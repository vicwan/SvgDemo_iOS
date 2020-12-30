/**
 
 */
#import "ZG_SVGKSource.h"

@interface ZG_SVGKSourceURL : ZG_SVGKSource

@property (nonatomic, strong) NSURL* URL;

+ (ZG_SVGKSource*)sourceFromURL:(NSURL*)u;

@end
