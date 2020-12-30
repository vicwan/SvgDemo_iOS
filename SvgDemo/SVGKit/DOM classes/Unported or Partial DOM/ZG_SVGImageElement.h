#import <Foundation/Foundation.h>

#import "ZG_SVGElement.h"
#import "ZG_SVGTransformable.h"
#import "ZG_SVGFitToViewBox.h"

#import "ZG_SVGElement_ForParser.h" // to resolve Xcode circular dependencies; in long term, parsing SHOULD NOT HAPPEN inside any class whose name starts "SVG" (because those are reserved classes for the SVG Spec)

@interface ZG_SVGImageElement : ZG_SVGElement <ZG_SVGTransformable, ZG_SVGStylable, ZG_ConverterSVGToCALayer, ZG_SVGFitToViewBox>

@property (nonatomic, readonly) CGFloat x;
@property (nonatomic, readonly) CGFloat y;
@property (nonatomic, readonly) CGFloat width;
@property (nonatomic, readonly) CGFloat height;

@property (nonatomic, strong, readonly) NSString *href;

@end
