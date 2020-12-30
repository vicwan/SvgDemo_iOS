/**
 http://www.w3.org/TR/SVG/shapes.html#InterfaceSVGRectElement
 
 interface ZG_SVGRectElement : ZG_SVGElement,
 SVGTests,
 SVGLangSpace,
 SVGExternalResourcesRequired,
 SVGStylable,
 SVGTransformable {
 readonly attribute SVGAnimatedLength x;
 readonly attribute SVGAnimatedLength y;
 readonly attribute SVGAnimatedLength width;
 readonly attribute SVGAnimatedLength height;
 readonly attribute SVGAnimatedLength rx;
 readonly attribute SVGAnimatedLength ry;
 */
#import "ZG_BaseClassForAllSVGBasicShapes.h"
#import "ZG_BaseClassForAllSVGBasicShapes_ForSubclasses.h"
#import "ZG_SVGLength.h"
#import "ZG_SVGTransformable.h"

@interface ZG_SVGRectElement : ZG_BaseClassForAllSVGBasicShapes <ZG_SVGStylable, ZG_SVGTransformable>
{ }

@property (nonatomic, strong, readonly) ZG_SVGLength* x;
@property (nonatomic, strong, readonly) ZG_SVGLength* y;
@property (nonatomic, strong, readonly) ZG_SVGLength* width;
@property (nonatomic, strong, readonly) ZG_SVGLength* height;

@property (nonatomic, strong, readonly) ZG_SVGLength* rx;
@property (nonatomic, strong, readonly) ZG_SVGLength* ry;

#pragma mark - Properties not in spec but are needed by ObjectiveC implementation to maintain

@end
