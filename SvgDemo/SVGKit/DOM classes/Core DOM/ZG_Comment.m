//
//  ZG_Comment.m
//  ZG_SVGKit
//
//  Created by adam on 22/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ZG_Comment.h"

@implementation ZG_Comment

- (id)initWithValue:(NSString*) v
{
    self = [super initType:ZG_DOMNodeType_COMMENT_NODE name:@"#comment" value:v];
    if (self) {
    }
    return self;
}

@end
