/*
 From SVG-DOM, via Core DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-B63ED1A3
 
 interface ZG_DocumentFragment : ZG_Node {
 };
*/

#import <Foundation/Foundation.h>

/** objc won't allow this: @class ZG_Node;*/
#import "ZG_Node.h"

@interface ZG_DocumentFragment : ZG_Node

@end
