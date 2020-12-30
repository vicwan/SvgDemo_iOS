#import "ZG_Element.h"

#import "ZG_NamedNodeMap.h"
#import "ZG_DOMHelperUtilities.h"

@interface ZG_Element()
@property(nonatomic,strong,readwrite) NSString* tagName;
@end

@implementation ZG_Element

@synthesize tagName;


- (id)initWithLocalName:(NSString*) n attributes:(NSMutableDictionary*) attributes {
    self = [super initType:ZG_DOMNodeType_ELEMENT_NODE name:n];
    if (self) {
        self.tagName = n;
		
		for( NSString* attributeName in attributes.allKeys )
		{
			[self setAttribute:attributeName value:[attributes objectForKey:attributeName]];
		}
    }
    return self;
}
- (id)initWithQualifiedName:(NSString*) n inNameSpaceURI:(NSString*) nsURI attributes:(NSMutableDictionary *)attributes
{
    self = [super initType:ZG_DOMNodeType_ELEMENT_NODE name:n inNamespace:nsURI];
    if (self) {
        self.tagName = n;
		
		for( ZG_Attr* attribute in attributes.allValues )
		{
			[self.attributes setNamedItemNS:attribute inNodeNamespace:nsURI];
		}
    }
    return self;
}

-(NSString*) getAttribute:(NSString*) name
{
	/**
	 WARNING: the definition in the spec WILL CORRUPT unsuspecting Objective-C code (including a lot of the original ZG_SVGKit code!).
	 
	 The spec - instead of defining 'nil' - defines "" (empty string) as the
	 correct response.
	 
	 But in most of the modern, C-based, (non-scripting) languages, "" means 0.
	 
	 Very dangerous!
	 */
	ZG_Attr* result = (ZG_Attr*) [self.attributes getNamedItem:name];
	
	if( result == nil || result.value == nil )
		return @""; // according to spec
	else
		return result.value;
}

-(void) setAttribute:(NSString*) name value:(NSString*) value
{
	ZG_Attr* att = [[ZG_Attr alloc] initWithName:name value:value];
	
	[self.attributes setNamedItem:att];
}

-(void) removeAttribute:(NSString*) name
{
	[self.attributes removeNamedItem:name];
	
	NSAssert( FALSE, @"Not fully implemented. Spec says: If the removed attribute is known to have a default value, an attribute immediately appears containing the default value as well as the corresponding namespace URI, local name, and prefix when applicable." );
}

-(ZG_Attr*) getAttributeNode:(NSString*) name
{
	return (ZG_Attr*) [self.attributes getNamedItem:name];
}

-(ZG_Attr*) setAttributeNode:(ZG_Attr*) newAttr
{
	ZG_Attr* oldAtt = (ZG_Attr*) [self.attributes getNamedItem:newAttr.nodeName];
	
	[self.attributes setNamedItem:newAttr];
	
	return oldAtt;
}

-(ZG_Attr*) removeAttributeNode:(ZG_Attr*) oldAttr
{
	[self.attributes removeNamedItem:oldAttr.nodeName];
	
	NSAssert( FALSE, @"Not fully implemented. Spec: If the removed ZG_Attr  has a default value it is immediately replaced. The replacing attribute has the same namespace URI and local name, as well as the original prefix, when applicable. " );
	
	return oldAttr;
}

-(ZG_NodeList*) getElementsByTagName:(NSString*) name
{
	ZG_NodeList* accumulator = [[ZG_NodeList alloc] init];
	[ZG_DOMHelperUtilities privateGetElementsByName:name inNamespace:nil childrenOfElement:self addToList:accumulator];
	
	return accumulator;
}

// Introduced in DOM Level 2:
-(NSString*) getAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	ZG_Attr* result = (ZG_Attr*) [self.attributes getNamedItemNS:namespaceURI localName:localName];
	
	if( result == nil || result.value == nil )
		return @""; // according to spec
	else
		return result.value;
}

// Introduced in DOM Level 2:
-(void) setAttributeNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName value:(NSString*) value
{
	ZG_Attr* att = [[ZG_Attr alloc] initWithNamespace:namespaceURI qualifiedName:qualifiedName value:value];
	
	[self.attributes setNamedItemNS:att];
}

// Introduced in DOM Level 2:
-(void) removeAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	NSAssert( FALSE, @"Not implemented yet" );
}

// Introduced in DOM Level 2:
-(ZG_Attr*) getAttributeNodeNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	ZG_Attr* result = (ZG_Attr*) [self.attributes getNamedItemNS:namespaceURI localName:localName];
	
	return result;
}

// Introduced in DOM Level 2:
-(ZG_Attr*) setAttributeNodeNS:(ZG_Attr*) newAttr
{
	NSAssert( FALSE, @"Not implemented yet" );
	return nil;
}

// Introduced in DOM Level 2:
-(ZG_NodeList*) getElementsByTagNameNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	ZG_NodeList* accumulator = [[ZG_NodeList alloc] init];
	[ZG_DOMHelperUtilities privateGetElementsByName:localName inNamespace:namespaceURI childrenOfElement:self addToList:accumulator];
	
	return accumulator;
}

// Introduced in DOM Level 2:
-(BOOL) hasAttribute:(NSString*) name
{
	ZG_Attr* result = (ZG_Attr*) [self.attributes getNamedItem:name];
	
	return result != nil;
}

// Introduced in DOM Level 2:
-(BOOL) hasAttributeNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	NSAssert( FALSE, @"Not implemented yet" );
	return FALSE;
}

@end
