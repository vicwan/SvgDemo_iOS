/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSValueList
 
 interface ZG_CSSValueList : ZG_CSSValue {
 readonly attribute unsigned long    length;
 ZG_CSSValue           item(in unsigned long index);
 */

#import "ZG_CSSValue.h"

@interface ZG_CSSValueList : ZG_CSSValue

@property(nonatomic,readonly) unsigned long length;

-(ZG_CSSValue*) item:(unsigned long) index;

@end
