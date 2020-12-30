/**
 This class is FOR IMPLEMENTATION ONLY, it is NOT part of the SVG Spec.
 
 All the SVG Basic Shapes are rendered in ObjectiveC using the same CGPath primitive - so this class provides
 a clean, OOP, way of implementing that.
 
 Sub-classes MUST write to the "pathForShapeInRelativeCoords" property, and this superclass will automatically generate
 the required CALayer on the fly, using that CGPath
 */

#import "ZG_SVGElement.h"
#import "ZG_ConverterSVGToCALayer.h"
#import "ZG_SVGUtils.h"
#import "ZG_SVGTransformable.h"

@class ZG_SVGGradientElement;
@class ZG_SVGKPattern;

@interface ZG_BaseClassForAllSVGBasicShapes : ZG_SVGElement < ZG_SVGStylable, ZG_SVGTransformable, ZG_ConverterSVGToCALayer >
{
	/* FIXME: are any of these private elements in the SVG spec? */
	NSString *_styleClass;
	CGRect _layerRect;
}

/** The actual path as parsed from the original file. THIS MIGHT NOT BE NORMALISED (TODO: perhaps an extra feature?) */
@property (nonatomic, readonly) CGPathRef pathForShapeInRelativeCoords;

@end
