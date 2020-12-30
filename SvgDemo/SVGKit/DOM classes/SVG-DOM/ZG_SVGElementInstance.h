/*
 http://www.w3.org/TR/SVG/struct.html#InterfaceSVGElementInstance
 
 interface ZG_SVGElementInstance : EventTarget {
 readonly attribute ZG_SVGElement correspondingElement;
 readonly attribute ZG_SVGUseElement correspondingUseElement;
 readonly attribute ZG_SVGElementInstance parentNode;
 readonly attribute ZG_SVGElementInstanceList childNodes;
 readonly attribute ZG_SVGElementInstance firstChild;
 readonly attribute ZG_SVGElementInstance lastChild;
 readonly attribute ZG_SVGElementInstance previousSibling;
 readonly attribute ZG_SVGElementInstance nextSibling;
 */

#import "ZG_SVGElement.h"
#import "ZG_SVGElementInstanceList.h"

@class ZG_SVGUseElement;
#import "ZG_SVGUseElement.h"

/**
 ADDITIONAL IMPLEMENTATION NOTES:
 
 We make the two back-links into the SVG DOM Tree ("correspondingElement" and "correspondingUseElement") weak references to prevent
 a retain-cycle.
 
 If you delete parts of the original tree, but don't do anything to update your USE tags / elements, then ... the back-links will
 become nil. This seems the most rational, "what you would expect", behaviour.
 */

@interface ZG_SVGElementInstance : NSObject


/*The corresponding element to which this object is an instance. For example, if a ‘use’ element references a ‘rect’ element, then an ZG_SVGElementInstance is created, with its correspondingElement being the ZG_SVGRectElement object for the ‘rect’ element. */
@property(nonatomic, weak, readonly) ZG_SVGElement* correspondingElement;


/* The corresponding ‘use’ element to which this ZG_SVGElementInstance object belongs. When ‘use’ elements are nested (e.g., a ‘use’ references another ‘use’ which references a graphics element such as a ‘rect’), then the correspondingUseElement is the outermost ‘use’ (i.e., the one which indirectly references the ‘rect’, not the one with the direct reference). */
@property(nonatomic, weak, readonly) ZG_SVGUseElement* correspondingUseElement;

/* The parent of this ZG_SVGElementInstance within the instance tree. All ZG_SVGElementInstance objects have a parent except the ZG_SVGElementInstance which corresponds to the element which was directly referenced by the ‘use’ element, in which case parentNode is null. */
@property(nonatomic,strong, readonly) ZG_SVGElementInstance* parentNode;

/* An ZG_SVGElementInstanceList that contains all children of this ZG_SVGElementInstance within the instance tree. If there are no children, this is an ZG_SVGElementInstanceList containing no entries (i.e., an empty list). 
firstChild (readonly SVGElementInstance) */
@property(nonatomic,strong, readonly) ZG_SVGElementInstanceList* childNodes;


/* The first child of this ZG_SVGElementInstance within the instance tree. If there is no such ZG_SVGElementInstance, this returns null. */
@property(nonatomic,strong, readonly) ZG_SVGElementInstance* firstChild;

/* The last child of this ZG_SVGElementInstance within the instance tree. If there is no such ZG_SVGElementInstance, this returns null. */
@property(nonatomic,strong, readonly) ZG_SVGElementInstance* lastChild;

/* The ZG_SVGElementInstance immediately preceding this ZG_SVGElementInstance. If there is no such ZG_SVGElementInstance, this returns null.  */
@property(nonatomic,strong, readonly) ZG_SVGElementInstance* previousSibling;

/* The ZG_SVGElementInstance immediately following this ZG_SVGElementInstance. If there is no such ZG_SVGElementInstance, this returns null. */
@property(nonatomic,strong, readonly) ZG_SVGElementInstance* nextSibling;

@end
