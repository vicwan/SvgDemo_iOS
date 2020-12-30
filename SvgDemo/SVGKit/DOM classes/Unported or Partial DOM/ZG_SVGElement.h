/**
 ZG_SVGElement
 
 http://www.w3.org/TR/SVG/types.html#InterfaceSVGElement

 NB: "id" is illegal in Objective-C language, so we use "identifier" instead
 */
#import <QuartzCore/QuartzCore.h>

#import "ZG_Element.h"
#import "ZG_Node+Mutable.h"
#import "ZG_SVGStylable.h"
#import "ZG_SVGLength.h"

#define DEBUG_SVG_ELEMENT_PARSING 0

@class ZG_SVGSVGElement;
//obj-c's compiler sucks, and doesn't allow this line: #import "ZG_SVGSVGElement.h"

@interface ZG_SVGElement : ZG_Element <ZG_SVGStylable>

@property (nonatomic, readwrite, strong) NSString *identifier; // 'id' is reserved in Obj-C, so we have to break SVG Spec here, slightly
@property (nonatomic, strong) NSString* xmlbase;
/*!
 
 http://www.w3.org/TR/SVG/intro.html#TermSVGDocumentFragment
 
 SVG document fragment
 The XML document sub-tree which starts with an ‘svg’ element. An SVG document fragment can consist of a stand-alone SVG document, or a fragment of a parent XML document enclosed by an ‘svg’ element. When an ‘svg’ element is a descendant of another ‘svg’ element, there are two SVG document fragments, one for each ‘svg’ element. (One SVG document fragment is contained within another SVG document fragment.)
 */
@property (nonatomic, weak) ZG_SVGSVGElement* rootOfCurrentDocumentFragment;

/*! The viewport is set / re-set whenever an SVG node specifies a "width" (and optionally: a "height") attribute,
 assuming that SVG node is one of: svg, symbol, image, foreignobject
 
 The spec isn't clear what happens if this element redefines the viewport itself, but IMHO it implies that the
 viewportElement becomes a reference to "self" */
@property (nonatomic, weak) ZG_SVGElement* viewportElement;


#pragma mark - NON-STANDARD features of class (these are things that are NOT in the SVG spec, and should NOT be in SVGKit's implementation - they should be moved to a different class, although WE DO STILL NEED THESE in order to implement the spec, and to provide ZG_SVGKit features!)

/*! This is used when generating CALayer objects, to store the id of the ZG_SVGElement that created the CALayer */
#define kSVGElementIdentifier @"SVGElementIdentifier"


#pragma mark - SVG-spec supporting methods that aren't in the Spec itself

- (id)initWithLocalName:(NSString*) n attributes:(NSMutableDictionary*) attributes;
- (id)initWithQualifiedName:(NSString*) n inNameSpaceURI:(NSString*) nsURI attributes:(NSMutableDictionary*) attributes;

-(void) reCalculateAndSetViewportElementReferenceUsingFirstSVGAncestor:(ZG_SVGElement*) firstAncestor;

/**
 Convenience method for reading an attribute (SVG defines all as strings), converting it into an ZG_SVGLength object
 */
-(ZG_SVGLength*) getAttributeAsSVGLength:(NSString*) attributeName;

#pragma mark - CSS cascading special attributes. c.f. full list here: http://www.w3.org/TR/SVG/propidx.html

-(NSString*) cascadedValueForStylableProperty:(NSString*) stylableProperty;
-(NSString*) cascadedValueForStylableProperty:(NSString*) stylableProperty inherit:(BOOL)inherit;

@end
