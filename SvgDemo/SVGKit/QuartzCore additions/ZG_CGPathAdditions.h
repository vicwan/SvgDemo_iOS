//
//  ZG_CGPathAdditions.h
//  SVGPad
//
//  Copyright Matt Rajca 2011. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

/*! From original ZG_SVGKit, but it seems to be "the opposite of translation" */
CGPathRef ZG_CGPathCreateByOffsettingPath (CGPathRef aPath, CGFloat x, CGFloat y);

/*! New ZG_SVGKit: carefully named method that does what it claims to: it translates a path by the specified amount */
CGPathRef ZG_CGPathCreateByTranslatingPath (CGPathRef aPath, CGFloat x, CGFloat y);
