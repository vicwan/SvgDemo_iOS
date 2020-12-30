#import "ZG_SVGKParserDOM.h"

#import "ZG_Node+Mutable.h"

@implementation ZG_SVGKParserDOM

/**
 This is a special, magical parser that matches "no namespace" - i.e. matches what happens when no namespace was declared
 */
-(NSArray*) supportedNamespaces
{
	return [NSArray array];
}

/** 
 This is a special, magical parser that matches "all tags"
 */
-(NSArray*) supportedTags
{
	return [NSMutableArray array];
}

- (ZG_Node*) handleStartElement:(NSString *)name document:(ZG_SVGKSource*) ZG_SVGKSource namePrefix:(NSString*)prefix namespaceURI:(NSString*) XMLNSURI attributes:(NSMutableDictionary *)attributeObjects parseResult:(ZG_SVGKParseResult *)parseResult parentNode:(ZG_Node*) parentNode
{
	if( [[self supportedNamespaces] count] == 0
	|| [[self supportedNamespaces] containsObject:XMLNSURI] ) // unnecesary here, but allows safe updates to this parser's matching later
	{	
		NSString* qualifiedName = (prefix == nil) ? name : [NSString stringWithFormat:@"%@:%@", prefix, name];
		
		/** NB: must supply a NON-qualified name if we have no specific prefix here ! */
		// FIXME: we always return an empty ZG_Element here; for DOM spec, should we be detecting things like "comment" nodes? I dont know how libxml handles those and sends them to us. I've never seen one in action...
		ZG_Element *blankElement = [[ZG_Element alloc] initWithQualifiedName:qualifiedName inNameSpaceURI:XMLNSURI attributes:attributeObjects];
		
		return blankElement;
	}
	
	return nil;
}

-(void)handleEndElement:(ZG_Node *)newNode document:(ZG_SVGKSource *)document parseResult:(ZG_SVGKParseResult *)parseResult
{
	
}

/***
 
 None of this can be used any more; text-processing (the only part that used it) CANNOT be handled
 generically, because of the way that the DOM is defined and the libxml XML parser works.
 
 Instead, text-handling, and creation of text nodes, MUST be hard-coded into the ZG_SVGKParser core parser :(
 
-(BOOL) createdNodeShouldStoreContent:(ZG_Node*) item
{
	switch( item.nodeType )
	{
		case DOMNodeType_ATTRIBUTE_NODE:
		case DOMNodeType_DOCUMENT_FRAGMENT_NODE:
		case DOMNodeType_DOCUMENT_NODE:
		case DOMNodeType_DOCUMENT_TYPE_NODE:
		case DOMNodeType_ELEMENT_NODE:
		case DOMNodeType_ENTITY_NODE:
		case DOMNodeType_ENTITY_REFERENCE_NODE:
		case DOMNodeType_NOTATION_NODE:
		{
			return FALSE; // do nothing, according to the table in : http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-1950641247
		} break;
			
		case DOMNodeType_CDATA_SECTION_NODE:
		case DOMNodeType_COMMENT_NODE:
		case DOMNodeType_PROCESSING_INSTRUCTION_NODE:
		case DOMNodeType_TEXT_NODE:
		{
			return TRUE;
		} break;
	}
}

-(void) handleStringContent:(NSMutableString*) content forNode:(ZG_Node*) node parseResult:(ZG_SVGKParseResult *)parseResult
{
	switch( node.nodeType )
	{
		case DOMNodeType_ATTRIBUTE_NODE:
		case DOMNodeType_DOCUMENT_FRAGMENT_NODE:
		case DOMNodeType_DOCUMENT_NODE:
		case DOMNodeType_DOCUMENT_TYPE_NODE:
		case DOMNodeType_ELEMENT_NODE:
		case DOMNodeType_ENTITY_NODE:
		case DOMNodeType_ENTITY_REFERENCE_NODE:
		case DOMNodeType_NOTATION_NODE:
		{
			// do nothing, according to the table in : http://www.w3.org/TR/DOM-Level-2-Core/core.html#ID-1950641247
		} break;
			
		case DOMNodeType_CDATA_SECTION_NODE:
		case DOMNodeType_COMMENT_NODE:
		case DOMNodeType_PROCESSING_INSTRUCTION_NODE:
		case DOMNodeType_TEXT_NODE:
		{
			node.nodeValue = content;
		} break;
	}
}
*/
@end
