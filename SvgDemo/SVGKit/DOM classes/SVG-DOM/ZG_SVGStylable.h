/**
 http://www.w3.org/TR/SVG/types.html#InterfaceSVGStylable
 
 interface SVGStylable {
 
 readonly attribute SVGAnimatedString className;
 readonly attribute ZG_CSSStyleDeclaration style;
 
 ZG_CSSValue getPresentationAttribute(in DOMString name);
 */
#import <Foundation/Foundation.h>

#import "ZG_CSSStyleDeclaration.h"
#import "ZG_CSSValue.h"

@protocol ZG_SVGStylable <NSObject>

@property(nonatomic,retain) /*FIXME: should be of type: SVGAnimatedString */ NSString* className;
@property(nonatomic,retain)	ZG_CSSStyleDeclaration* style;

-(ZG_CSSValue*) getPresentationAttribute:(NSString*) name;

@end
