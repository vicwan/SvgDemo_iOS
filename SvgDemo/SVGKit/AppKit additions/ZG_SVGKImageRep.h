//
//  SVGKitImageRep.h
//  ZG_SVGKit
//
//  Created by C.W. Betts on 12/5/12.
//
//

#import "ZG_SVGKDefine.h"

#if SVGKIT_MAC
#import <Cocoa/Cocoa.h>
@class ZG_SVGKImage;
@class ZG_SVGKSource;

@interface ZG_SVGKImageRep : NSImageRep
@property (nonatomic, strong, readonly) ZG_SVGKImage *image;

//Function used by NSImageRep to init.
+ (instancetype)imageRepWithData:(NSData *)d;
+ (instancetype)imageRepWithContentsOfFile:(NSString *)filename;
+ (instancetype)imageRepWithContentsOfURL:(NSURL *)url;
+ (instancetype)imageRepWithSVGImage:(ZG_SVGKImage*)theImage;
+ (instancetype)imageRepWithSVGSource:(ZG_SVGKSource*)theSource;

- (instancetype)initWithData:(NSData *)theData;
- (instancetype)initWithContentsOfURL:(NSURL *)theURL;
- (instancetype)initWithContentsOfFile:(NSString *)thePath;
- (instancetype)initWithSVGString:(NSString *)theString;
- (instancetype)initWithSVGImage:(ZG_SVGKImage*)theImage;
- (instancetype)initWithSVGSource:(ZG_SVGKSource*)theSource;

- (NSData *)TIFFRepresentation;
- (NSData *)TIFFRepresentationWithSize:(NSSize)theSize;
- (NSData *)TIFFRepresentationUsingCompression:(NSTIFFCompression)comp factor:(float)factor;
- (NSData *)TIFFRepresentationUsingCompression:(NSTIFFCompression)comp factor:(float)factor size:(NSSize)asize;

+ (void)loadSVGKImageRep;
+ (void)unloadSVGKImageRep;

@end

#endif /* SVGKIT_MAC */
