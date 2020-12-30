/*
 From SVG-DOM, via Core DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-1728279322

 interface ZG_Comment : ZG_CharacterData {
 };
*/

#import <Foundation/Foundation.h>

#import "ZG_CharacterData.h"
#ifdef __CARBONCORE__
// macOS's out-of-date Carbon API defined the `Comment` struct and cause naming conflict, so we need re-define it and use macro to avoid changing exist API
#define ZG_Comment SVGKComment
#endif
@interface ZG_Comment : ZG_CharacterData

- (id)initWithValue:(NSString*) v;

@end
