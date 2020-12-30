//
//  ZG_SVGTextLayer.m
//  SVGKit-iOS
//
//  Created by lizhuoli on 2018/11/6.
//  Copyright © 2018 na. All rights reserved.
//

#import "ZG_SVGTextLayer.h"
#import "ZG_SVGKDefine.h"

@implementation ZG_SVGTextLayer

- (BOOL)contentsAreFlipped {
#if SVGKIT_MAC
    return YES;
#else
    return [super contentsAreFlipped];
#endif
}

@end
