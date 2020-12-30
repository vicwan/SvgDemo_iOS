#import "ZG_CSSValueList.h"
#import "ZG_CSSValue_ForSubclasses.h"
#import "ZG_SVGKDefine_Private.h"

@interface ZG_CSSValueList()

@property(nonatomic,strong) NSArray* internalArray;

@end

@implementation ZG_CSSValueList

@synthesize internalArray;


- (id)init
{
    self = [super initWithUnitType:ZG_CSS_VALUE_LIST];
    if (self) {
        self.internalArray = [NSArray array];
    }
    return self;
}

-(unsigned long)length
{
	return self.internalArray.count;
}

-(ZG_CSSValue*) item:(unsigned long) index
{
	return [self.internalArray objectAtIndex:index];
}

#pragma mark - non DOM spec methods needed to implement Objective-C code for this class

-(void)setCssText:(NSString *)newCssText
{
	_cssText = newCssText;
	
	/** the css text value has been set, so we need to split the elements up and save them in the internal array */
	SVGKitLogVerbose(@"[%@] received new CSS ZG_Text, need to split this and save as ZG_CSSValue instances: %@", [self class], _cssText);
	
	self.internalArray = [_cssText componentsSeparatedByString:@" "];
}

@end
