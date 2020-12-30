#import "ZG_SVGSVGElement.h"

@interface ZG_SVGSVGElement ()

@property (nonatomic, strong, readwrite) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* x;
@property (nonatomic, strong, readwrite) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* y;
@property (nonatomic, strong, readwrite) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* width;
@property (nonatomic, strong, readwrite) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* height;
@property (nonatomic, strong, readwrite) NSString* contentScriptType;
@property (nonatomic, strong, readwrite) NSString* contentStyleType;
@property (nonatomic, readwrite) ZG_SVGRect viewport;
@property (nonatomic, readwrite) float pixelUnitToMillimeterX;
@property (nonatomic, readwrite) float pixelUnitToMillimeterY;
@property (nonatomic, readwrite) float screenPixelToMillimeterX;
@property (nonatomic, readwrite) float screenPixelToMillimeterY;
@property (nonatomic, readwrite) BOOL useCurrentView;
@property (nonatomic, strong, readwrite) ZG_SVGViewSpec* currentView;
@property (nonatomic, readwrite) float currentScale;
@property (nonatomic, strong, readwrite) ZG_SVGPoint* currentTranslate;

@end
