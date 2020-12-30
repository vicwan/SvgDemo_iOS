//
//  ZG_SVGUtils.h
//  ZG_SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreFoundation/CoreFoundation.h>
#import <CoreGraphics/CoreGraphics.h>

#define RGB_N(v) (v) / 255.0f

typedef struct {
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
} ZG_SVGColor;

ZG_SVGColor ZG_SVGColorMake (uint8_t r, uint8_t g, uint8_t b, uint8_t a);
ZG_SVGColor ZG_SVGColorFromString (const char *string);

CGFloat ZG_SVGPercentageFromString (const char *string);

CGMutablePathRef ZG_createPathFromPointsInString (const char *string, boolean_t close);
CGColorRef ZG_CGColorWithSVGColor (ZG_SVGColor color);
