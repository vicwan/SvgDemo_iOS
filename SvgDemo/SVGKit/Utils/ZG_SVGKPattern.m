#import "ZG_SVGKPattern.h"

@implementation ZG_SVGKPattern

@synthesize color;

+ (ZG_SVGKPattern *)patternWithColor:(UIColor *)color
{
    ZG_SVGKPattern* p = [[ZG_SVGKPattern alloc] init];
    p.color = color;
    return p;
}

+ (ZG_SVGKPattern*)patternWithImage:(UIImage*)image
{
    UIColor* patternImage = [UIColor colorWithPatternImage:image];
    return [self patternWithColor:patternImage];
}

- (CGColorRef)CGColor
{
    return [self.color CGColor];
}

@end
