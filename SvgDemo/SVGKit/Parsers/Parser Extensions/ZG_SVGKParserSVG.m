#import "ZG_SVGKParserSVG.h"

#import "ZG_SVGSVGElement.h"
#import "ZG_SVGCircleElement.h"
#import "ZG_SVGClipPathElement.h"
#import "ZG_SVGDefsElement.h"
#import "ZG_SVGDescriptionElement.h"
//#import "ZG_SVGKSource.h"
#import "ZG_SVGEllipseElement.h"
#import "ZG_SVGGElement.h"
#import "ZG_SVGImageElement.h"
#import "ZG_SVGLineElement.h"
#import "ZG_SVGPathElement.h"
#import "ZG_SVGPolygonElement.h"
#import "ZG_SVGPolylineElement.h"
#import "ZG_SVGRectElement.h"
#import "ZG_SVGSwitchElement.h"
#import "ZG_SVGTitleElement.h"
#import "ZG_SVGTextElement.h"
#import "ZG_TinySVGTextAreaElement.h"

#import "ZG_SVGDocument_Mutable.h"

#import "ZG_SVGKDefine_Private.h"

@interface ZG_SVGKParserSVG ()
@property (nonatomic) NSArray *supportedNamespaces;
@property (nonatomic) NSDictionary *elementMap;
@end

@implementation ZG_SVGKParserSVG

- (NSDictionary *)elementMap {
    if (!_elementMap) {
        _elementMap = [NSDictionary dictionaryWithObjectsAndKeys:
                      [ZG_SVGSVGElement class], @"svg",
                      [ZG_SVGCircleElement class], @"circle",
                      [ZG_SVGDescriptionElement class], @"description",
                      [ZG_SVGEllipseElement class], @"ellipse",
                      [ZG_SVGGElement class], @"g",
                      [ZG_SVGClipPathElement class], @"clipPath",
                      [ZG_SVGImageElement class], @"image",
                      [ZG_SVGLineElement class], @"line",
                      [ZG_SVGPathElement class], @"path",
                      [ZG_SVGPolygonElement class], @"polygon",
                      [ZG_SVGPolylineElement class], @"polyline",
                      [ZG_SVGRectElement class], @"rect",
                      [ZG_SVGSwitchElement class], @"switch",
                      [ZG_SVGTitleElement class], @"title",
                      [ZG_SVGTextElement class], @"text",
                      [ZG_TinySVGTextAreaElement class], @"textArea",
                      nil];
    }
    return _elementMap;
}

-(NSArray *)supportedNamespaces
{
    if( _supportedNamespaces == nil )
        _supportedNamespaces = @[@"http://www.w3.org/2000/svg"];
    return _supportedNamespaces;
}

/** "tags supported" is exactly the set of all ZG_SVGElement subclasses that already exist */
-(NSArray*) supportedTags
{
    return [self.elementMap allKeys];
}

