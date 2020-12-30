/*
 From SVG-DOM, via Core-DOM:
 
 http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-1780488922
 
 interface ZG_NamedNodeMap {
 ZG_Node               getNamedItem(in DOMString name);
 ZG_Node               setNamedItem(in ZG_Node arg)
 raises(DOMException);
 ZG_Node               removeNamedItem(in DOMString name)
 raises(DOMException);
 ZG_Node               item(in unsigned long index);
 readonly attribute unsigned long    length;
 // Introduced in DOM Level 2:
 ZG_Node               getNamedItemNS(in DOMString namespaceURI, 
 in DOMString localName);
 // Introduced in DOM Level 2:
 ZG_Node               setNamedItemNS(in ZG_Node arg)
 raises(DOMException);
 // Introduced in DOM Level 2:
 ZG_Node               removeNamedItemNS(in DOMString namespaceURI, 
 in DOMString localName)
 raises(DOMException);
 };

 */

#import <Foundation/Foundation.h>

@class ZG_Node;
#import "ZG_Node.h"

@interface ZG_NamedNodeMap : NSObject </** needed so we can output SVG text in the [ZG_Node appendToXML:..] methods */ NSCopying>

-(ZG_Node*) getNamedItem:(NSString*) name;
-(ZG_Node*) setNamedItem:(ZG_Node*) arg;
-(ZG_Node*) removeNamedItem:(NSString*) name;
-(ZG_Node*) item:(unsigned long) index;

@property(readonly) unsigned long length;

// Introduced in DOM Level 2:
-(ZG_Node*) getNamedItemNS:(NSString*) namespaceURI localName:(NSString*) localName;

// Introduced in DOM Level 2:
-(ZG_Node*) setNamedItemNS:(ZG_Node*) arg;

// Introduced in DOM Level 2:
-(ZG_Node*) removeNamedItemNS:(NSString*) namespaceURI localName:(NSString*) localName;

#pragma mark - MISSING METHOD FROM SVG Spec, without which you cannot parse documents (don't understand how they intended you to fulfil the spec without this method)

-(ZG_Node*) setNamedItemNS:(ZG_Node*) arg inNodeNamespace:(NSString*) nodesNamespace;

@end
