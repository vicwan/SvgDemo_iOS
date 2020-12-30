#import "ZG_SVGKLayer.h"

@implementation ZG_SVGKLayer
{

}

@synthesize SVGImage = _SVGImage;
@synthesize showBorder = _showBorder;

/** Apple requires this to be implemented by CALayer subclasses */
+ (id)layer
{
	ZG_SVGKLayer* layer = [[ZG_SVGKLayer alloc] init];
	return layer;
}

- (id)init
{
    self = [super init];
    if (self)
	{
    	self.borderColor = [UIColor blackColor].CGColor;
    }
    return self;
}
- (void)setSVGImage:(ZG_SVGKImage *)newImage
{
	if( newImage == _SVGImage )
		return;
	
	self.startRenderTime = self.endRenderTime = nil; // set to nil, so that watchers know it hasn't loaded yet
	
	/** 1: remove old */
	if( _SVGImage != nil )
	{
		[_SVGImage.CALayerTree removeFromSuperlayer];
	}
	
	/** 2: update pointer */
	_SVGImage = newImage;
	
	/** 3: add new */
	if( _SVGImage != nil )
	{
		self.startRenderTime = [NSDate date];
		[self addSublayer:_SVGImage.CALayerTree];
		self.endRenderTime = [NSDate date];
	}
}

- (void)setShowBorder:(BOOL)shouldShow
{
    _showBorder = shouldShow;
    self.borderWidth = shouldShow ? 1.0f : 0.0f;
    [self setNeedsDisplay];
}

- (void)dealloc
{
	self.SVGImage = nil;
}

@end
