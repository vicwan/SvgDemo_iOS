//
//  ZG_TinySVGTextAreaElement.h
//  SVGKit-iOS
//
//  Created by David Gileadi on 8/26/14.
//  Copyright (c) 2014 na. All rights reserved.
//

#import "ZG_SVGTextElement.h"

@interface ZG_TinySVGTextAreaElement : ZG_SVGTextElement

@property(nonatomic,strong,readonly) ZG_SVGLength* /* FIXME: should be SVGAnimatedLengthList */ width;
@property(nonatomic,strong,readonly) ZG_SVGLength* /* FIXME: should be SVGAnimatedLengthList */ height;

@end
