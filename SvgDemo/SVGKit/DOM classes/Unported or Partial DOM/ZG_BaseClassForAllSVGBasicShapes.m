#import "ZG_BaseClassForAllSVGBasicShapes.h"
#import "ZG_BaseClassForAllSVGBasicShapes_ForSubclasses.h"

#import "ZG_CGPathAdditions.h"
#import "ZG_SVGDefsElement.h"
#import "ZG_SVGKPattern.h"
#import "ZG_CAShapeLayerWithHitTest.h"

#import "ZG_SVGElement_ForParser.h" // to resolve Xcode circular dependencies; in long term, parsing SHOULD NOT HAPPEN inside any class whose name starts "SVG" (because those are reserved classes for the SVG Spec)

#import "ZG_SVGHelperUtilities.h"

@implementation ZG_BaseClassForAllSVGBasicShapes

@synthesize pathForShapeInRelativeCoords = _pathForShapeInRelativeCoords;

@synthesize transform; // each ZG_SVGElement subclass that conforms to protocol "SVGTransformable" has to re-synthesize this to work around bugs in Apple's Objective-C 2.0 design that don't allow @properties to be extended by categories / protocols

- (id)init
{
    self = [super init];
    if (self) {
        self.pathForShapeInRelativeCoords = NULL;
    }
    return self;
}


- (void)dealloc {
	CGPathRelease(_pathForShapeInRelativeCoords);
    
}

-(void)setPathForShapeInRelativeCoords:(CGPathRef)pathForShapeInRelativeCoords
{
	if( pathForShapeInRelativeCoords == _pathForShapeInRelativeCoords )
		return;
	
	CGPathRelease( _pathForShapeInRelativeCoords ); // Apple says NULL is fine as argument
	_pathForShapeInRelativeCoords = pathForShapeInRelativeCoords;
	CGPathRetain( _pathForShapeInRelativeCoords );
}

- (CALayer *) newLayer
{
	NSAssert(self.pathForShapeInRelativeCoords != NULL, @"Requested a CALayer for SVG shape that never initialized its own .pathForShapeInRelativeCoords property. Shape class = %@. Shape instance = %@", [self class], self );
	
	return [ZG_SVGHelperUtilities newCALayerForPathBasedSVGElement:self withPath:self.pathForShapeInRelativeCoords];
}

- (void)layoutLayer:(CALayer *)layer { }

@end
