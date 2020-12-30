/*
 http://www.w3.org/TR/SVG/struct.html#InterfaceSVGUseElement
 
 interface ZG_SVGUseElement : ZG_SVGElement,
 SVGURIReference,
 SVGTests,
 SVGLangSpace,
 SVGExternalResourcesRequired,
 SVGStylable,
 SVGTransformable {
 readonly attribute SVGAnimatedLength x;
 readonly attribute SVGAnimatedLength y;
 readonly attribute SVGAnimatedLength width;
 readonly attribute SVGAnimatedLength height;
 readonly attribute ZG_SVGElementInstance instanceRoot;
 readonly attribute ZG_SVGElementInstance animatedInstanceRoot;
 };
 
 */
#import "ZG_SVGLength.h"
#import "ZG_SVGElement.h"

@class ZG_SVGElementInstance;
#import "ZG_SVGElementInstance.h"

#import "ZG_ConverterSVGToCALayer.h"
#import "ZG_SVGTransformable.h"

@interface ZG_SVGUseElement : ZG_SVGElement < ZG_SVGTransformable /*FIXME: delete this rubbish:*/, ZG_ConverterSVGToCALayer>

@property(nonatomic, strong, readonly) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* x;
@property(nonatomic, strong, readonly) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* y;
@property(nonatomic, strong, readonly) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* width;
@property(nonatomic, strong, readonly) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* height;
@property(nonatomic, strong, readonly) ZG_SVGElementInstance* instanceRoot;
@property(nonatomic, strong, readonly) ZG_SVGElementInstance* animatedInstanceRoot;

@end
