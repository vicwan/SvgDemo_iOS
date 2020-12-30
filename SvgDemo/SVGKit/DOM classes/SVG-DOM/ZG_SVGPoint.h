/*!
 http://www.w3.org/TR/SVG/coords.html#InterfaceSVGPoint
 
 interface ZG_SVGPoint {
 
 attribute float x setraises(DOMException);
 attribute float y setraises(DOMException);
 
 ZG_SVGPoint matrixTransform(in ZG_SVGMatrix matrix);
 };
 */
#import <Foundation/Foundation.h>

#import "ZG_SVGMatrix.h"

@interface ZG_SVGPoint : NSObject

@property(nonatomic,readonly) float x, y;

-(ZG_SVGPoint*) matrixTransform:(ZG_SVGMatrix*) matrix;

@end
