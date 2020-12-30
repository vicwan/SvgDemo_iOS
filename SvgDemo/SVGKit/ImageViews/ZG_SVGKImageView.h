#import <Foundation/Foundation.h>

#import "ZG_SVGKImage.h" // cannot import "ZG_SVGKit.h" because that would cause ciruclar imports

/**
 * SVGKit's version of UIImageView - with some improvements over Apple's design. There are multiple versions of this class, for different use cases.
 
 STANDARD USAGE:
   - ZG_SVGKImageView *myImageView = [[ZG_SVGKFastImageView alloc] initWithSVGKImage: [ZG_SVGKImage imageNamed:@"image.svg"]];
   - [self.view addSubview: myImageView];
 
 NB: the "ZG_SVGKFastImageView" is the one you want 9 times in 10. The alternative classes (e.g. SVGKLayeredImageView) are for advanced usage.
 
 NB: read the class-comment for each subclass carefully before deciding what to use.
 
 */
@interface ZG_SVGKImageView : UIView

@property(nonatomic,strong) ZG_SVGKImage* image;
@property(nonatomic) BOOL showBorder; /**< mostly for debugging - adds a coloured 1-pixel border around the image */

@property(nonatomic,readonly) NSTimeInterval timeIntervalForLastReRenderOfSVGFromMemory;

- (id)initWithSVGKImage:(ZG_SVGKImage*) im;

@end
