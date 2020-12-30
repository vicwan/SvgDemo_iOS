#import "ZG_SVGPolylineElement.h"

#import "ZG_SVGUtils.h"

#import "ZG_SVGElement_ForParser.h" // to resolve Xcode circular dependencies; in long term, parsing SHOULD NOT HAPPEN inside any class whose name starts "SVG" (because those are reserved classes for the SVG Spec)


@implementation ZG_SVGPolylineElement

- (void)postProcessAttributesAddingErrorsTo:(ZG_SVGKParseResult *)parseResult {
	[super postProcessAttributesAddingErrorsTo:parseResult];
	
	if( [[self getAttribute:@"points"] length] > 0 )
	{
		CGMutablePathRef path = ZG_createPathFromPointsInString([[self getAttribute:@"points"] UTF8String], NO);
		
		self.pathForShapeInRelativeCoords = path;
		CGPathRelease(path);
	}
}

@end
