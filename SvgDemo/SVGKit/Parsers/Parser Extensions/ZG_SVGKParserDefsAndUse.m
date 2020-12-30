#import "ZG_SVGKParserDefsAndUse.h"

#import "ZG_Node.h"
#import "ZG_SVGKSource.h"
#import "ZG_SVGKParseResult.h"

#import "ZG_SVGDefsElement.h"
#import "ZG_SVGUseElement.h"
#import "ZG_SVGUseElement_Mutable.h"
#import "ZG_SVGElementInstance.h"
#import "ZG_SVGElementInstance_Mutable.h"
#import "ZG_SVGElementInstanceList.h"
#import "ZG_SVGElement_ForParser.h"

@implementation ZG_SVGKParserDefsAndUse

-(NSArray*) supportedNamespaces
{
	return [NSArray arrayWithObjects:
			@"http://www.w3.org/2000/svg",
			nil];
}

/** "tags supported" is exactly the set of all ZG_SVGElement subclasses that already exist */
-(NSArray*) supportedTags
{
	return [NSMutableArray arrayWithObjects: @"defs", @"use", nil];
}

-(ZG_SVGElementInstance*) convertSVGElementToElementInstanceTree:(ZG_SVGElement*) original outermostUseElement:(ZG_SVGUseElement*) outermostUseElement
{
	ZG_SVGElementInstance* instance = [[ZG_SVGElementInstance alloc] init];
	instance.correspondingElement = original;
	instance.correspondingUseElement = outermostUseElement;
	
	for( ZG_Node* subNode in original.childNodes )
	{
		if( [subNode isKindOfClass:[ZG_SVGElement class]])
		{
			ZG_SVGElement* subElement = (ZG_SVGElement*) subNode;
			
			ZG_SVGElementInstance *newSubInstance = [self convertSVGElementToElementInstanceTree:subElement outermostUseElement:outermostUseElement];
			
			newSubInstance.parentNode = instance; // side-effect: automatically adds sub as child
		}
	}
	
	return instance;
}

- (ZG_Node*) handleStartElement:(NSString *)name document:(ZG_SVGKSource*) ZG_SVGKSource namePrefix:(NSString*)prefix namespaceURI:(NSString*) XMLNSURI attributes:(NSMutableDictionary *)attributes parseResult:(ZG_SVGKParseResult *)parseResult parentNode:(ZG_Node*) parentNode
{
	if( [[self supportedNamespaces] containsObject:XMLNSURI] )
	{	
		NSString* qualifiedName = (prefix == nil) ? name : [NSString stringWithFormat:@"%@:%@", prefix, name];
		
		if( [name isEqualToString:@"defs"])
		{	
			/** NB: must supply a NON-qualified name if we have no specific prefix here ! */
			ZG_SVGDefsElement *element = [[ZG_SVGDefsElement alloc] initWithQualifiedName:qualifiedName inNameSpaceURI:XMLNSURI attributes:attributes];
			
			return element;
		}
		else if( [name isEqualToString:@"use"])
		{	
			/** NB: must supply a NON-qualified name if we have no specific prefix here ! */
			ZG_SVGUseElement *useElement = [[ZG_SVGUseElement alloc] initWithQualifiedName:qualifiedName inNameSpaceURI:XMLNSURI attributes:attributes];
			
			[useElement postProcessAttributesAddingErrorsTo:parseResult]; // handles "transform" and "style"
			
			if( [attributes valueForKey:@"x"] != nil )
				useElement.x = [ZG_SVGLength svgLengthFromNSString:[((ZG_Attr*)[attributes valueForKey:@"x"]) value]];
			if( [attributes valueForKey:@"y"] != nil )
				useElement.y = [ZG_SVGLength svgLengthFromNSString:[((ZG_Attr*)[attributes valueForKey:@"y"]) value]];
			if( [attributes valueForKey:@"width"] != nil )
				useElement.width = [ZG_SVGLength svgLengthFromNSString:[((ZG_Attr*)[attributes valueForKey:@"width"]) value]];
			if( [attributes valueForKey:@"height"] != nil )
				useElement.height = [ZG_SVGLength svgLengthFromNSString:[((ZG_Attr*)[attributes valueForKey:@"height"]) value]];
			
			NSString* hrefAttribute = [useElement getAttributeNS:@"http://www.w3.org/1999/xlink" localName:@"href"];
			
			NSAssert( [hrefAttribute length] > 0, @"Found an SVG <use> tag that has no 'xlink:href' attribute. File is invalid / don't know how to parse this" );
			if( [hrefAttribute length] > 0 )
			{
				NSString* linkHref = [((ZG_Attr*)[attributes valueForKey:@"xlink:href"]) value];
                /** support `url(#id) funcIRI as well to follow SVG spec` */
                if ([linkHref hasPrefix:@"url"]) {
                    NSRange range = NSMakeRange(4, linkHref.length - 5);
                    linkHref = [linkHref substringWithRange:range];
                }
                 
                NSAssert( [linkHref hasPrefix:@"#"], @"Not supported: <use> tags that declare an href to something that DOESN'T begin with #. Href supplied = %@", linkHref );
				
				linkHref = [linkHref substringFromIndex:1];
				
				/** have to find the node in the DOM tree with id = xlink:href's value */
				ZG_SVGElement* linkedElement = (ZG_SVGElement*) [parseResult.parsedDocument getElementById:linkHref];
				
				NSAssert( linkedElement != nil, @"Found an SVG <use> tag that points to a non-existent element. Missing element: id = %@", linkHref );
				
				
				useElement.instanceRoot = [self convertSVGElementToElementInstanceTree:linkedElement outermostUseElement:useElement];
			}
			
			return useElement;
		}
	}
	
	return nil;
}

-(void)handleEndElement:(ZG_Node *)newNode document:(ZG_SVGKSource *)document parseResult:(ZG_SVGKParseResult *)parseResult
{
	
}

@end
