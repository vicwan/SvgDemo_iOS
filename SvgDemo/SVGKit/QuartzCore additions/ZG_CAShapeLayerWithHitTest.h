#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>
#import "ZG_CAShapeLayerWithClipRender.h"

/*!
 * Overrides Apple's CAShapeLayer purely to change one method, so that hit-testing
 * is done by checking whether the hit point lies:
 *
 *    "inside ANY part of the layer's CGPath"
 *
 * This is used exclusively by SVGShapeElement, but in theory works for any SVG*Element class that
 * uses CGPath to render itself.
 *
 * This is more useful than Apple's default implementation, but it might cause unexpected
 * problems in other code (not that I'm aware of any - this override appears to be a common
 * implementation, c.f. http://stackoverflow.com/questions/2944064/hit-testing-with-calayer-using-the-alpha-properties-of-the-calayer-contents
 *
 * TODO: should this layer be used in ZG_SVGEllipseElement, ZG_SVGPolygonElement, etc?
 */
@interface ZG_CAShapeLayerWithHitTest : ZG_CAShapeLayerWithClipRender {
    
}

@end
