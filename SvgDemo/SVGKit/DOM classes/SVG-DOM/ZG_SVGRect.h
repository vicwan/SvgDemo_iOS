/*
 http://www.w3.org/TR/SVG/types.html#InterfaceSVGRect
 
 interface ZG_SVGRect {
 attribute float x setraises(DOMException);
 attribute float y setraises(DOMException);
 attribute float width setraises(DOMException);
 attribute float height setraises(DOMException);
 };
 */
#import <Foundation/Foundation.h>

#import <CoreGraphics/CoreGraphics.h>

typedef struct
{
	float x;
	float y;
	float width;
	float height;
} ZG_SVGRect;

#pragma mark - utility methods that are NOT in the SVG Spec, bu which we need to implement it in ObjectiveC

/** C has no way of detecting if an ZG_SVGRect is deliberately 0 width (has special meaning in SVG), or accidentally (because it was
 never initialized).
 
 Unfortunately, the SVG Spec authors defined "uninitialized" and "values of zero" to mean differnet things, so we MUST preserve
 that difference! */
ZG_SVGRect ZG_SVGRectUninitialized(void);

/** c.f. note about SVGRectUninitialized() -- this method checks if a Rect is identical to the output of that method */
BOOL ZG_SVGRectIsInitialized( ZG_SVGRect rect );

ZG_SVGRect ZG_SVGRectMake( float x, float y, float width, float height );

/** Convenience method to convert to ObjectiveC's kind of rect */
CGRect ZG_CGRectFromSVGRect( ZG_SVGRect rect );

/** Convenience method to convert to ObjectiveC's kind of size - ONLY the width and height of this rect */
CGSize ZG_CGSizeFromSVGRect( ZG_SVGRect rect );

NSString * _Nonnull ZG_NSStringFromSVGRect( ZG_SVGRect rect );
