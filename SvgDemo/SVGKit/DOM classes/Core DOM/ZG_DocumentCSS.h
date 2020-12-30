/**
 http://www.w3.org/TR/2000/REC-DOM-Level-2-Style-20001113/css.html#CSS-DocumentCSS
 
 interface DocumentCSS : stylesheets::DocumentStyle {
 ZG_CSSStyleDeclaration getOverrideStyle(in ZG_Element elt,
 in DOMString pseudoElt);
 */
#import <Foundation/Foundation.h>
#import "ZG_DocumentStyle.h"

#import "ZG_CSSStyleDeclaration.h"

@class ZG_Element;

@protocol DocumentCSS <DocumentStyle>

-(ZG_CSSStyleDeclaration *)getOverrideStyle:(ZG_Element *)element pseudoElt:(NSString *)pseudoElt;

@end
