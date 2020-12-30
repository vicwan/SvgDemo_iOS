/*
 From SVG-DOM, via Core DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-11C98490
 
 interface ZG_EntityReference : ZG_Node {
 };
 */
#import <Foundation/Foundation.h>

/** objc won't allow this: @class ZG_Node; */
#import "ZG_Node.h"

@interface ZG_EntityReference : ZG_Node

@end
