/*
 SVG-DOM, via Core DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-1312295772
 
 interface ZG_Text : ZG_CharacterData {
 ZG_Text               splitText(in unsigned long offset)
 raises(DOMException);
 };
*/

#import <Foundation/Foundation.h>

@class ZG_CharacterData;
#import "ZG_CharacterData.h"

@interface ZG_Text : ZG_CharacterData

- (id)initWithValue:(NSString*) v;

-(ZG_Text*) splitText:(unsigned long) offset;

@end
