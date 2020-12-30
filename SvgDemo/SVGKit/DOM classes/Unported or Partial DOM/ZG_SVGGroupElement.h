//
//  ZG_SVGGroupElement.h
//  ZG_SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import "ZG_SVGElement.h"
#import "ZG_ConverterSVGToCALayer.h"

@interface ZG_SVGGroupElement : ZG_SVGElement < ZG_ConverterSVGToCALayer > { }

@property (nonatomic, readonly) CGFloat opacity;

@end
