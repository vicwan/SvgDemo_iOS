#import "ZG_SVGKLayeredImageView.h"

#import <QuartzCore/QuartzCore.h>

#import "ZG_SVGKSourceString.h"
#import "ZG_SVGKInlineResource.h"

#import "ZG_SVGKDefine_Private.h"

@interface ZG_SVGKLayeredImageView()
@property(nonatomic,strong) CAShapeLayer* internalBorderLayer;
@end

@implementation ZG_SVGKLayeredImageView
@synthesize internalBorderLayer = _internalBorderLayer;

/** uses the custom ZG_SVGKLayer instead of a default CALayer */
+(Class)layerClass
{
	return NSClassFromString(@"ZG_SVGKLayer");
}

- (id)init
{
	NSAssert(false, @"init not supported, use initWithSVGKImage:");
    
    return nil;
}

- (id)initWithCoder:(NSCoder *)aDecoder
{
    if( aDecoder == nil )
	{
		self = [super initWithFrame:CGRectMake(0,0,100,100)]; // coincides with the inline SVG in populateFromImage!
	}
	else
	{
		self = [super initWithCoder:aDecoder];
	}
    if( self )
    {
        [self populateFromImage:nil];
    }
	return self;
}

-(id)initWithFrame:(CGRect)frame
{
	self = [super initWithFrame:frame];
	if( self )
	{
        [self populateFromImage:nil];
	}
	return self;
}

- (id)initWithSVGKImage:(ZG_SVGKImage*) im
{
	if( im == nil )
	{
		self = [super initWithFrame:CGRectMake(0,0,100,100)]; // coincides with the inline SVG in populateFromImage!
	}
	else
	{
		self = [super initWithFrame:CGRectMake( 0,0, im.CALayerTree.frame.size.width, im.CALayerTree.frame.size.height )]; // default: 0,0 to width x height of original image];
	}
    
    if (self)
    {
        [self populateFromImage:im];
    }
    return self;
}

- (void)populateFromImage:(ZG_SVGKImage*) im
{
#if SVGKIT_MAC
    // setup layer-hosting view
    self.layer = [[ZG_SVGKLayer alloc] init];
    self.wantsLayer = YES;
#endif
	if( im == nil )
	{
#ifndef SVGK_DONT_USE_EMPTY_IMAGE_PLACEHOLDER
        SVGKitLogWarn(@"[%@] WARNING: you have initialized an [%@] with a blank image (nil). Possibly because you're using Storyboards or NIBs which Apple won't allow us to decorate. Make sure you assign an ZG_SVGKImage to the .image property!", [self class], [self class]);
#if SVGKIT_UIKIT
		self.backgroundColor = [UIColor clearColor];
#else
        self.layer.backgroundColor = [NSColor clearColor].CGColor;
#endif
        
        NSString* svgStringDefaultContents = ZG_SVGKGetDefaultContentString();
        
		SVGKitLogInfo(@"About to make a blank image using the inlined SVG = %@", svgStringDefaultContents);
		
		ZG_SVGKImage* defaultBlankImage = [ZG_SVGKImage imageWithSource:[ZG_SVGKSourceString sourceFromContentsOfString:svgStringDefaultContents]];
		
		((ZG_SVGKLayer*) self.layer).SVGImage = defaultBlankImage;
#endif
	}
	else
	{
#if SVGKIT_UIKIT
		self.backgroundColor = [UIColor clearColor];
#else
        self.layer.backgroundColor = [NSColor clearColor].CGColor;
#endif
		
		((ZG_SVGKLayer*) self.layer).SVGImage = im;
	}
}

/** Delegate the call to the internal layer that's coded to handle this stuff automatically */
-(ZG_SVGKImage *)image
{
	return ((ZG_SVGKLayer*)self.layer).SVGImage;
}
/** Delegate the call to the internal layer that's coded to handle this stuff automatically */
-(void)setImage:(ZG_SVGKImage *)image
{
	((ZG_SVGKLayer*)self.layer).SVGImage = image;
}

/** Delegate the call to the internal layer that's coded to handle this stuff automatically */
-(BOOL)showBorder
{
	return ((ZG_SVGKLayer*)self.layer).showBorder;
}
/** Delegate the call to the internal layer that's coded to handle this stuff automatically */
-(void)setShowBorder:(BOOL)showBorder
{
	((ZG_SVGKLayer*)self.layer).showBorder = showBorder;
}

-(NSTimeInterval)timeIntervalForLastReRenderOfSVGFromMemory
{
	return[((ZG_SVGKLayer*)self.layer).endRenderTime timeIntervalSinceDate:((ZG_SVGKLayer*)self.layer).startRenderTime];
}

@end
