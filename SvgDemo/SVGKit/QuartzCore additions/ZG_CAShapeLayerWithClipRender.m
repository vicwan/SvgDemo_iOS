//
//  ZG_CAShapeLayerWithClipRender.m
//  SVGKit-iOS
//
//  Created by David Gileadi on 8/14/14.
//  Copyright (c) 2014 na. All rights reserved.
//

#import "ZG_CAShapeLayerWithClipRender.h"
#import "ZG_CALayerWithClipRender.h"

@implementation ZG_CAShapeLayerWithClipRender

- (void)renderInContext:(CGContextRef)ctx {
	if (CGRectIsEmpty(self.bounds)) return;

    CALayer *mask = nil;
    if( self.mask != nil ) {
        [ZG_CALayerWithClipRender maskLayer:self inContext:ctx];
        
        mask = self.mask;
        self.mask = nil;
    }
    
    [super renderInContext:ctx];
    
    if( mask != nil ) {
        self.mask = mask;
    }
}

@end
