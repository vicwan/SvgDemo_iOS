#import "ZG_CSSRuleList.h"
#import "ZG_CSSRuleList+Mutable.h"

@implementation ZG_CSSRuleList

@synthesize internalArray;


- (id)init
{
    self = [super init];
    if (self) {
        self.internalArray = [NSMutableArray array];
    }
    return self;
}

-(unsigned long)length
{
	return self.internalArray.count;
}

-(ZG_CSSRule *)item:(unsigned long)index
{
	return [self.internalArray objectAtIndex:index];
}

-(NSString *)description
{
	return [NSString stringWithFormat:@"CSSRuleList: array(%@)", self.internalArray];
}

@end
