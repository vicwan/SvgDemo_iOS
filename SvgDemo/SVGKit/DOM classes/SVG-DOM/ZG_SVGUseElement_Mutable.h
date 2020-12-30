#import "ZG_SVGUseElement.h"

@interface ZG_SVGUseElement ()
@property(nonatomic, strong, readwrite) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* x;
@property(nonatomic, strong, readwrite) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* y;
@property(nonatomic, strong, readwrite) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* width;
@property(nonatomic, strong, readwrite) /*FIXME: should be SVGAnimatedLength instead*/ ZG_SVGLength* height;
@property(nonatomic, strong, readwrite) ZG_SVGElementInstance* instanceRoot;
@property(nonatomic, strong, readwrite) ZG_SVGElementInstance* animatedInstanceRoot;

@end
