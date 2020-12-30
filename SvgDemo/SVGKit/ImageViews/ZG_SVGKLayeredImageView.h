#import "ZG_SVGKImageView.h"
#import "ZG_SVGKit.h"

/**
 * SVGKit's ADVANCED version of UIImageView - for most cases, you want to use the simple version instead (ZG_SVGKImageView)
 
 This class is similar to ZG_SVGKImageView, but it DOES NOT HAVE the performance optimizations, and it WILL NOT AUTO-DRAW AT FULL RESOLUTION.
 
 However, it DOES SUPPORT CORE ANIMATION (which ZG_SVGKImageView cannot do), and in some cases that's more important.
 
 Basic usage:
 - as per ZG_SVGKImageView:
 - ZG_SVGKLayeredImageView *skv = [[ZG_SVGKLayeredImageView alloc] initWithSVGKImage: [ZG_SVGKImage imageNamed:@"image.svg"]];
 - [self.view addSubview: skv];
 
 Advanced usage:
 - to access the underlying layers, typecast the .layer property:
   - ZG_SVGKLayeredImageView *skv = [[ZG_SVGKLayeredImageView alloc] initWithSVGKImage: [ZG_SVGKImage imageNamed:@"image.svg"]];
   - ZG_SVGKLayer* layer = (ZG_SVGKLayer*) skv.layer;
 
 For Mac user:
    `SVGKLayeredImageView` is a layer-hosting view. It uses the `SVGKLayer` layer class for rendering.
 
 */

@interface ZG_SVGKLayeredImageView : ZG_SVGKImageView

@end
