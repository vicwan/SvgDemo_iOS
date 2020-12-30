#import "ZG_SVGAnimatedPreserveAspectRatio.h"

@implementation ZG_SVGAnimatedPreserveAspectRatio


- (id)init
{
    self = [super init];
    if (self) {
        self.baseVal = [ZG_SVGPreserveAspectRatio new];
    }
    return self;
}

/** TODO: Current implementation (animation not supported anywhere in ZG_SVGKit yet) simply returns
 a copy of self.baseVal --- NOTE: spec REQUIRES you return a copy! It is explicit on this!
 */
-(ZG_SVGPreserveAspectRatio *)animVal
{
	ZG_SVGPreserveAspectRatio* cloneOfBase = [ZG_SVGPreserveAspectRatio new];
	
	cloneOfBase.align = self.baseVal.align;
	cloneOfBase.meetOrSlice = self.baseVal.meetOrSlice;
	
	return cloneOfBase;
}

@end
