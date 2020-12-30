#import "ZG_SVGTextPositioningElement.h"
#import "ZG_SVGTextPositioningElement_Mutable.h"

#import "ZG_SVGElement_ForParser.h" // because we do post-processing of the SVG x,y,dx,dy,rotate attributes

@implementation ZG_SVGTextPositioningElement

@synthesize x,y,dx,dy,rotate;


- (void)postProcessAttributesAddingErrorsTo:(ZG_SVGKParseResult *)parseResult
{
	[super postProcessAttributesAddingErrorsTo:parseResult];
	
	self.x = [self getAttributeAsSVGLength:@"x"];
	self.y = [self getAttributeAsSVGLength:@"y"];
	self.dx = [self getAttributeAsSVGLength:@"dx"];
	self.dy = [self getAttributeAsSVGLength:@"dy"];
	self.rotate = [self getAttributeAsSVGLength:@"rotate"];
}

@end
