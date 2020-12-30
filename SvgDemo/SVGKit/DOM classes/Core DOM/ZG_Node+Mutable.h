/**
 Makes the writable properties all package-private, effectively
 */
#import "ZG_Node.h"

@interface ZG_Node()
@property(nonatomic,strong,readwrite) NSString* nodeName;
@property(nonatomic,strong,readwrite) NSString* nodeValue;

@property(nonatomic,readwrite) ZG_DOMNodeType nodeType;
@property(nonatomic,weak,readwrite) ZG_Node* parentNode;
@property(nonatomic,strong,readwrite) ZG_NodeList* childNodes;
@property(nonatomic,strong,readwrite) ZG_NamedNodeMap* attributes;

@property(nonatomic,weak,readwrite) ZG_Document* ownerDocument;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readwrite) NSString* namespaceURI;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readwrite) NSString* prefix;

// Introduced in DOM Level 2:
@property(nonatomic,strong,readwrite) NSString* localName;

@end
