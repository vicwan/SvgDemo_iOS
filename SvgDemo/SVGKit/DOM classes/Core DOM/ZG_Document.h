/*
//  ZG_Document.h

 NOT a Cocoa / Apple document,
 NOT an SVG document,
 BUT INSTEAD: a DOM document (blame w3.org for the too-generic name).
 
 Required for SVG-DOM
 
 c.f.:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#i-Document
 
 interface ZG_Document : ZG_Node {
 readonly attribute ZG_DocumentType     doctype;
 readonly attribute DOMImplementation  implementation;
 readonly attribute ZG_Element          documentElement;
 ZG_Element            createElement(in DOMString tagName)
 raises(DOMException);
 ZG_DocumentFragment   createDocumentFragment();
 ZG_Text               createTextNode(in DOMString data);
 ZG_Comment            createComment(in DOMString data);
 ZG_CDATASection       createCDATASection(in DOMString data)
 raises(DOMException);
 ZG_ProcessingInstruction createProcessingInstruction(in DOMString target, 
 in DOMString data)
 raises(DOMException);
 ZG_Attr               createAttribute(in DOMString name)
 raises(DOMException);
 ZG_EntityReference    createEntityReference(in DOMString name)
 raises(DOMException);
 ZG_NodeList           getElementsByTagName(in DOMString tagname);
 // Introduced in DOM Level 2:
 ZG_Node               importNode(in ZG_Node importedNode, 
 in boolean deep)
 raises(DOMException);
 // Introduced in DOM Level 2:
 ZG_Element            createElementNS(in DOMString namespaceURI, 
 in DOMString qualifiedName)
 raises(DOMException);
 // Introduced in DOM Level 2:
 ZG_Attr               createAttributeNS(in DOMString namespaceURI, 
 in DOMString qualifiedName)
 raises(DOMException);
 // Introduced in DOM Level 2:
 ZG_NodeList           getElementsByTagNameNS(in DOMString namespaceURI, 
 in DOMString localName);
 // Introduced in DOM Level 2:
 ZG_Element            getElementById(in DOMString elementId);
 };

 
 */

#import <Foundation/Foundation.h>

/** ObjectiveC won't allow this: @class ZG_Node; */
#import "ZG_Node.h"
@class ZG_Element;
#import "ZG_Element.h"
//@class ZG_Comment;
#import "ZG_Comment.h"
@class ZG_CDATASection;
#import "ZG_CDATASection.h"
@class ZG_DocumentFragment;
#import "ZG_DocumentFragment.h"
@class ZG_EntityReference;
#import "ZG_EntityReference.h"
@class ZG_NodeList;
#import "ZG_NodeList.h"
@class ZG_ProcessingInstruction;
#import "ZG_ProcessingInstruction.h"
@class ZG_DocumentType;
#import "ZG_DocumentType.h"
@class ZG_AppleSucksDOMImplementation;
#import "ZG_AppleSucksDOMImplementation.h"

@interface ZG_Document : ZG_Node

@property(nonatomic,strong,readonly) ZG_DocumentType*     doctype;
@property(nonatomic,strong,readonly) ZG_AppleSucksDOMImplementation*  implementation;
@property(nonatomic,strong,readonly) ZG_Element*          documentElement;


-(ZG_Element*) createElement:(NSString*) tagName __attribute__((ns_returns_retained));
-(ZG_DocumentFragment*) createDocumentFragment __attribute__((ns_returns_retained));
-(ZG_Text*) createTextNode:(NSString*) data __attribute__((ns_returns_retained));
-(ZG_Comment*) createComment:(NSString*) data __attribute__((ns_returns_retained));
-(ZG_CDATASection*) createCDATASection:(NSString*) data __attribute__((ns_returns_retained));
-(ZG_ProcessingInstruction*) createProcessingInstruction:(NSString*) target data:(NSString*) data __attribute__((ns_returns_retained));
-(ZG_Attr*) createAttribute:(NSString*) data __attribute__((ns_returns_retained));
-(ZG_EntityReference*) createEntityReference:(NSString*) data __attribute__((ns_returns_retained));

-(ZG_NodeList*) getElementsByTagName:(NSString*) data;

// Introduced in DOM Level 2:
-(ZG_Node*) importNode:(ZG_Node*) importedNode deep:(BOOL) deep;

// Introduced in DOM Level 2:
-(ZG_Element*) createElementNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName __attribute__((ns_returns_retained));

// Introduced in DOM Level 2:
-(ZG_Attr*) createAttributeNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName;

// Introduced in DOM Level 2:
-(ZG_NodeList*) getElementsByTagNameNS:(NSString*) namespaceURI localName:(NSString*) localName;

// Introduced in DOM Level 2:
-(ZG_Element*) getElementById:(NSString*) elementId;

@end
