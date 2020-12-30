//
//  ZG_SVGLineElement.m
//  ZG_SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import "ZG_SVGLineElement.h"

#import "ZG_SVGElement_ForParser.h" // to resolve Xcode circular dependencies; in long term, parsing SHOULD NOT HAPPEN inside any class whose name starts "SVG" (because those are reserved classes for the SVG Spec)

#import "ZG_SVGHelperUtilities.h"

@implementation ZG_SVGLineElement

@synthesize x1 = _x1;
@synthesize y1 = _y1;
@synthesize x2 = _x2;
@synthesize y2 = _y2;

- (void)postProcessAttributesAddingErrorsTo:(ZG_SVGKParseResult *)parseResult {
	[super postProcessAttributesAddingErrorsTo:parseResult];
	
	ZG_SVGRect r = parseResult.rootOfSVGTree.viewport;

	if( [[self getAttribute:@"x1"] length] > 0 )
	{
		_x1 = [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"x1"] ]
				   pixelsValueWithDimension:r.width];
	}
	if( [[self getAttribute:@"y1"] length] > 0 )
	{
		_y1 = [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"y1"] ]
			   pixelsValueWithDimension:r.height];
	}
	if( [[self getAttribute:@"x2"] length] > 0 )
	{
		_x2 = [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"x2"] ]
			   pixelsValueWithDimension:r.width];
	}
	if( [[self getAttribute:@"y2"] length] > 0 )
	{
		_y2 = [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"y2"] ]
			   pixelsValueWithDimension:r.height];
	}
}

-(CALayer *)newLayer
{
	CGMutablePathRef path = CGPathCreateMutable();
	CGPathMoveToPoint(path, NULL, _x1, _y1);
	CGPathAddLineToPoint(path, NULL, _x2, _y2);
	
	CALayer* result = [ZG_SVGHelperUtilities newCALayerForPathBasedSVGElement:self withPath:path];
	
	CGPathRelease(path);
	return result;
}

@end
