/**
 Makes the writable properties all package-private, effectively
 */

#import "ZG_NodeList.h"

@interface ZG_NodeList()

@property(nonatomic,strong) NSMutableArray* internalArray;

@end
