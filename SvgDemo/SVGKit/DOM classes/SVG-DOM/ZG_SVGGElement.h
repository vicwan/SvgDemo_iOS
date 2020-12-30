/**
 http://www.w3.org/TR/SVG/struct.html#InterfaceSVGGElement
 
 interface ZG_SVGGElement : ZG_SVGElement,
 SVGTests,
 SVGLangSpace,
 SVGExternalResourcesRequired,
 SVGStylable,
 SVGTransformable {
 */

#import "ZG_SVGElement.h"
#import "ZG_SVGElement_ForParser.h"

#import "ZG_ConverterSVGToCALayer.h"
#import "ZG_SVGTransformable.h"


@interface ZG_SVGGElement : ZG_SVGElement <ZG_SVGTransformable, ZG_SVGStylable, ZG_ConverterSVGToCALayer >

@end
