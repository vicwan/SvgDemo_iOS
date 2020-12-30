/**
 
 */
#import "ZG_SVGKSource.h"

@interface ZG_SVGKSourceNSData : ZG_SVGKSource

@property (nonatomic, strong) NSData* rawData;
@property (nonatomic, strong) NSURL* effectiveURL;

+ (ZG_SVGKSource*)sourceFromData:(NSData*)data URLForRelativeLinks:(NSURL*) url;

@end
