/**
 Makes the writable properties all package-private, effectively
 */

#import "ZG_SVGDocument.h"

@interface ZG_SVGDocument ()
@property (nonatomic, strong, readwrite) NSString* title;
@property (nonatomic, strong, readwrite) NSString* referrer;
@property (nonatomic, strong, readwrite) NSString* domain;
@property (nonatomic, strong, readwrite) NSString* URL;
@property (nonatomic, strong, readwrite) ZG_SVGSVGElement* rootElement;
@end
