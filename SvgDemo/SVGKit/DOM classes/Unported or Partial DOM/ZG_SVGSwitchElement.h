

#import "ZG_SVGElement.h"

#import "ZG_ConverterSVGToCALayer.h"

@interface ZG_SVGSwitchElement : ZG_SVGElement <ZG_ConverterSVGToCALayer>

@property (nonatomic, readonly, strong) ZG_NodeList * visibleChildNodes;

@end
