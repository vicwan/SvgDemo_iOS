/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSRule
 
 interface ZG_CSSRule {
 
 // RuleType
 const unsigned short      UNKNOWN_RULE                   = 0;
 const unsigned short      STYLE_RULE                     = 1;
 const unsigned short      CHARSET_RULE                   = 2;
 const unsigned short      IMPORT_RULE                    = 3;
 const unsigned short      MEDIA_RULE                     = 4;
 const unsigned short      FONT_FACE_RULE                 = 5;
 const unsigned short      PAGE_RULE                      = 6;
 
 readonly attribute unsigned short   type;
 attribute DOMString        cssText;
 // raises(DOMException) on setting
 
 readonly attribute ZG_CSSStyleSheet    parentStyleSheet;
 readonly attribute ZG_CSSRule          parentRule;
 */
#import <Foundation/Foundation.h>

@class ZG_CSSStyleSheet;

typedef enum ZG_CSSRuleType
{
	ZG_UNKNOWN_RULE                   = 0,
	ZG_STYLE_RULE                     = 1,
    ZG_CHARSET_RULE                   = 2,
    ZG_IMPORT_RULE                    = 3,
    ZG_MEDIA_RULE                     = 4,
    ZG_FONT_FACE_RULE                 = 5,
    ZG_PAGE_RULE                      = 6
} ZG_CSSRuleType;

@interface ZG_CSSRule : NSObject

@property(nonatomic) unsigned short type;
@property(nonatomic,strong) NSString* cssText;

@property(nonatomic,strong) ZG_CSSStyleSheet* parentStyleSheet;
@property(nonatomic,strong) ZG_CSSRule* parentRule;
	
@end
