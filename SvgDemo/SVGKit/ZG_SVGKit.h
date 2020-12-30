/*!
 
 ZG_SVGKit - https://github.com/SVGKit/SVGKit
 
 THE MOST IMPORTANT ELEMENTS YOU'LL INTERACT WITH:
 
 1. ZG_SVGKImage = contains most of the convenience methods for loading / reading / displaying SVG files
 2. ZG_SVGKImageView = the easiest / fastest way to display an ZG_SVGKImage on screen
 3. ZG_SVGKLayer = the low-level way of getting an SVG as a bunch of layers
 
 ZG_SVGKImage makes heavy use of the following classes - you'll often use these classes (most of them given to you by an SVGKImage):
 
 4. ZG_SVGKSource = the "file" or "URL" for loading the SVG data
 5. ZG_SVGKParseResult = contains the parsed SVG file AND/OR the list of errors during parsing
 
 */

#import "ZG_SVGKDefine.h"


// MARK: - Framework Header File Content

@interface ZG_SVGKit : NSObject

+ (void) enableLogging;

@end

//! Project version number for SVGKitFramework-iOS.
FOUNDATION_EXPORT double SVGKitFramework_VersionNumber;

//! Project version string for SVGKitFramework-iOS.
FOUNDATION_EXPORT const unsigned char SVGKitFramework_VersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <SVGKitFramework_iOS/PublicHeader.h>

// Core DOM
#import "ZG_AppleSucksDOMImplementation.h"
#import "ZG_Attr.h"
#import "ZG_CDATASection.h"
#import "ZG_CharacterData.h"
#import "ZG_Comment.h"
#import "ZG_CSSStyleDeclaration.h"
#import "ZG_CSSRule.h"
#import "ZG_CSSStyleSheet.h"
#import "ZG_CSSStyleRule.h"
#import "ZG_CSSRuleList.h"
#import "ZG_CSSRuleList+Mutable.h"
#import "ZG_CSSPrimitiveValue.h"
#import "ZG_CSSPrimitiveValue_ConfigurablePixelsPerInch.h"
#import "ZG_CSSValueList.h"
#import "ZG_CSSValue_ForSubclasses.h"
#import "ZG_CSSValue.h"
#import "ZG_Document+Mutable.h"
#import "ZG_Document.h"
#import "ZG_DocumentCSS.h"
#import "ZG_DocumentStyle.h"
#import "ZG_StyleSheetList+Mutable.h"
#import "ZG_StyleSheetList.h"
#import "ZG_StyleSheet.h"
#import "ZG_MediaList.h"
#import "ZG_DocumentFragment.h"
#import "ZG_DocumentType.h"
#import "ZG_DOMHelperUtilities.h"
#import "ZG_Element.h"
#import "ZG_EntityReference.h"
#import "ZG_NamedNodeMap.h"
#import "ZG_NamedNodeMap_Iterable.h"
#import "ZG_Node+Mutable.h"
#import "ZG_Node.h"
#import "ZG_NodeList+Mutable.h"
#import "ZG_NodeList.h"
#import "ZG_ProcessingInstruction.h"
#import "ZG_Text.h"
#import "ZG_DOMGlobalSettings.h"

