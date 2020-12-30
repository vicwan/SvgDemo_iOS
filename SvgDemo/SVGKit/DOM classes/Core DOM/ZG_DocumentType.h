/*
 From SVG-DOM, via Core DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-412266927
 
 interface ZG_DocumentType : ZG_Node {
 readonly attribute DOMString        name;
 readonly attribute ZG_NamedNodeMap     entities;
 readonly attribute ZG_NamedNodeMap     notations;
 // Introduced in DOM Level 2:
 readonly attribute DOMString        publicId;
 // Introduced in DOM Level 2:
 readonly attribute DOMString        systemId;
 // Introduced in DOM Level 2:
 readonly attribute DOMString        internalSubset;
 };
*/
#import <Foundation/Foundation.h>

#import "ZG_Node.h"
#import "ZG_NamedNodeMap.h"

@interface ZG_DocumentType : ZG_Node

@property(nonatomic,strong,readonly) NSString* name;
@property(nonatomic,strong,readonly) ZG_NamedNodeMap* entities;
@property(nonatomic,strong,readonly) ZG_NamedNodeMap* notations;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readonly) NSString* publicId;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readonly) NSString* systemId;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readonly) NSString* internalSubset;


@end
