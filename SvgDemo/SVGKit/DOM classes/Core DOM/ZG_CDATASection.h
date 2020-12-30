/*
 From SVG-DOM, via Core DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-667469212
 
 interface ZG_CDATASection : ZG_Text {
 };
 */
#import <Foundation/Foundation.h>

@class ZG_Text;
#import "ZG_Text.h"

@interface ZG_CDATASection : ZG_Text

- (id)initWithValue:(NSString*) v;

@end
