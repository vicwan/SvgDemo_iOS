/*
 https://www.w3.org/TR/SVG/pservers.html#InterfaceSVGRadialGradientElement
 
 interface ZG_SVGRadialGradientElement : ZG_SVGGradientElement {
 [SameObject] readonly attribute SVGAnimatedLength cx;
 [SameObject] readonly attribute SVGAnimatedLength cy;
 [SameObject] readonly attribute SVGAnimatedLength r;
 [SameObject] readonly attribute SVGAnimatedLength fx;
 [SameObject] readonly attribute SVGAnimatedLength fy;
 [SameObject] readonly attribute SVGAnimatedLength fr;
 };
 */

#import "ZG_SVGGradientElement.h"

@interface ZG_SVGRadialGradientElement : ZG_SVGGradientElement

@property (nonatomic, readonly) ZG_SVGLength *cx;
@property (nonatomic, readonly) ZG_SVGLength *cy;
@property (nonatomic, readonly) ZG_SVGLength *r;
@property (nonatomic, readonly) ZG_SVGLength *fx;
@property (nonatomic, readonly) ZG_SVGLength *fy;
@property (nonatomic, readonly) ZG_SVGLength *fr;

@end
