/*!
 ZG_SVGAngle
 
 http://www.w3.org/TR/SVG/types.html#InterfaceSVGAngle
 
 // Angle Unit Types
 const unsigned short SVG_ANGLETYPE_UNKNOWN = 0;
 const unsigned short SVG_ANGLETYPE_UNSPECIFIED = 1;
 const unsigned short SVG_ANGLETYPE_DEG = 2;
 const unsigned short SVG_ANGLETYPE_RAD = 3;
 const unsigned short SVG_ANGLETYPE_GRAD = 4;
 
 readonly attribute unsigned short unitType;
 attribute float value setraises(DOMException);
 attribute float valueInSpecifiedUnits setraises(DOMException);
 attribute DOMString valueAsString setraises(DOMException);
 
 void newValueSpecifiedUnits(in unsigned short unitType, in float valueInSpecifiedUnits) raises(DOMException);
 void convertToSpecifiedUnits(in unsigned short unitType) raises(DOMException);
 */
#import <Foundation/Foundation.h>

@interface ZG_SVGAngle : NSObject

/*! Angle Unit Types */
typedef enum ZG_SVGKAngleType
{
    ZG_SVG_ANGLETYPE_UNKNOWN = 0,
    ZG_SVG_ANGLETYPE_UNSPECIFIED = 1,
    ZG_SVG_ANGLETYPE_DEG = 2,
    ZG_SVG_ANGLETYPE_RAD = 3,
    ZG_SVG_ANGLETYPE_GRAD = 4
} ZG_SVGKAngleType;

@property(nonatomic, readonly) ZG_SVGKAngleType unitType;
@property(nonatomic) float value;
@property(nonatomic) float valueInSpecifiedUnits;
@property(nonatomic,strong) NSString* valueAsString;

-(void) newValueSpecifiedUnits:(ZG_SVGKAngleType) unitType valueInSpecifiedUnits:(float) valueInSpecifiedUnits;
-(void) convertToSpecifiedUnits:(ZG_SVGKAngleType) unitType;
@end
