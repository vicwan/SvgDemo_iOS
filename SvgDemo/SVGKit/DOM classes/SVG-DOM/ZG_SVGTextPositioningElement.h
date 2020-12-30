/**
 http://www.w3.org/TR/2011/REC-SVG11-20110816/text.html#InterfaceSVGTextPositioningElement
 
 interface ZG_SVGTextPositioningElement : ZG_SVGTextContentElement {
 readonly attribute SVGAnimatedLengthList x;
 readonly attribute SVGAnimatedLengthList y;
 readonly attribute SVGAnimatedLengthList dx;
 readonly attribute SVGAnimatedLengthList dy;
 readonly attribute SVGAnimatedNumberList rotate;
 */

#import "ZG_SVGTextContentElement.h"
#import "ZG_SVGLength.h"

@interface ZG_SVGTextPositioningElement : ZG_SVGTextContentElement

@property(nonatomic,strong,readonly) ZG_SVGLength* /* FIXME: should be SVGAnimatedLengthList */ x;
@property(nonatomic,strong,readonly) ZG_SVGLength* /* FIXME: should be SVGAnimatedLengthList */ y;
@property(nonatomic,strong,readonly) ZG_SVGLength* /* FIXME: should be SVGAnimatedLengthList */ dx;
@property(nonatomic,strong,readonly) ZG_SVGLength* /* FIXME: should be SVGAnimatedLengthList */ dy;
@property(nonatomic,strong,readonly) ZG_SVGLength* /* FIXME: should be SVGAnimatedLengthList */ rotate;

@end
