/*!
//  ZG_SVGKPointsAndPathsParser.h

 This class really needs to be "upgraded" by wrapping it in a class named
 
     ZG_SVGPathElement
 
 and naming methods in that new class so that they adhere to the method names used in the official SVG standard's ZG_SVGPathElement spec:
 
 http://www.w3.org/TR/SVG11/paths.html#InterfaceSVGPathElement
 
 ...
 
 */
#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

/**
 * Partially spammy; not as spammy as DEBUG_PATH_CREATION
 */
#define VERBOSE_PARSE_SVG_COMMAND_STRINGS 0

/*! Very useful for debugging the parser - this will output one line of logging
 * for every CGPath command that's actually done; you can then compare these lines
 * to the input source file, and manually check what's being sent to the renderer
 * versus what was expected
 *
 * this is MORE SPAMMY than VERBOSE_PARSE_SVG_COMMAND_STRINGS
 */
#define DEBUG_PATH_CREATION 0

typedef NS_ENUM(NSUInteger, ZG_SVGCurveType) {
    ZG_SVGCurveTypePoint,
    ZG_SVGCurveTypeCubic,
    ZG_SVGCurveTypeQuadratic,
};

typedef struct ZG_SVGCurve
{
    ZG_SVGCurveType type;
    CGPoint c1;
    CGPoint c2;
    CGPoint p;
} ZG_SVGCurve;


@interface ZG_SVGKPointsAndPathsParser : NSObject

+ (ZG_SVGCurve) startingCurve;

+ (ZG_SVGCurve) readMovetoDrawtoCommandGroups:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readMovetoDrawto:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readMoveto:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readMovetoArgumentSequence:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;

+ (ZG_SVGCurve) readLinetoCommand:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readLinetoArgumentSequence:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readVerticalLinetoCommand:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readVerticalLinetoArgumentSequence:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readHorizontalLinetoArgumentSequence:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readHorizontalLinetoCommand:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;

+ (ZG_SVGCurve) readQuadraticCurvetoCommand:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readQuadraticCurvetoArgumentSequence:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readQuadraticCurvetoArgument:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin;
+ (ZG_SVGCurve) readSmoothQuadraticCurvetoCommand:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin withPrevCurve:(ZG_SVGCurve)prevCurve;
+ (ZG_SVGCurve) readSmoothQuadraticCurvetoArgumentSequence:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin withPrevCurve:(ZG_SVGCurve)prevCurve;
+ (ZG_SVGCurve) readSmoothQuadraticCurvetoArgument:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin withPrevCurve:(ZG_SVGCurve)prevCurve;

+ (ZG_SVGCurve) readCurvetoCommand:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readCurvetoArgumentSequence:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readCurvetoArgument:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin;
+ (ZG_SVGCurve) readSmoothCurvetoCommand:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin withPrevCurve:(ZG_SVGCurve)prevCurve isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readSmoothCurvetoArgumentSequence:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin withPrevCurve:(ZG_SVGCurve)prevCurve isRelative:(BOOL) isRelative;
+ (ZG_SVGCurve) readSmoothCurvetoArgument:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin withPrevCurve:(ZG_SVGCurve)prevCurve;

+ (ZG_SVGCurve) readEllipticalArcArguments:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin isRelative:(BOOL) isRelative;

+ (ZG_SVGCurve) readCloseCommand:(NSScanner*)scanner path:(CGMutablePathRef)path relativeTo:(CGPoint)origin;

@end
