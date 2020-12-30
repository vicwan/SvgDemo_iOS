/*
// https://www.w3.org/TR/SVG/pservers.html#InterfaceSVGLinearGradientElement
 
 interface ZG_SVGLinearGradientElement : ZG_SVGGradientElement {
 [SameObject] readonly attribute SVGAnimatedLength x1;
 [SameObject] readonly attribute SVGAnimatedLength y1;
 [SameObject] readonly attribute SVGAnimatedLength x2;
 [SameObject] readonly attribute SVGAnimatedLength y2;
 };
 
*/

#import "ZG_SVGGradientElement.h"

@interface ZG_SVGLinearGradientElement : ZG_SVGGradientElement

@property (nonatomic, readonly) ZG_SVGLength *x1;
@property (nonatomic, readonly) ZG_SVGLength *y1;
@property (nonatomic, readonly) ZG_SVGLength *x2;
@property (nonatomic, readonly) ZG_SVGLength *y2;

@end
