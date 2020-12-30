/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-CSSStyleSheet
 
 interface ZG_CSSStyleSheet : stylesheets::ZG_StyleSheet {
 readonly attribute ZG_CSSRule          ownerRule;
 readonly attribute ZG_CSSRuleList      cssRules;
 unsigned long      insertRule(in DOMString rule,
 in unsigned long index)
 raises(DOMException);
 void               deleteRule(in unsigned long index)
 raises(DOMException);
 */
#import <Foundation/Foundation.h>

#import "ZG_CSSRule.h"
#import "ZG_CSSRuleList.h"

@interface ZG_CSSStyleSheet : NSObject


@property(nonatomic,strong) ZG_CSSRule* ownerRule;
@property(nonatomic,strong) ZG_CSSRuleList* cssRules;

-(long) insertRule:(NSString*) rule index:(unsigned long) index;
-(void) deleteRule:(unsigned long) index;

#pragma mark - methods needed for ObjectiveC implementation

- (id)initWithString:(NSString*) styleSheetBody;

@end
