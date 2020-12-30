#import <Foundation/Foundation.h>

#import "ZG_SVGTextPositioningElement.h"
#import "ZG_ConverterSVGToCALayer.h"
#import "ZG_SVGTransformable.h"

/**
 http://www.w3.org/TR/2011/REC-SVG11-20110816/text.html#TextElement
 
 interface ZG_SVGTextElement : ZG_SVGTextPositioningElement, SVGTransformable
 */
@interface ZG_SVGTextElement : ZG_SVGTextPositioningElement <ZG_SVGTransformable, ZG_ConverterSVGToCALayer>

@end
