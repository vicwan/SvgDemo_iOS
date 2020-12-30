/*
//
 http://www.w3.org/TR/SVG/pservers.html#InterfaceSVGGradientElement
 
 interface ZG_SVGGradientElement : ZG_SVGElement,

 SVGURIReference,
 SVGExternalResourcesRequired,
 SVGStylable,
 SVGUnitTypes {
 
 // Spread Method Types
 const unsigned short SVG_SPREADMETHOD_UNKNOWN = 0;
 const unsigned short SVG_SPREADMETHOD_PAD = 1;
 const unsigned short SVG_SPREADMETHOD_REFLECT = 2;
 const unsigned short SVG_SPREADMETHOD_REPEAT = 3;
 
 readonly attribute SVGAnimatedEnumeration gradientUnits;
 readonly attribute SVGAnimatedTransformList gradientTransform;
 readonly attribute SVGAnimatedEnumeration spreadMethod;
 
 */

#import "ZG_SVGElement.h"
#import "ZG_SVGRect.h"
#import "ZG_SVGGradientStop.h"
#import "ZG_SVGTransformable.h"
#import "ZG_SVGPreserveAspectRatio.h"
#import "ZG_SVGUnitTypes.h"

typedef NS_ENUM(NSUInteger, ZG_SVGSpreadMethod) {
    ZG_SVGSpreadMethodUnkown = 0,
    ZG_SVGSpreadMethodPad = 1,
    ZG_SVGSpreadMethodReflect = 2,
    ZG_SVGSpreadMethodRepeat = 3
};

@class ZG_SVGGradientLayer;
@interface ZG_SVGGradientElement : ZG_SVGElement <ZG_SVGTransformable> /* NB: does NOT implemente "SVGLayeredElement" because spec says that these specifically NEVER appear in the output */

@property (readonly, strong) NSArray *stops; /* FIXME: not in SVG Spec */
@property (readonly, strong) NSArray *locations; /* FIXME: not in SVG Spec */
@property (readonly, strong) NSArray *colors; /* FIXME: not in SVG Spec */

@property (readonly, assign) ZG_SVG_UNIT_TYPE gradientUnits;
@property (readonly, assign) ZG_SVGSpreadMethod spreadMethod; /* FIXME: currently only support `pad`. other methods are not supported */


-(void)addStop:(ZG_SVGGradientStop *)gradientStop; /* FIXME: not in SVG Spec */

-(NSString*) getAttributeInheritedIfNil:(NSString*)attrName;
-(ZG_SVGGradientLayer *)newGradientLayerForObjectRect:(CGRect)objectRect
                                      viewportRect:(ZG_SVGRect)viewportRect
                                         transform:(CGAffineTransform)transform;

- (void)synthesizeProperties; // resolve any xlink:hrefs to other gradients
@end
