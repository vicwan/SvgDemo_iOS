/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/stylesheets.html#StyleSheets-StyleSheet
 
 interface ZG_StyleSheet {
 readonly attribute DOMString        type;
 attribute boolean          disabled;
 readonly attribute ZG_Node             ownerNode;
 readonly attribute ZG_StyleSheet       parentStyleSheet;
 readonly attribute DOMString        href;
 readonly attribute DOMString        title;
 readonly attribute ZG_MediaList        media;
 */

#import <Foundation/Foundation.h>

@class ZG_Node;
@class ZG_MediaList;

@interface ZG_StyleSheet : NSObject

@property(nonatomic,strong) NSString* type;
@property(nonatomic) BOOL disabled;
@property(nonatomic,strong) ZG_Node* ownerNode;
@property(nonatomic,strong) ZG_StyleSheet* parentStyleSheet;
@property(nonatomic,strong) NSString* href;
@property(nonatomic,strong) NSString* title;
@property(nonatomic,strong) ZG_MediaList* media;

@end
