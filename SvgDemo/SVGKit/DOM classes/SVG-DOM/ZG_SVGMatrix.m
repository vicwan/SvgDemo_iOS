
#import "ZG_SVGMatrix.h"

@implementation ZG_SVGMatrix

@synthesize a,b,c,d,e,f;

-(ZG_SVGMatrix*) multiply:(ZG_SVGMatrix*) secondMatrix { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) inverse { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) translate:(float) x y:(float) y { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) scale:(float) scaleFactor { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) scaleNonUniform:(float) scaleFactorX scaleFactorY:(float) scaleFactorY { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) rotate:(float) angle { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) rotateFromVector:(float) x y:(float) y { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) flipX { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) flipY { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) skewX:(float) angle { NSAssert( FALSE, @"Not implemented yet" ); return nil; }
-(ZG_SVGMatrix*) skewY:(float) angle { NSAssert( FALSE, @"Not implemented yet" ); return nil; }

@end
