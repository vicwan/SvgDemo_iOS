/**
 http://www.w3.org/TR/SVG/coords.html#InterfaceSVGAnimatedPreserveAspectRatio
 
 readonly attribute ZG_SVGPreserveAspectRatio baseVal;
 readonly attribute ZG_SVGPreserveAspectRatio animVal;
 */
#import <Foundation/Foundation.h>
#import "ZG_SVGPreserveAspectRatio.h"

@interface ZG_SVGAnimatedPreserveAspectRatio : NSObject

@property(nonatomic,strong) ZG_SVGPreserveAspectRatio* baseVal;
@property(nonatomic,strong, readonly) ZG_SVGPreserveAspectRatio* animVal;

@end