// SVG DOM
#import "ZG_SVGAngle.h"
#import "ZG_SVGAnimatedPreserveAspectRatio.h"
#import "ZG_SVGDefsElement.h"
#import "ZG_SVGDocument.h"
#import "ZG_SVGDocument_Mutable.h"
#import "ZG_SVGElementInstance.h"
#import "ZG_SVGElementInstance_Mutable.h"
#import "ZG_SVGElementInstanceList.h"
#import "ZG_SVGElementInstanceList_Internal.h"
#import "ZG_SVGGElement.h"
#import "ZG_SVGStylable.h"
#import "ZG_SVGLength.h"
#import "ZG_SVGMatrix.h"
#import "ZG_SVGNumber.h"
#import "ZG_SVGPoint.h"
#import "ZG_SVGPreserveAspectRatio.h"
#import "ZG_SVGRect.h"
#import "ZG_SVGSVGElement_Mutable.h"
#import "ZG_SVGTransform.h"
#import "ZG_SVGUseElement.h"
#import "ZG_SVGUseElement_Mutable.h"
#import "ZG_SVGViewSpec.h"
#import "ZG_SVGHelperUtilities.h"
#import "ZG_SVGTransformable.h"
#import "ZG_SVGFitToViewBox.h"
#import "ZG_SVGTextPositioningElement.h"
#import "ZG_SVGTextContentElement.h"
#import "ZG_SVGTextPositioningElement_Mutable.h"
#import "ZG_ConverterSVGToCALayer.h"
#import "ZG_SVGGradientElement.h"
#import "ZG_SVGGradientStop.h"
#import "ZG_SVGLinearGradientElement.h"
#import "ZG_SVGRadialGradientElement.h"
#import "ZG_SVGStyleCatcher.h"
#import "ZG_SVGStyleElement.h"
#import "ZG_SVGCircleElement.h"
#import "ZG_SVGDescriptionElement.h"
#import "ZG_SVGElement.h"
#import "ZG_SVGElement_ForParser.h"
#import "ZG_SVGEllipseElement.h"
#import "ZG_SVGGroupElement.h"
#import "ZG_SVGImageElement.h"
#import "ZG_SVGLineElement.h"
#import "ZG_SVGPathElement.h"
#import "ZG_SVGPolygonElement.h"
#import "ZG_SVGPolylineElement.h"
#import "ZG_SVGRectElement.h"
#import "ZG_BaseClassForAllSVGBasicShapes.h"
#import "ZG_BaseClassForAllSVGBasicShapes_ForSubclasses.h"
#import "ZG_SVGSVGElement.h"
#import "ZG_SVGTextElement.h"
#import "ZG_SVGTitleElement.h"
#import "ZG_SVGSwitchElement.h"
#import "ZG_SVGClipPathElement.h"
#import "ZG_TinySVGTextAreaElement.h"

// Parser

#import "ZG_SVGKImage+CGContext.h"
#import "ZG_SVGKExporterNSData.h"
#if SVGKIT_MAC
#import "ZG_SVGKExporterNSImage.h"
#else
#import "ZG_SVGKExporterUIImage.h"
#endif
#import "ZG_SVGKSourceLocalFile.h"
#import "ZG_SVGKSourceString.h"
#import "ZG_SVGKSourceURL.h"
#import "ZG_SVGKParserDefsAndUse.h"
#import "ZG_SVGKParserDOM.h"
#import "ZG_SVGKParserGradient.h"
#import "ZG_SVGKParserPatternsAndGradients.h"
#import "ZG_SVGKParserStyles.h"
#import "ZG_SVGKParserSVG.h"
#import "ZG_SVGKParser.h"
#import "ZG_SVGKParseResult.h"
#import "ZG_SVGKParserExtension.h"
#import "ZG_SVGKPointsAndPathsParser.h"
#import "CALayer+RecursiveClone.h"
#import "ZG_SVGGradientLayer.h"
#import "ZG_SVGTextLayer.h"
#import "ZG_CALayerWithChildHitTest.h"
#import "ZG_CAShapeLayerWithHitTest.h"
#import "ZG_CGPathAdditions.h"
#import "ZG_SVGKLayer.h"
#import "ZG_SVGKImage.h"
#import "ZG_SVGKSource.h"
#import "NSCharacterSet+SVGKExtensions.h"
#import "ZG_SVGKFastImageView.h"
#import "ZG_SVGKImageView.h"
#import "ZG_SVGKLayeredImageView.h"
#import "ZG_SVGKPattern.h"
#import "ZG_SVGUtils.h"
#if SVGKIT_MAC
#import "ZG_SVGKImageRep.h"
#endif
#import "NSData+NSInputStream.h"
#import "ZG_SVGKSourceNSData.h"
#import "ZG_SVGKInlineResource.h"
