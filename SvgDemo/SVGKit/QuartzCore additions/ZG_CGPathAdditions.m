//
//  ZG_CGPathAdditions.m
//  SVGPad
//
//  Copyright Matt Rajca 2011. All rights reserved.
//

#import "ZG_CGPathAdditions.h"
#import <stdlib.h>

void ZG_applier (void *info, const CGPathElement *element);

typedef struct {
	CGMutablePathRef path;
	CGFloat offX;
	CGFloat offY;
} ZG_PathInfo;

CGFloat ZG_fixInfinity(CGFloat inputFloat){
    if(inputFloat>CGFLOAT_MAX) inputFloat=CGFLOAT_MAX;
    if(inputFloat<(-1)*CGFLOAT_MAX) inputFloat=(-1)*CGFLOAT_MAX;
    return inputFloat;
}

CGPoint *ZG_fixPointsInfinity(const CGPathElement *element){
    int i,total;
    
    switch (element->type) {
        case kCGPathElementMoveToPoint:
            total=1;
            break;
        case kCGPathElementAddLineToPoint:
            total=1;
            break;
        case kCGPathElementAddQuadCurveToPoint:
            total=2;
            break;
        case kCGPathElementAddCurveToPoint:
            total=3;
            break;
        default:
            total=0;
            break;
    }
	
	if( total == 0 )
		return NULL; // Avoid malloc(0); keep C compilers happy
	
	CGPoint* returnArray = malloc(sizeof(CGPoint) * total);
    for (i = 0; i < total; i++)
    {
        returnArray[i].x=ZG_fixInfinity(element->points[i].x);
        returnArray[i].y=ZG_fixInfinity(element->points[i].y);
    }
    return returnArray;
}

void ZG_applier (void *info, const CGPathElement *element) {
	ZG_PathInfo *pathInfo = (ZG_PathInfo *) info;
	
	CGMutablePathRef path = pathInfo->path;
	CGFloat x = ZG_fixInfinity(pathInfo->offX);
	CGFloat y = ZG_fixInfinity(pathInfo->offY);
    
	CGPoint *points = ZG_fixPointsInfinity(element);
	
	switch (element->type) {
		case kCGPathElementMoveToPoint:
			CGPathMoveToPoint(path, NULL, points[0].x - x, points[0].y - y);
			break;
		case kCGPathElementAddLineToPoint:
			CGPathAddLineToPoint(path, NULL, points[0].x - x, points[0].y - y);
			break;
		case kCGPathElementAddQuadCurveToPoint:
			CGPathAddQuadCurveToPoint(path, NULL, points[0].x - x, points[0].y - y,
									  points[1].x - x, points[1].y - y);
			break;
		case kCGPathElementAddCurveToPoint:
			CGPathAddCurveToPoint(path, NULL, points[0].x - x, points[0].y - y,
								  points[1].x - x, points[1].y - y,
								  points[2].x - x, points[2].y - y);
			break;
		case kCGPathElementCloseSubpath:
			CGPathCloseSubpath(path);
			break;
	}
	
	free(points);
}

CGPathRef ZG_CGPathCreateByOffsettingPath (CGPathRef aPath, CGFloat x, CGFloat y) {
	CGMutablePathRef path = CGPathCreateMutable();
	
	ZG_PathInfo *info = (ZG_PathInfo *) malloc(sizeof(ZG_PathInfo));
	info->path = path;
	info->offX = ZG_fixInfinity(x);
	info->offY = ZG_fixInfinity(y);
	
	CGPathApply(aPath, info, &ZG_applier);
	free(info);
	
	return path;
}

void ZG_applyPathTranslation (void *info, const CGPathElement *element) {
	ZG_PathInfo *pathInfo = (ZG_PathInfo *) info;
	
	CGMutablePathRef path = pathInfo->path;
	CGFloat x = ZG_fixInfinity(pathInfo->offX);
	CGFloat y = ZG_fixInfinity(pathInfo->offY);
	
	CGPoint *points = ZG_fixPointsInfinity(element);
	
	switch (element->type) {
		case kCGPathElementMoveToPoint:
			CGPathMoveToPoint(path, NULL, points[0].x + x, points[0].y + y);
			break;
		case kCGPathElementAddLineToPoint:
			CGPathAddLineToPoint(path, NULL, points[0].x + x, points[0].y + y);
			break;
		case kCGPathElementAddQuadCurveToPoint:
			CGPathAddQuadCurveToPoint(path, NULL, points[0].x + x, points[0].y + y,
									  points[1].x + x, points[1].y + y);
			break;
		case kCGPathElementAddCurveToPoint:
			CGPathAddCurveToPoint(path, NULL, points[0].x + x, points[0].y + y,
								  points[1].x + x, points[1].y + y,
								  points[2].x + x, points[2].y + y);
			break;
		case kCGPathElementCloseSubpath:
			CGPathCloseSubpath(path);
			break;
	}
	
	free(points);
}

CGPathRef ZG_CGPathCreateByTranslatingPath (CGPathRef aPath, CGFloat x, CGFloat y) {
	CGMutablePathRef path = CGPathCreateMutable();
	
	ZG_PathInfo *info = (ZG_PathInfo *) malloc(sizeof(ZG_PathInfo));
	info->path = path;
	info->offX = ZG_fixInfinity(x);
	info->offY = ZG_fixInfinity(y);
	
	CGPathApply(aPath, info, &ZG_applyPathTranslation);
	free(info);
	
	return path;
}
