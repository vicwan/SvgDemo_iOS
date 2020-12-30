//
//  SVGKitImageRep.m
//  ZG_SVGKit
//
//  Created by C.W. Betts on 12/5/12.
//
//

#import "ZG_SVGKit.h"

#if SVGKIT_MAC
#import "ZG_SVGKSourceNSData.h"
#import "ZG_SVGKSourceLocalFile.h"
#import "ZG_SVGKSourceURL.h"
#import "ZG_SVGKSourceString.h"
#import "ZG_SVGKImageRep.h"
#import "ZG_SVGKImage+CGContext.h"
#include <tgmath.h>

@interface ZG_SVGKImageRep ()
@property (nonatomic, strong, readwrite, setter = setTheSVG:) ZG_SVGKImage *image;
@property (nonatomic, assign) BOOL antiAlias;
@property (nonatomic, assign) CGFloat curveFlatness;
@property (nonatomic, assign) CGInterpolationQuality interpolationQuality;
@end

@implementation ZG_SVGKImageRep

- (NSData *)TIFFRepresentationWithSize:(NSSize)theSize
{
	self.image.size = theSize;
    NSImageRep *imageRep = self.image.NSImage.representations.firstObject;
    if (![imageRep isKindOfClass:[NSBitmapImageRep class]]) {
        return nil;
    }
	return [(NSBitmapImageRep *)imageRep TIFFRepresentation];
}

- (NSData *)TIFFRepresentation
{
	return [self TIFFRepresentationWithSize:self.size];
}

- (NSData *)TIFFRepresentationUsingCompression:(NSTIFFCompression)comp factor:(float)factor
{
	return [self TIFFRepresentationUsingCompression:comp factor:factor size:self.size];
}

- (NSData *)TIFFRepresentationUsingCompression:(NSTIFFCompression)comp factor:(float)factor size:(NSSize)asize
{
	self.image.size = asize;
    NSImageRep *imageRep = self.image.NSImage.representations.firstObject;
    if (![imageRep isKindOfClass:[NSBitmapImageRep class]]) {
        return nil;
    }
    return [(NSBitmapImageRep *)imageRep TIFFRepresentation];
}

+ (NSArray<NSString *> *)imageUnfilteredTypes {
    static NSArray *UTItypes;
    if (UTItypes == nil) {
        UTItypes = @[@"public.svg-image"];
    }
    return UTItypes;
}

+ (BOOL)canInitWithData:(NSData *)d
{
	ZG_SVGKParseResult *parseResult;
	@autoreleasepool {
		parseResult = [ZG_SVGKParser parseSourceUsingDefaultSVGKParser:[ZG_SVGKSourceNSData sourceFromData:d URLForRelativeLinks:nil]];
	}
	if (parseResult == nil) {
		return NO;
	}
	if (!parseResult.parsedDocument) {
		return NO;
	}
	return YES;
}

+ (instancetype)imageRepWithData:(NSData *)d
{
	return [[self alloc] initWithData:d];
}

+ (instancetype)imageRepWithContentsOfFile:(NSString *)filename
{
	return [[self alloc] initWithContentsOfFile:filename];
}

+ (instancetype)imageRepWithContentsOfURL:(NSURL *)url
{
	return [[self alloc] initWithContentsOfURL:url];
}

+ (instancetype)imageRepWithSVGSource:(ZG_SVGKSource*)theSource
{
	return [[self alloc] initWithSVGSource:theSource];
}

+ (instancetype)imageRepWithSVGImage:(ZG_SVGKImage*)theImage
{
	return [[self alloc] initWithSVGImage:theImage];
}

+ (void)load
{
	[self loadSVGKImageRep];
}

- (instancetype)initWithData:(NSData *)theData
{
	return [self initWithSVGImage:[[ZG_SVGKImage alloc] initWithData:theData] copy:NO];
}

- (instancetype)initWithContentsOfURL:(NSURL *)theURL
{
	return [self initWithSVGImage:[ZG_SVGKImage imageWithContentsOfURL:theURL] copy:NO];
}

- (instancetype)initWithContentsOfFile:(NSString *)thePath
{
	return [self initWithSVGImage:[[ZG_SVGKImage alloc] initWithContentsOfFile:thePath] copy:NO];
}

- (instancetype)initWithSVGString:(NSString *)theString
{
    return [self initWithSVGSource:[ZG_SVGKSourceString sourceFromContentsOfString:theString]];
}

- (instancetype)initWithSVGSource:(ZG_SVGKSource*)theSource
{
	return [self initWithSVGImage:[[ZG_SVGKImage alloc] initWithSource:theSource] copy:NO];
}

