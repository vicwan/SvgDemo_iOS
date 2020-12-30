/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSStyleRule
 
 interface ZG_CSSStyleRule : ZG_CSSRule {
 attribute DOMString        selectorText;
 // raises(DOMException) on setting
 
 readonly attribute ZG_CSSStyleDeclaration  style;
 */
#import <Foundation/Foundation.h>

#import "ZG_CSSRule.h"
#import "ZG_CSSStyleDeclaration.h"

@interface ZG_CSSStyleRule : ZG_CSSRule

@property(nonatomic,strong) NSString* selectorText;
@property(nonatomic,strong) ZG_CSSStyleDeclaration* style;

#pragma mark - methods needed for ObjectiveC implementation

- (id)initWithSelectorText:(NSString*) selector styleText:(NSString*) styleText;

@end
