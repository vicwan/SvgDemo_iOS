/**
 ZG_SVGSVGElement.m
 
 Represents the "<svg>" tag in an SVG file
 
 http://www.w3.org/TR/SVG/struct.html#InterfaceSVGSVGElement
 
 readonly attribute SVGAnimatedLength x;
 readonly attribute SVGAnimatedLength y;
 readonly attribute SVGAnimatedLength width;
 readonly attribute SVGAnimatedLength height;
 attribute DOMString contentScriptType setraises(DOMException);
 attribute DOMString contentStyleType setraises(DOMException);
 readonly attribute ZG_SVGRect viewport;
 readonly attribute float pixelUnitToMillimeterX;
 readonly attribute float pixelUnitToMillimeterY;
 readonly attribute float screenPixelToMillimeterX;
 readonly attribute float screenPixelToMillimeterY;
 readonly attribute boolean useCurrentView;
 readonly attribute SVGViewSpec currentView;
 attribute float currentScale;
 readonly attribute ZG_SVGPoint currentTranslate;
 
 unsigned long suspendRedraw(in unsigned long maxWaitMilliseconds);
 void unsuspendRedraw(in unsigned long suspendHandleID);
 void unsuspendRedrawAll();
 void forceRedraw();
 void pauseAnimations();
 void unpauseAnimations();
 boolean animationsPaused();
 float getCurrentTime();
 void setCurrentTime(in float seconds);
 ZG_NodeList getIntersectionList(in ZG_SVGRect rect, in ZG_SVGElement referenceElement);
 ZG_NodeList getEnclosureList(in ZG_SVGRect rect, in ZG_SVGElement referenceElement);
 boolean checkIntersection(in ZG_SVGElement element, in ZG_SVGRect rect);
 boolean checkEnclosure(in ZG_SVGElement element, in ZG_SVGRect rect);
 void deselectAll();
 ZG_SVGNumber createSVGNumber();
 ZG_SVGLength createSVGLength();
 ZG_SVGAngle createSVGAngle();
 ZG_SVGPoint createSVGPoint();
 ZG_SVGMatrix createSVGMatrix();
 ZG_SVGRect createSVGRect();
 ZG_SVGTransform createSVGTransform();
 ZG_SVGTransform createSVGTransformFromMatrix(in ZG_SVGMatrix matrix);
 ZG_Element getElementById(in DOMString elementId);
 */

#import "ZG_DocumentCSS.h"
#import "ZG_SVGFitToViewBox.h"

#import "ZG_SVGElement.h"
#import "ZG_SVGViewSpec.h"

#pragma mark - the SVG* types (SVGLength, SVGNumber, etc)
#import "ZG_SVGAngle.h"
#import "ZG_SVGLength.h"
#import "ZG_SVGNumber.h"
#import "ZG_SVGPoint.h"
#import "ZG_SVGRect.h"
#import "ZG_SVGTransform.h"

#pragma mark - a few raw DOM imports are required for SVG DOM, but not many
#import "ZG_Element.h"
#import "ZG_NodeList.h"

#import "ZG_ConverterSVGToCALayer.h"
#import "ZG_SVGKSource.h"

@interface ZG_SVGSVGElement : ZG_SVGElement < DocumentCSS, ZG_SVGFitToViewBox, /* FIXME: refactor and delete this, it's in violation of the spec: */ ZG_ConverterSVGToCALayer >



@property (nonatomic, strong, readonly) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* x;
@property (nonatomic, strong, readonly) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* y;
@property (nonatomic, strong, readonly) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* width;
@property (nonatomic, strong, readonly) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* height;
@property (nonatomic, strong, readonly) NSString* contentScriptType;
@property (nonatomic, strong, readonly) NSString* contentStyleType;

/**
 "The position and size of the viewport (implicit or explicit) that corresponds to this ‘svg’ element. When the user agent is actually rendering the content, then the position and size values represent the actual values when rendering. The position and size values are unitless values in the coordinate system of the parent element. If no parent element exists (i.e., ‘svg’ element represents the root of the document tree), if this SVG document is embedded as part of another document (e.g., via the HTML ‘object’ element), then the position and size are unitless values in the coordinate system of the parent document. (If the parent uses CSS or XSL layout, then unitless values represent pixel units for the current CSS or XSL viewport, as described in the CSS2 specification.) If the parent element does not have a coordinate system, then the user agent should provide reasonable default values for this attribute."
 */
@property (nonatomic, readonly) ZG_SVGRect viewport;
@property (nonatomic, readonly) float pixelUnitToMillimeterX;
@property (nonatomic, readonly) float pixelUnitToMillimeterY;
@property (nonatomic, readonly) float screenPixelToMillimeterX;
@property (nonatomic, readonly) float screenPixelToMillimeterY;
@property (nonatomic, readonly) BOOL useCurrentView;
@property (nonatomic, strong, readonly) ZG_SVGViewSpec* currentView;
@property (nonatomic, readonly) float currentScale;
@property (nonatomic, strong, readonly) ZG_SVGPoint* currentTranslate;
@property (nonatomic, strong, readwrite) ZG_SVGKSource *source;

-(long) suspendRedraw:(long) maxWaitMilliseconds;
-(void) unsuspendRedraw:(long) suspendHandleID;
-(void) unsuspendRedrawAll;
-(void) forceRedraw;
-(void) pauseAnimations;
-(void) unpauseAnimations;
-(BOOL) animationsPaused;
-(float) getCurrentTime;
-(void) setCurrentTime:(float) seconds;
-(ZG_NodeList*) getIntersectionList:(ZG_SVGRect) rect referenceElement:(ZG_SVGElement*) referenceElement;
-(ZG_NodeList*) getEnclosureList:(ZG_SVGRect) rect referenceElement:(ZG_SVGElement*) referenceElement;
-(BOOL) checkIntersection:(ZG_SVGElement*) element rect:(ZG_SVGRect) rect;
-(BOOL) checkEnclosure:(ZG_SVGElement*) element rect:(ZG_SVGRect) rect;
-(void) deselectAll;
-(ZG_SVGNumber) createSVGNumber;
-(ZG_SVGLength*) createSVGLength __attribute__((ns_returns_retained));
-(ZG_SVGAngle*) createSVGAngle;
-(ZG_SVGPoint*) createSVGPoint;
-(ZG_SVGMatrix*) createSVGMatrix;
-(ZG_SVGRect) createSVGRect;
-(ZG_SVGTransform*) createSVGTransform;
-(ZG_SVGTransform*) createSVGTransformFromMatrix:(ZG_SVGMatrix*) matrix;
-(ZG_Element*) getElementById:(NSString*) elementId;

#pragma mark - below here VIOLATES THE STANDARD, but needs to be CAREFULLY merged with spec

- (ZG_SVGElement *)findFirstElementOfClass:(Class)classParameter; /**< temporary convenience method until ZG_SVGDocument support is complete */

#pragma mark - elements REQUIRED to implement the spec but not included in SVG Spec due to bugs in the spec writing!

@property(nonatomic,readonly) ZG_SVGRect requestedViewport;

/** Required by the spec whenever someone specifies a width and height that disagree with the viewbox they also specified */
@property(readonly) double aspectRatioFromWidthPerHeight;
/** Required by the spec whenever someone specifies a width and height that disagree with the viewbox they also specified */
@property(readonly) double aspectRatioFromViewBox;

@end