- (ZG_Node*) handleStartElement:(NSString *)name document:(ZG_SVGKSource*) ZG_SVGKSource namePrefix:(NSString*)prefix namespaceURI:(NSString*) XMLNSURI attributes:(NSMutableDictionary *)attributes parseResult:(ZG_SVGKParseResult *)parseResult parentNode:(ZG_Node*) parentNode
{
	if( [[self supportedNamespaces] containsObject:XMLNSURI] )
	{
		Class elementClass = [self.elementMap objectForKey:name];
		
		if (!elementClass) {
			elementClass = [ZG_SVGElement class];
			SVGKitLogWarn(@"Support for '%@' element has not been implemented", name);
		}
		
		/**
		 NB: following the SVG Spec, it's critical that we ONLY use the DOM methods for creating
		 basic 'Element' nodes.
		 
		 Our ZG_SVGElement root class has an implementation of init that delegates to the same
		 private methods that the DOM methods use, so it's safe...
		 
		 FIXME: ...but in reality we ought to be using the DOMDocument createElement/NS methods, although "good luck" trying to find a DOMDocument if your SVG is embedded inside a larger XML document :(
		 */
		
		
		NSString* qualifiedName = (prefix == nil) ? name : [NSString stringWithFormat:@"%@:%@", prefix, name];
		/** NB: must supply a NON-qualified name if we have no specific prefix here ! */
		ZG_SVGElement *element = [[elementClass alloc] initWithQualifiedName:qualifiedName inNameSpaceURI:XMLNSURI attributes:attributes];
		
		/** NB: all the interesting handling of shared / generic attributes - e.g. the whole of CSS styling etc - takes place in this method: */
		[element postProcessAttributesAddingErrorsTo:parseResult];
		
		/** special case: <svg:svg ... version="XXX"> */
		if( [@"svg" isEqualToString:name] )
		{
            ((ZG_SVGSVGElement *) element).source = ZG_SVGKSource;
            
			NSString* svgVersion = nil;
			
			/** According to spec, if the first XML node is an SVG node, then it
			 becomes TWO THINGS:
			 
			 - An ZG_SVGSVGElement
			 *and*
			 - An ZG_SVGDocument
			 - ...and that becomes "the root SVGDocument"
			 
			 If it's NOT the first XML node, but it's the first SVG node, then it ONLY becomes:
			 
			 - An ZG_SVGSVGElement
			 
			 If it's NOT the first SVG node, then it becomes:
			 
			 - An ZG_SVGSVGElement
			 *and*
			 - An ZG_SVGDocument
			 
			 Yes. It's Very confusing! Go read the SVG Spec!
			 */
			
			BOOL generateAnSVGDocument = FALSE;
			BOOL overwriteRootSVGDocument = FALSE;
			BOOL overwriteRootOfTree = FALSE;
			
			if( parentNode == nil )
			{
				/** This start element is the first item in the document
				 PS: xcode has a new bug for Lion: it can't format single-line comments with two asterisks. This line added because Xcode sucks.
				 */
				generateAnSVGDocument = overwriteRootSVGDocument = overwriteRootOfTree = TRUE;
				
			}
			else if( parseResult.rootOfSVGTree == nil )
			{
				/** It's not the first XML, but it's the first SVG node */
				overwriteRootOfTree = TRUE;
			}
			else
			{
				/** It's not the first SVG node */
				// ... so: do nothing special
			}
			
			/**
			 Handle the complex stuff above about ZG_SVGDocument and SVG node
			 */
			if( overwriteRootOfTree )
			{
				parseResult.rootOfSVGTree = (ZG_SVGSVGElement*) element;
				
				/** Post-processing of the ROOT SVG ONLY (doesn't apply to embedded SVG's )
				 */
				if ((svgVersion = [attributes objectForKey:@"version"])) {
                    ZG_SVGKSource.svgLanguageVersion = svgVersion;
				}
			}
			if( generateAnSVGDocument )
			{
				NSAssert( [element isKindOfClass:[ZG_SVGSVGElement class]], @"Trying to create a new internal ZG_SVGDocument from a ZG_Node that is NOT of type ZG_SVGSVGElement (tag: svg). ZG_Node was of type: %@", NSStringFromClass([element class]));
				
				ZG_SVGDocument* newDocument = [[ZG_SVGDocument alloc] init];
				newDocument.rootElement = (ZG_SVGSVGElement*) element;
				
				if( overwriteRootSVGDocument )
				{
					parseResult.parsedDocument = newDocument;
				}
				else
				{
					NSAssert( FALSE, @"Currently not supported: multiple SVG ZG_Document nodes in a single SVG file" );
				}
			}
			
		}
		
		
		return element;
	}
	
	return nil;
}

-(void)handleEndElement:(ZG_Node *)newNode document:(ZG_SVGKSource *)document parseResult:(ZG_SVGKParseResult *)parseResult
{
	
}

@end
