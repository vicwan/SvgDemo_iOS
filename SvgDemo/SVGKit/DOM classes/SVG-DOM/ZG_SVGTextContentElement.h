/**
 http://www.w3.org/TR/2011/REC-SVG11-20110816/text.html#InterfaceSVGTextContentElement
 
 interface ZG_SVGTextContentElement : ZG_SVGElement,
 SVGTests,
 SVGLangSpace,
 SVGExternalResourcesRequired,
 SVGStylable {
 
 // lengthAdjust Types
 const unsigned short LENGTHADJUST_UNKNOWN = 0;
 const unsigned short LENGTHADJUST_SPACING = 1;
 const unsigned short LENGTHADJUST_SPACINGANDGLYPHS = 2;
 
 readonly attribute SVGAnimatedLength textLength;
 readonly attribute SVGAnimatedEnumeration lengthAdjust;
 
 long getNumberOfChars();
 float getComputedTextLength();
 float getSubStringLength(in unsigned long charnum, in unsigned long nchars) raises(DOMException);
 ZG_SVGPoint getStartPositionOfChar(in unsigned long charnum) raises(DOMException);
 ZG_SVGPoint getEndPositionOfChar(in unsigned long charnum) raises(DOMException);
 ZG_SVGRect getExtentOfChar(in unsigned long charnum) raises(DOMException);
 float getRotationOfChar(in unsigned long charnum) raises(DOMException);
 long getCharNumAtPosition(in ZG_SVGPoint point);
 void selectSubString(in unsigned long charnum, in unsigned long nchars) raises(DOMException);
 */
#import "ZG_SVGElement.h"
#import "ZG_SVGStylable.h"
#import "ZG_SVGLength.h"

typedef enum ZG_SVGLengthAdjust
{
	// lengthAdjust Types
	ZG_SVGLengthAdjustUnknown = 0,
	ZG_SVGLengthAdjustSpacing = 1,
	ZG_SVGLengthAdjustSpacingAndGlyphs = 2
} ZG_SVGLengthAdjust;

@interface ZG_SVGTextContentElement : ZG_SVGElement <ZG_SVGStylable>
	
@property(weak, nonatomic,readonly) ZG_SVGLength* /* FIXMED: should be SVGAnimatedLength*/ textLength;
/**FIXME: missing:	readonly attribute SVGAnimatedEnumeration lengthAdjust;*/

/**FIXME: missing:	
	long getNumberOfChars();
	float getComputedTextLength();
	float getSubStringLength(in unsigned long charnum, in unsigned long nchars) raises(DOMException);
	ZG_SVGPoint getStartPositionOfChar(in unsigned long charnum) raises(DOMException);
	ZG_SVGPoint getEndPositionOfChar(in unsigned long charnum) raises(DOMException);
	ZG_SVGRect getExtentOfChar(in unsigned long charnum) raises(DOMException);
	float getRotationOfChar(in unsigned long charnum) raises(DOMException);
	long getCharNumAtPosition(in ZG_SVGPoint point);
	void selectSubString(in unsigned long charnum, in unsigned long nchars) raises(DOMException);
 */
@end
