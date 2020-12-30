/*!
 http://www.w3.org/TR/SVG/coords.html#InterfaceSVGTransform
 
 // Transform Types
 const unsigned short SVG_TRANSFORM_UNKNOWN = 0;
 const unsigned short SVG_TRANSFORM_MATRIX = 1;
 const unsigned short SVG_TRANSFORM_TRANSLATE = 2;
 const unsigned short SVG_TRANSFORM_SCALE = 3;
 const unsigned short SVG_TRANSFORM_ROTATE = 4;
 const unsigned short SVG_TRANSFORM_SKEWX = 5;
 const unsigned short SVG_TRANSFORM_SKEWY = 6;
 
 readonly attribute unsigned short type;
 readonly attribute ZG_SVGMatrix matrix;
 readonly attribute float angle;
 
 void setMatrix(in ZG_SVGMatrix matrix) raises(DOMException);
 void setTranslate(in float tx, in float ty) raises(DOMException);
 void setScale(in float sx, in float sy) raises(DOMException);
 void setRotate(in float angle, in float cx, in float cy) raises(DOMException);
 void setSkewX(in float angle) raises(DOMException);
 void setSkewY(in float angle) raises(DOMException);
*/
 
#import <Foundation/Foundation.h>

#import "ZG_SVGMatrix.h"

@interface ZG_SVGTransform : NSObject

/*! Transform Types */
typedef enum ZG_SVGKTransformType
{
	ZG_SVG_TRANSFORM_UNKNOWN = 0,
	ZG_SVG_TRANSFORM_MATRIX = 1,
	ZG_SVG_TRANSFORM_TRANSLATE = 2,
	ZG_SVG_TRANSFORM_SCALE = 3,
	ZG_SVG_TRANSFORM_ROTATE = 4,
	ZG_SVG_TRANSFORM_SKEWX = 5,
	ZG_SVG_TRANSFORM_SKEWY = 6
} ZG_SVGKTransformType;

@property(nonatomic) ZG_SVGKTransformType type;
@property(nonatomic,strong) ZG_SVGMatrix* matrix;
@property(nonatomic,readonly) float angle;

-(void) setMatrix:(ZG_SVGMatrix*) matrix;
-(void) setTranslate:(float) tx ty:(float) ty;
-(void) setScale:(float) sx sy:(float) sy;
-(void) setRotate:(float) angle cx:(float) cx cy:(float) cy;
-(void) setSkewX:(float) angle;
-(void) setSkewY:(float) angle;

@end
