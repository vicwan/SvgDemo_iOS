//
//  ZG_SVGEllipseElement.h
//  ZG_SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import "ZG_BaseClassForAllSVGBasicShapes.h"
#import "ZG_BaseClassForAllSVGBasicShapes_ForSubclasses.h"

@interface ZG_SVGEllipseElement : ZG_BaseClassForAllSVGBasicShapes { }

@property (nonatomic, readonly) CGFloat cx;
@property (nonatomic, readonly) CGFloat cy;
@property (nonatomic, readonly) CGFloat rx;
@property (nonatomic, readonly) CGFloat ry;

@end
