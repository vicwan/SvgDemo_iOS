#import <Foundation/Foundation.h>
#import "ZG_SVGKDefine.h"

/** lightweight wrapper for UIColor so that we can draw with fill patterns */
@interface ZG_SVGKPattern : NSObject

+ (ZG_SVGKPattern*) patternWithColor:(UIColor*)color;
+ (ZG_SVGKPattern*) patternWithImage:(UIImage*)image;

@property (readwrite,nonatomic,strong) UIColor* color;

- (CGColorRef) CGColor;

@end
