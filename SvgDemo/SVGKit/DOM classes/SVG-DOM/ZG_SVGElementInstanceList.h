/*
 http://www.w3.org/TR/SVG/struct.html#InterfaceSVGElementInstanceList
 
 interface ZG_SVGElementInstanceList {
 
 readonly attribute unsigned long length;
 
 ZG_SVGElementInstance item(in unsigned long index);
*/

#import "ZG_SVGElement.h"

@class ZG_SVGElementInstance;

@interface ZG_SVGElementInstanceList : ZG_SVGElement

@property(nonatomic, readonly) unsigned long length;

-(ZG_SVGElementInstance*) item:(unsigned long) index;
						
@end
