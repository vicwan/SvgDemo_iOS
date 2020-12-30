/**
 
 */
#import "ZG_SVGKSource.h"

@interface ZG_SVGKSourceLocalFile : ZG_SVGKSource

@property (nonatomic, strong) NSString* filePath;
@property (nonatomic, readonly) BOOL wasRelative;

+ (ZG_SVGKSourceLocalFile*)sourceFromFilename:(NSString*)p;

+ (ZG_SVGKSourceLocalFile *)internalSourceAnywhereInBundleUsingName:(NSString *)name;
+ (ZG_SVGKSourceLocalFile *)internalSourceAnywhereInBundle:(NSBundle *)bundle usingName:(NSString *)name;

@end
