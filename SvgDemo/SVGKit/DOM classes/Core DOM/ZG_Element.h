/*
 From SVG-DOM, via Core-DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-745549614
 
 interface ZG_Element : ZG_Node {
 readonly attribute DOMString        tagName;
 DOMString          getAttribute(in DOMString name);
 void               setAttribute(in DOMString name, 
 in DOMString value)
 raises(DOMException);
 void               removeAttribute(in DOMString name)
 raises(DOMException);
 ZG_Attr               getAttributeNode(in DOMString name);
 ZG_Attr               setAttributeNode(in ZG_Attr newAttr)
 raises(DOMException);
 ZG_Attr               removeAttributeNode(in ZG_Attr oldAttr)
 raises(DOMException);
 ZG_NodeList           getElementsByTagName(in DOMString name);
 // Introduced in DOM Level 2:
 DOMString          getAttributeNS(in DOMString namespaceURI, 
 in DOMString localName);
 // Introduced in DOM Level 2:
 void               setAttributeNS(in DOMString namespaceURI, 
 in DOMString qualifiedName, 
 in DOMString value)
 raises(DOMException);
 // Introduced in DOM Level 2:
 void               removeAttributeNS(in DOMString namespaceURI, 
 in DOMString localName)
 raises(DOMException);
 // Introduced in DOM Level 2:
 ZG_Attr               getAttributeNodeNS(in DOMString namespaceURI, 
 in DOMString localName);
 // Introduced in DOM Level 2:
 ZG_Attr               setAttributeNodeNS(in ZG_Attr newAttr)
 raises(DOMException);
 // Introduced in DOM Level 2:
 ZG_NodeList           getElementsByTagNameNS(in DOMString namespaceURI, 
 in DOMString localName);
 // Introduced in DOM Level 2:
 boolean            hasAttribute(in DOMString name);
 // Introduced in DOM Level 2:
 boolean            hasAttributeNS(in DOMString namespaceURI, 
 in DOMString localName);
 };
 */

#import <Foundation/Foundation.h>

/** objc won't allow this: @class ZG_Node;*/
#import "ZG_Node.h"
@class ZG_Attr;
#import "ZG_Attr.h"
@class ZG_NodeList;
#import "ZG_NodeList.h"

@interface ZG_Element : ZG_Node

@property(nonatomic,strong,readonly) NSString* tagName;

-(NSString*) getAttribute:(NSString*) name;
-(void) setAttribute:(NSString*) name value:(NSString*) value;
-(void) removeAttribute:(NSString*) name;
-(ZG_Attr*) getAttributeNode:(NSString*) name;
-(ZG_Attr*) setAttributeNode:(ZG_Attr*) newAttr;
-(ZG_Attr*) removeAttributeNode:(ZG_Attr*) oldAttr;
-(ZG_NodeList*) getElementsByTagName:(NSString*) name;

// Introduced in DOM Level 2:
-(NSString*) getAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName;

// Introduced in DOM Level 2:
-(void) setAttributeNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName value:(NSString*) value;

// Introduced in DOM Level 2:
-(void) removeAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName;

// Introduced in DOM Level 2:
-(ZG_Attr*) getAttributeNodeNS:(NSString*) namespaceURI localName:(NSString*) localName;

// Introduced in DOM Level 2:
-(ZG_Attr*) setAttributeNodeNS:(ZG_Attr*) newAttr;

// Introduced in DOM Level 2:
-(ZG_NodeList*) getElementsByTagNameNS:(NSString*) namespaceURI localName:(NSString*) localName;

// Introduced in DOM Level 2:
-(BOOL) hasAttribute:(NSString*) name;

// Introduced in DOM Level 2:
-(BOOL) hasAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName;

#pragma mark - Objective-C init methods (not in SVG Spec - you're supposed to use SVGDocument's createXXX methods instead)

- (id)initWithLocalName:(NSString*) n attributes:(NSMutableDictionary*) attributes;
- (id)initWithQualifiedName:(NSString*) n inNameSpaceURI:(NSString*) nsURI attributes:(NSMutableDictionary*) attributes;
	
@end
