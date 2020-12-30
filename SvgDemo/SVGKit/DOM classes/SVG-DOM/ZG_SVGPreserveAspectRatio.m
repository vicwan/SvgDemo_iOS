#import "ZG_SVGPreserveAspectRatio.h"

@implementation ZG_SVGPreserveAspectRatio

/** Sets default values mandated by SVG Spec */
- (id)init
{
    self = [super init];
    if (self) {
        self.align = ZG_SVG_PRESERVEASPECTRATIO_XMIDYMID;
		self.meetOrSlice = ZG_SVG_MEETORSLICE_MEET;
    }
    return self;
}
@end
