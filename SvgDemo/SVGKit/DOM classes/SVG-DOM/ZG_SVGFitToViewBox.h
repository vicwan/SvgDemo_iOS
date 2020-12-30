/**
 * http://www.w3.org/TR/SVG/types.html#InterfaceSVGFitToViewBox
 
 interface SVGFitToViewBox {
 readonly attribute SVGAnimatedRect viewBox;
 readonly attribute ZG_SVGAnimatedPreserveAspectRatio preserveAspectRatio;
 */

#import <Foundation/Foundation.h>

#import <QuartzCore/QuartzCore.h>

#import "ZG_SVGRect.h"
#import "ZG_SVGAnimatedPreserveAspectRatio.h"

@protocol ZG_SVGFitToViewBox <NSObject>

@property (nonatomic) /* SVGAnimatedRect */ ZG_SVGRect viewBox;

@property(nonatomic,retain) ZG_SVGAnimatedPreserveAspectRatio* preserveAspectRatio;

@end
