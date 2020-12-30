/**
 Parses the "<defs>" and "<use>" tags in SVG files.
 
 NB: relies upon other parsers to parse the actual CONTENTS of a "defs" or "use" tag
 */
#import <Foundation/Foundation.h>
#import "ZG_SVGKParserExtension.h"

@interface ZG_SVGKParserDefsAndUse : NSObject <SVGKParserExtension>

@end
