/*!
 SVGViewSpec
 
 interface SVGViewSpec : SVGZoomAndPan,
 SVGFitToViewBox {
 readonly attribute SVGTransformList transform;
 readonly attribute ZG_SVGElement viewTarget;
 readonly attribute DOMString viewBoxString;
 readonly attribute DOMString preserveAspectRatioString;
 readonly attribute DOMString transformString;
 readonly attribute DOMString viewTargetString;
 };
 */
#import <Foundation/Foundation.h>

@class ZG_SVGElement;
#import "ZG_SVGElement.h"

@interface ZG_SVGViewSpec : NSObject

/* FIXME: SVGTransformList not implemented yet: @property(nonatomic,readonly) SVGTransformList transform; */
@property(nonatomic,readonly) ZG_SVGElement* viewTarget;
@property(nonatomic,readonly) NSString* viewBoxString;
@property(nonatomic,readonly) NSString* preserveAspectRatioString;
@property(nonatomic,readonly) NSString* transformString;
@property(nonatomic,readonly) NSString* viewTargetString;

@end
