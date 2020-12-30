/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSValue
 
 interface ZG_CSSValue {
 
 // UnitTypes
 const unsigned short      CSS_INHERIT                    = 0;
 const unsigned short      CSS_PRIMITIVE_VALUE            = 1;
 const unsigned short      CSS_VALUE_LIST                 = 2;
 const unsigned short      CSS_CUSTOM                     = 3;
 
 attribute DOMString        cssText;
 // raises(DOMException) on setting
 
 readonly attribute unsigned short   cssValueType;
 */
#import <Foundation/Foundation.h>

typedef enum ZG_CSSUnitType
{
    ZG_CSS_INHERIT                    = 0,
    ZG_CSS_PRIMITIVE_VALUE            = 1,
    ZG_CSS_VALUE_LIST                 = 2,
    ZG_CSS_CUSTOM                     = 3
} ZG_CSSUnitType;

@interface ZG_CSSValue : NSObject
{
	NSString* _cssText; // for subclasses to manually set
}

@property(nonatomic,strong) NSString* cssText;
@property(nonatomic) ZG_CSSUnitType cssValueType;

@end
