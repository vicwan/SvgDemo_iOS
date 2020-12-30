/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSRuleList
 
 interface ZG_CSSRuleList {
 readonly attribute unsigned long    length;
 ZG_CSSRule            item(in unsigned long index);
 */
#import <Foundation/Foundation.h>

#import "ZG_CSSRule.h"

@interface ZG_CSSRuleList : NSObject

@property(nonatomic,readonly) unsigned long length;

-(ZG_CSSRule*) item:(unsigned long) index;

@end
