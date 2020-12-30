/**
 Reports detailed information from an attempted run of the SVG Parser
 */
#import <Foundation/Foundation.h>

@class ZG_SVGSVGElement, ZG_SVGDocument;
#import "ZG_SVGSVGElement.h"
#import "ZG_SVGDocument.h"

@protocol SVGKParserExtension;
#import "ZG_SVGKParserExtension.h"

@interface ZG_SVGKParseResult : NSObject

@property(nonatomic, strong) NSMutableArray* warnings, * errorsRecoverable, * errorsFatal;
@property(nonatomic) BOOL libXMLFailed;
/** 0.0 = no parsing done yet, 0.x = partially parsed, 1.0 = parse complete (no fatal errors) */
@property(nonatomic) double parseProgressFractionApproximate;

@property(nonatomic,strong) ZG_SVGSVGElement* rootOfSVGTree; /**< both are needed, see spec */
@property(nonatomic,strong) ZG_SVGDocument* parsedDocument; /**< both are needed, see spec */

@property(nonatomic,strong) NSMutableDictionary* namespacesEncountered; /**< maps "prefix" to "uri" */

-(void) addSourceError:(NSError*) fatalError;
-(void) addParseWarning:(NSError*) warning;
-(void) addParseErrorRecoverable:(NSError*) recoverableError;
-(void) addParseErrorFatal:(NSError*) fatalError;
-(void) addSAXError:(NSError*) saxError;

#if ENABLE_PARSER_EXTENSIONS_CUSTOM_DATA
/*! Each SVGKParserExtension can optionally save extra data here */
@property(nonatomic,retain) NSMutableDictionary* extensionsData;

-(NSMutableDictionary*) dictionaryForParserExtension:(NSObject<SVGKParserExtension>*) extension;
#endif

@end