- (instancetype)initWithSVGImage:(ZG_SVGKImage*)theImage copy:(BOOL)copyImage
{
	if (self = [super init]) {
		if (theImage == nil) {
			return nil;
		}
		ZG_SVGKImage *tmpImage;
		if (copyImage) {
			tmpImage = [theImage copy];
			if (tmpImage) {
				theImage = tmpImage;
			}
		}
		
		self.image = theImage;
		
		if (![self.image hasSize]) {
			self.image.size = CGSizeMake(32, 32);
		}
		
        self.colorSpaceName = NSCalibratedRGBColorSpace;
        self.alpha = YES;
        self.opaque = NO;
		[self setSize:self.image.size sizeImage:NO];
		self.interpolationQuality = kCGInterpolationDefault;
		self.antiAlias = YES;
		self.curveFlatness = 1.0;
        
        // Setting these to zero will tell NSImage that this image is resolution-independant.
        self.pixelsHigh = 0;
        self.pixelsWide = 0;
        self.bitsPerSample = 0;
	}
	return self;
}

- (instancetype)init
{
    NSAssert(NO, @"init not supported, use initWithData:");
    
    return nil;
}

- (void)setSize:(NSSize)aSize
{
	[self setSize:aSize sizeImage:YES];
}

- (void)setSize:(NSSize)aSize sizeImage:(BOOL)theSize
{
    [super setSize:aSize];
    if (theSize) {
        self.image.size = aSize;
    }
}

+ (void)loadSVGKImageRep
{
	[NSImageRep registerImageRepClass:[ZG_SVGKImageRep class]];
}

+ (void)unloadSVGKImageRep
{
	[NSImageRep unregisterImageRepClass:[ZG_SVGKImageRep class]];
}

- (instancetype)initWithSVGImage:(ZG_SVGKImage*)theImage
{
	//Copy over the image, just in case
	return [self initWithSVGImage:theImage copy:YES];
}

- (BOOL)drawInRect:(NSRect)rect
{
	NSSize scaledSize = rect.size;
	if (!CGSizeEqualToSize(self.image.size, scaledSize)) {
		//For when we're at the full size.
		if (CGSizeEqualToSize(self.size, scaledSize)) {
			return [super drawInRect:rect];
		} else {
			[self.image scaleToFitInside:scaledSize];
		}
	} else if (CGSizeEqualToSize(self.size, scaledSize) &&
			   CGSizeEqualToSize(self.image.size, self.size)) {
		return [super drawInRect:rect];
	}

	CGContextRef imRepCtx = [[NSGraphicsContext currentContext] graphicsPort];
	CGLayerRef layerRef = CGLayerCreateWithContext(imRepCtx, rect.size, NULL);
	if (!layerRef) {
		return NO;
	}

	CGContextRef layerCont = CGLayerGetContext(layerRef);
	CGContextSaveGState(layerCont);
    [self.image renderToContext:layerCont antiAliased:_antiAlias curveFlatnessFactor:_curveFlatness interpolationQuality:_interpolationQuality flipYaxis:YES];
	CGContextRestoreGState(layerCont);

	CGContextDrawLayerInRect(imRepCtx, rect, layerRef);
	CGLayerRelease(layerRef);
	
	return YES;
}

- (BOOL)draw
{
	//Just in case someone resized the image rep.
	NSSize scaledSize = self.size;
	if (!CGSizeEqualToSize(self.image.size, scaledSize)) {
		self.image.size = scaledSize;
	}

	CGContextRef imRepCtx = [[NSGraphicsContext currentContext] graphicsPort];
	CGLayerRef layerRef = CGLayerCreateWithContext(imRepCtx, scaledSize, NULL);
	if (!layerRef) {
		return NO;
	}

	CGContextRef layerCont = CGLayerGetContext(layerRef);
	CGContextSaveGState(layerCont);
    [self.image renderToContext:layerCont antiAliased:_antiAlias curveFlatnessFactor:_curveFlatness interpolationQuality:_interpolationQuality flipYaxis:YES];
	CGContextRestoreGState(layerCont);

	CGContextDrawLayerAtPoint(imRepCtx, CGPointZero, layerRef);
	CGLayerRelease(layerRef);
	
	return YES;
}

#pragma mark - Inherited protocols

#pragma mark NSCopying

- (id)copyWithZone:(NSZone *)zone
{
    ZG_SVGKImageRep *toRet = [[ZG_SVGKImageRep alloc] initWithSVGImage:self.image];
    
    return toRet;
}

#pragma mark NSCoding
- (instancetype)initWithCoder:(NSCoder *)coder
{
    if (self = [super initWithCoder:coder]) {
        
    }
    return self;
}

- (void)encodeWithCoder:(NSCoder *)aCoder
{
    [super encodeWithCoder:aCoder];
}

@end

#endif /* SVGKIT_MAC */
