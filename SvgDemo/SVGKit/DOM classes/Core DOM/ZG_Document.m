#import "ZG_Document.h"
#import "ZG_Document+Mutable.h"

#import "ZG_DOMHelperUtilities.h"

#import "ZG_NodeList+Mutable.h" // needed for access to underlying array, because SVG doesnt specify how lists are made mutable

#import "ZG_SVGKDefine_Private.h"

@implementation ZG_Document

@synthesize doctype;
@synthesize implementation;
@synthesize documentElement;



-(ZG_Element*) createElement:(NSString*) tagName
{
	ZG_Element* newElement = [[ZG_Element alloc] initWithLocalName:tagName attributes:nil];
	
	SVGKitLogVerbose( @"[%@] WARNING: SVG Spec, missing feature: if there are known attributes with default values, ZG_Attr nodes representing them SHOULD BE automatically created and attached to the element.", [self class] );
	
	return newElement;
}

-(ZG_DocumentFragment*) createDocumentFragment
{
	return [[ZG_DocumentFragment alloc] init];
}

-(ZG_Text*) createTextNode:(NSString*) data
{
	return [[ZG_Text alloc] initWithValue:data];
}

-(ZG_Comment*) createComment:(NSString*) data
{
	return [[ZG_Comment alloc] initWithValue:data];
}

-(ZG_CDATASection*) createCDATASection:(NSString*) data
{
	return [[ZG_CDATASection alloc] initWithValue:data];
}

-(ZG_ProcessingInstruction*) createProcessingInstruction:(NSString*) target data:(NSString*) data
{
	return [[ZG_ProcessingInstruction alloc] initProcessingInstruction:target value:data];
}

-(ZG_Attr*) createAttribute:(NSString*) n
{
	return [[ZG_Attr alloc] initWithName:n value:@""];
}

-(ZG_EntityReference*) createEntityReference:(NSString*) data
{
	NSAssert( FALSE, @"Not implemented. According to spec: Creates an ZG_EntityReference object. In addition, if the referenced entity is known, the child list of the ZG_EntityReference  node is made the same as that of the corresponding Entity  node. Note: If any descendant of the Entity node has an unbound namespace prefix, the corresponding descendant of the created ZG_EntityReference node is also unbound; (its namespaceURI is null). The DOM Level 2 does not support any mechanism to resolve namespace prefixes." );
	return nil;
}

-(ZG_NodeList*) getElementsByTagName:(NSString*) data
{
	ZG_NodeList* accumulator = [[ZG_NodeList alloc] init];
	[ZG_DOMHelperUtilities privateGetElementsByName:data inNamespace:nil childrenOfElement:self.documentElement addToList:accumulator];
	
	return accumulator;
}

// Introduced in DOM Level 2:
-(ZG_Node*) importNode:(ZG_Node*) importedNode deep:(BOOL) deep
{
	NSAssert( FALSE, @"Not implemented." );
	return nil;
}

// Introduced in DOM Level 2:
-(ZG_Element*) createElementNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName
{
	ZG_Element* newElement = [[ZG_Element alloc] initWithQualifiedName:qualifiedName inNameSpaceURI:namespaceURI attributes:nil];
	
	SVGKitLogVerbose( @"[%@] WARNING: SVG Spec, missing feature: if there are known attributes with default values, ZG_Attr nodes representing them SHOULD BE automatically created and attached to the element.", [self class] );
	
	return newElement;
}

// Introduced in DOM Level 2:
-(ZG_Attr*) createAttributeNS:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName
{
	NSAssert( FALSE, @"This should be re-implemented to share code with createElementNS: method above" );
	ZG_Attr* newAttr = [[ZG_Attr alloc] initWithNamespace:namespaceURI qualifiedName:qualifiedName value:@""];
	return newAttr;
}

// Introduced in DOM Level 2:
-(ZG_NodeList*) getElementsByTagNameNS:(NSString*) namespaceURI localName:(NSString*) localName
{
	ZG_NodeList* accumulator = [[ZG_NodeList alloc] init];
	[ZG_DOMHelperUtilities privateGetElementsByName:localName inNamespace:namespaceURI childrenOfElement:self.documentElement addToList:accumulator];
	
	return accumulator;
}

// Introduced in DOM Level 2:
-(ZG_Element*) getElementById:(NSString*) elementId
{
	return [ZG_DOMHelperUtilities privateGetElementById:elementId childrenOfElement:self.documentElement];
}

@end
