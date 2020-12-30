
#import "ZG_SVGSwitchElement.h"
#import "ZG_CALayerWithChildHitTest.h"
#import "ZG_SVGHelperUtilities.h"
#import "ZG_NodeList+Mutable.h"

@implementation ZG_SVGSwitchElement

@synthesize visibleChildNodes = _visibleChildNodes;


- (CALayer *) newLayer
{
    CALayer* _layer = [ZG_CALayerWithChildHitTest layer];
    
    [ZG_SVGHelperUtilities configureCALayer:_layer usingElement:self];
    
    return _layer;
}

- (ZG_NodeList *)visibleChildNodes
{
    if (_visibleChildNodes)
        return _visibleChildNodes;
    
    _visibleChildNodes = [[ZG_NodeList alloc] init];
    
    NSString* localLanguage = [[NSLocale preferredLanguages] firstObject];
    
    for ( ZG_SVGElement<ZG_ConverterSVGToCALayer> *child in self.childNodes )
    {
        if ([child conformsToProtocol:@protocol(ZG_ConverterSVGToCALayer)])
        {
            // spec says if there is no attribute at all then pick it
            if (![child hasAttribute:@"systemLanguage"])
            {
                [_visibleChildNodes.internalArray addObject:child];
                break;
            }
            
            NSString* languages = [child getAttribute:@"systemLanguage"];

            NSArray* languageCodes = [languages componentsSeparatedByCharactersInSet:
                                      [NSCharacterSet characterSetWithCharactersInString:@", \t\n\r"]];

            if ([languageCodes containsObject:localLanguage])
            {
                [_visibleChildNodes.internalArray addObject:child];
                break;
            }
        
        }
    }
    return _visibleChildNodes;
}

- (void)layoutLayer:(CALayer *)layer
{
    
}
@end
