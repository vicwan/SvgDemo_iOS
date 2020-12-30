//
//  ZG_SVGLineElement.h
//  ZG_SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import "ZG_BaseClassForAllSVGBasicShapes.h"

@interface ZG_SVGLineElement : ZG_BaseClassForAllSVGBasicShapes { }

@property (nonatomic, readonly) CGFloat x1;
@property (nonatomic, readonly) CGFloat y1;
@property (nonatomic, readonly) CGFloat x2;
@property (nonatomic, readonly) CGFloat y2;

@end
