//
//  SVGParserLinearGradient.h
//  SVGPad
//
//  Created by Kevin Stich on 1/31/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZG_SVGKParserSVG.h"


@class ZG_SVGGradientElement;

@interface ZG_SVGKParserGradient : ZG_SVGKParserSVG {
    ZG_SVGGradientElement *currentElement;
}

@end
