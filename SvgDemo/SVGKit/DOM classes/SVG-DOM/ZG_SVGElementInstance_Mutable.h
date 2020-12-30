#import "ZG_SVGElementInstance.h"

@interface ZG_SVGElementInstance ()
@property(nonatomic,weak, readwrite) ZG_SVGElement* correspondingElement;
@property(nonatomic,weak, readwrite) ZG_SVGUseElement* correspondingUseElement;
@property(nonatomic,strong, readwrite) ZG_SVGElementInstance* parentNode;
@property(nonatomic,strong, readwrite) ZG_SVGElementInstanceList* childNodes;
@end
