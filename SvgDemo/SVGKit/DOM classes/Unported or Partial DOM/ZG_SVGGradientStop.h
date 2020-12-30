/*
 http://www.w3.org/TR/SVG/pservers.html#InterfaceSVGStopElement
 
 interface SVGStopElement : ZG_SVGElement,
 SVGStylable {
 readonly attribute SVGAnimatedNumber offset;
 */

#import "ZG_SVGElement.h"
#import "ZG_SVGUtils.h"


@interface ZG_SVGGradientStop : ZG_SVGElement

@property (nonatomic, readonly)CGFloat offset; /** FIXME: wrong units */
@property (nonatomic, readonly)CGFloat stopOpacity; /** FIXME: not in SVG Spec */
@property (nonatomic, readonly)ZG_SVGColor stopColor; /** FIXME: not in SVG Spec */

//@property (nonatomic, readonly)NSDictionary *style; //misc unaccounted for properties

@end
