/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/stylesheets.html#StyleSheets-StyleSheetList
 
 interface ZG_StyleSheetList {
 readonly attribute unsigned long    length;
 ZG_StyleSheet         item(in unsigned long index);
 */

#import <Foundation/Foundation.h>

#import "ZG_StyleSheet.h"

@interface ZG_StyleSheetList : NSObject

@property(nonatomic,readonly) unsigned long length;

-(ZG_StyleSheet*) item:(unsigned long) index;

@end
