#import "ZG_SVGElementInstanceList.h"
#import "ZG_SVGElementInstanceList_Internal.h"

@implementation ZG_SVGElementInstanceList
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
	return [self.internalArray count];
}

-(ZG_SVGElementInstance*) item:(unsigned long) index
{
	if( index >= [self.internalArray count] )
		return nil;
	
	return [self.internalArray objectAtIndex:index];
}

@end
