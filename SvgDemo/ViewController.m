//
//  ViewController.m
//  SvgDemo
//
//  Created by Vic on 2020/12/30.
//

#import "ViewController.h"
#import "ZG_SVGKit.h"

@interface ViewController ()
@property (nonatomic, strong) UIImageView *imageView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupImageView];
    [self loadSvgImage];
}

- (void)setupImageView {
    self.imageView = [[UIImageView alloc] initWithFrame:self.view.bounds];
    [self.view addSubview:self.imageView];
//    self.imageView.backgroundColor = UIColor.yellowColor;
    [self.imageView setContentMode:UIViewContentModeScaleAspectFit];
}

- (void)loadSvgImage {
    ZG_SVGKImage *svg = [ZG_SVGKImage imageNamed:@"svg-test.svg"];
    UIImage *image = svg.UIImage;
    self.imageView.image = image;
    NSLog(@"Parse svg complete.");
    NSLog(@"%@", svg.parseErrorsAndWarnings);
}

@end
