/*!
 
 http://www.w3.org/TR/SVG/coords.html#InterfaceSVGMatrix
 
 interface ZG_SVGMatrix {
 
 attribute float a setraises(DOMException);
 attribute float b setraises(DOMException);
 attribute float c setraises(DOMException);
 attribute float d setraises(DOMException);
 attribute float e setraises(DOMException);
 attribute float f setraises(DOMException);
 
 ZG_SVGMatrix multiply(in ZG_SVGMatrix secondMatrix);
 ZG_SVGMatrix inverse() raises(SVGException);
 ZG_SVGMatrix translate(in float x, in float y);
 ZG_SVGMatrix scale(in float scaleFactor);
 ZG_SVGMatrix scaleNonUniform(in float scaleFactorX, in float scaleFactorY);
 ZG_SVGMatrix rotate(in float angle);
 ZG_SVGMatrix rotateFromVector(in float x, in float y) raises(SVGException);
 ZG_SVGMatrix flipX();
 ZG_SVGMatrix flipY();
 ZG_SVGMatrix skewX(in float angle);
 ZG_SVGMatrix skewY(in float angle);
 };
 */

#import <Foundation/Foundation.h>

@interface ZG_SVGMatrix : NSObject

@property(nonatomic) float a;
@property(nonatomic) float b;
@property(nonatomic) float c;
@property(nonatomic) float d;
@property(nonatomic) float e;
@property(nonatomic) float f;

-(ZG_SVGMatrix*) multiply:(ZG_SVGMatrix*) secondMatrix;
-(ZG_SVGMatrix*) inverse;
-(ZG_SVGMatrix*) translate:(float) x y:(float) y;
-(ZG_SVGMatrix*) scale:(float) scaleFactor;
-(ZG_SVGMatrix*) scaleNonUniform:(float) scaleFactorX scaleFactorY:(float) scaleFactorY;
-(ZG_SVGMatrix*) rotate:(float) angle;
-(ZG_SVGMatrix*) rotateFromVector:(float) x y:(float) y;
-(ZG_SVGMatrix*) flipX;
-(ZG_SVGMatrix*) flipY;
-(ZG_SVGMatrix*) skewX:(float) angle;
-(ZG_SVGMatrix*) skewY:(float) angle;

@end
