/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSPrimitiveValue
 
 interface ZG_CSSPrimitiveValue : ZG_CSSValue {
 
 // UnitTypes
 const unsigned short      CSS_UNKNOWN                    = 0;
 const unsigned short      CSS_NUMBER                     = 1;
 const unsigned short      CSS_PERCENTAGE                 = 2;
 const unsigned short      CSS_EMS                        = 3;
 const unsigned short      CSS_EXS                        = 4;
 const unsigned short      CSS_PX                         = 5;
 const unsigned short      CSS_CM                         = 6;
 const unsigned short      CSS_MM                         = 7;
 const unsigned short      CSS_IN                         = 8;
 const unsigned short      CSS_PT                         = 9;
 const unsigned short      CSS_PC                         = 10;
 const unsigned short      CSS_DEG                        = 11;
 const unsigned short      CSS_RAD                        = 12;
 const unsigned short      CSS_GRAD                       = 13;
 const unsigned short      CSS_MS                         = 14;
 const unsigned short      CSS_S                          = 15;
 const unsigned short      CSS_HZ                         = 16;
 const unsigned short      CSS_KHZ                        = 17;
 const unsigned short      CSS_DIMENSION                  = 18;
 const unsigned short      CSS_STRING                     = 19;
 const unsigned short      CSS_URI                        = 20;
 const unsigned short      CSS_IDENT                      = 21;
 const unsigned short      CSS_ATTR                       = 22;
 const unsigned short      CSS_COUNTER                    = 23;
 const unsigned short      CSS_RECT                       = 24;
 const unsigned short      CSS_RGBCOLOR                   = 25;
 
 readonly attribute unsigned short   primitiveType;
 void               setFloatValue(in unsigned short unitType,
 in float floatValue)
 raises(DOMException);
 float              getFloatValue(in unsigned short unitType)
 raises(DOMException);
 void               setStringValue(in unsigned short stringType,
 in DOMString stringValue)
 raises(DOMException);
 DOMString          getStringValue()
 raises(DOMException);
 Counter            getCounterValue()
 raises(DOMException);
 Rect               getRectValue()
 raises(DOMException);
 RGBColor           getRGBColorValue()
 raises(DOMException);
 */
#import "ZG_CSSValue.h"

typedef enum ZG_CSSPrimitiveType
{
	ZG_CSS_UNKNOWN                    = 0,
	ZG_CSS_NUMBER                     = 1,
	ZG_CSS_PERCENTAGE                 = 2,
	ZG_CSS_EMS                        = 3,
	ZG_CSS_EXS                        = 4,
	ZG_CSS_PX                         = 5,
	ZG_CSS_CM                         = 6,
	ZG_CSS_MM                         = 7,
	ZG_CSS_IN                         = 8,
	ZG_CSS_PT                         = 9,
	ZG_CSS_PC                         = 10,
	ZG_CSS_DEG                        = 11,
	ZG_CSS_RAD                        = 12,
	ZG_CSS_GRAD                       = 13,
	ZG_CSS_MS                         = 14,
	ZG_CSS_S                          = 15,
	ZG_CSS_HZ                         = 16,
	ZG_CSS_KHZ                        = 17,
	ZG_CSS_DIMENSION                  = 18,
	ZG_CSS_STRING                     = 19,
	ZG_CSS_URI                        = 20,
	ZG_CSS_IDENT                      = 21,
	ZG_CSS_ATTR                       = 22,
	ZG_CSS_COUNTER                    = 23,
	ZG_CSS_RECT                       = 24,
	ZG_CSS_RGBCOLOR                   = 25
} ZG_CSSPrimitiveType;

@interface ZG_CSSPrimitiveValue : ZG_CSSValue

@property(nonatomic) ZG_CSSPrimitiveType primitiveType;

-(void) setFloatValue:(ZG_CSSPrimitiveType) unitType floatValue:(float) floatValue;

-(float) getFloatValue:(ZG_CSSPrimitiveType) unitType;

-(void) setStringValue:(ZG_CSSPrimitiveType) stringType stringValue:(NSString*) stringValue;

-(NSString*) getStringValue;

-(/* FIXME: have to add this type: Counter*/ void) getCounterValue;

-(/* FIXME: have to add this type: Rect*/ void) getRectValue;

-(/* FIXME: have to add this type: RGBColor*/ void) getRGBColorValue;

@end
