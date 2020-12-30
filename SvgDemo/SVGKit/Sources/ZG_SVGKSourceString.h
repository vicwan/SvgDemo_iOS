/**
 
 */
#import "ZG_SVGKSource.h"

@interface ZG_SVGKSourceString : ZG_SVGKSource

@property (nonatomic, strong) NSString* rawString;

+ (ZG_SVGKSource*)sourceFromContentsOfString:(NSString*)rawString;

@end
