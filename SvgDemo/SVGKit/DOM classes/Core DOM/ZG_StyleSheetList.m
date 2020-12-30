#import "ZG_StyleSheetList.h"
#import "ZG_StyleSheetList+Mutable.h"

@implementation ZG_StyleSheetList

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

-(ZG_StyleSheet*) item:(unsigned long) index
{
	return [self.internalArray objectAtIndex:index];
}

@end
