/**
 
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/stylesheets.html#StyleSheets-StyleSheet-DocumentStyle
 
 interface DocumentStyle {
 readonly attribute ZG_StyleSheetList   styleSheets;
 */

#import <Foundation/Foundation.h>

#import "ZG_StyleSheetList.h"

@protocol DocumentStyle <NSObject>

@property(nonatomic,retain) ZG_StyleSheetList* styleSheets;

@end
