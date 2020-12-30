//
//  ZG_SVGKParserPatternsAndGradients.m
//  ZG_SVGKit
//
//  Created by adam applecansuckmybigtodger on 28/06/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ZG_SVGKParserPatternsAndGradients.h"

#import "ZG_SVGSVGElement.h"
#import "ZG_SVGCircleElement.h"
#import "ZG_SVGDefsElement.h"
#import "ZG_SVGDescriptionElement.h"
//#import "ZG_SVGKSource.h"
#import "ZG_SVGEllipseElement.h"
#import "ZG_SVGImageElement.h"
#import "ZG_SVGLineElement.h"
#import "ZG_SVGPathElement.h"
#import "ZG_SVGPolygonElement.h"
#import "ZG_SVGPolylineElement.h"
#import "ZG_SVGRectElement.h"
#import "ZG_SVGTitleElement.h"

@implementation ZG_SVGKParserPatternsAndGradients


-(NSArray*) supportedNamespaces
{
	return [NSArray arrayWithObjects:
			@"http://www.w3.org/2000/svg",
			nil];
}

/** "tags supported" is exactly the set of all ZG_SVGElement subclasses that already exist */
-(NSArray*) supportedTags
{
	return [NSMutableArray arrayWithObjects:@"pattern", nil];
}

- (ZG_Node*)handleStartElement:(NSString *)name document:(ZG_SVGKSource*) document namePrefix:(NSString*)prefix namespaceURI:(NSString*) XMLNSURI attributes:(NSMutableDictionary *)attributes parseResult:(ZG_SVGKParseResult*) parseResult parentNode:(ZG_Node*) parentNode
{
		
	NSAssert( FALSE, @"Patterns are not supported by ZG_SVGKit yet - no-one has implemented them" );
	
	return nil;
}

-(void)handleEndElement:(ZG_Node *)newNode document:(ZG_SVGKSource *)document parseResult:(ZG_SVGKParseResult *)parseResult
{
	
}

@end
