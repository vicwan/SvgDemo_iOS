//
//  ZG_SVGEllipseElement.m
//  ZG_SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import "ZG_SVGEllipseElement.h"

#import "ZG_SVGElement_ForParser.h" // to resolve Xcode circular dependencies; in long term, parsing SHOULD NOT HAPPEN inside any class whose name starts "SVG" (because those are reserved classes for the SVG Spec)

#import "ZG_SVGHelperUtilities.h"

@interface ZG_SVGEllipseElement()
@property (nonatomic, readwrite) CGFloat cx;
@property (nonatomic, readwrite) CGFloat cy;
@property (nonatomic, readwrite) CGFloat rx;
@property (nonatomic, readwrite) CGFloat ry;
@end

@implementation ZG_SVGEllipseElement

@synthesize cx = _cx;
@synthesize cy = _cy;
@synthesize rx = _rx;
@synthesize ry = _ry;

- (void)postProcessAttributesAddingErrorsTo:(ZG_SVGKParseResult *)parseResult {
	[super postProcessAttributesAddingErrorsTo:parseResult];
	
	ZG_SVGRect r = parseResult.rootOfSVGTree.viewport;
	
	if( [[self getAttribute:@"cx"] length] > 0 )
	{
		self.cx = [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"cx"] ]
		 			pixelsValueWithDimension:r.width];
	}
	if( [[self getAttribute:@"cy"] length] > 0 )
	{
		self.cy = [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"cy"] ]
				   pixelsValueWithDimension:r.height];
	}
	if( [[self getAttribute:@"rx"] length] > 0 )
	{
		self.rx  = [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"rx"] ]
					pixelsValueWithDimension:r.width];
	}
	if( [[self getAttribute:@"ry"] length] > 0 )
	{
		self.ry =  [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"ry"] ]
					 pixelsValueWithDimension:r.height];
	}
	if( [[self getAttribute:@"r"] length] > 0 ) { // circle
		
		self.ry = self.rx = [[ZG_SVGLength svgLengthFromNSString:[self getAttribute:@"r"] ]
							 pixelsValueWithDimension:hypot(r.width, r.height)/M_SQRT2];
	}
    
    CGMutablePathRef path = CGPathCreateMutable();
	CGPathAddEllipseInRect(path, NULL, CGRectMake(self.cx - self.rx, self.cy - self.ry, self.rx * 2, self.ry * 2));
	self.pathForShapeInRelativeCoords = path;
    CGPathRelease(path);
}

@end
