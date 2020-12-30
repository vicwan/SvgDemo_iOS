//
//  ZG_SVGCircleElement.m
//  ZG_SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import "ZG_SVGCircleElement.h"
#import "ZG_SVGKDefine_Private.h"

@implementation ZG_SVGCircleElement

@dynamic r;

- (CGFloat)r {
	if (self.rx != self.ry) {
		SVGKitLogVerbose(@"Undefined radius of circle");
		return 0.0f;
	}
	
	return self.rx;
}

@end
