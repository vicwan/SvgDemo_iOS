/**
http://www.w3.org/TR/SVG/masking.html#InterfaceSVGClipPathElement
 
 interface ZG_SVGClipPathElement : ZG_SVGElement,
 SVGTests,
 SVGLangSpace,
 SVGExternalResourcesRequired,
 SVGStylable,
 SVGTransformable,
 SVGUnitTypes {
 */

#import "ZG_SVGElement.h"
#import "ZG_SVGElement_ForParser.h"

#import "ZG_ConverterSVGToCALayer.h"
#import "ZG_SVGTransformable.h"
#import "ZG_SVGUnitTypes.h"


// Does NOT implement ConverterSVGToCALayer because <clipPath> elements are never rendered directly; they're only referenced via clip-path attributes in other elements
@interface ZG_SVGClipPathElement : ZG_SVGElement <ZG_SVGTransformable, ZG_SVGStylable>

@property(nonatomic, readonly) ZG_SVG_UNIT_TYPE clipPathUnits;

- (CALayer *) newLayer;
- (void)layoutLayer:(CALayer *)layer toMaskLayer:(CALayer *)maskThis;

@end
