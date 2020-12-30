//
//  ZG_Text.m
//  ZG_SVGKit
//
//  Created by adam on 22/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ZG_Text.h"

@implementation ZG_Text

- (id)initWithValue:(NSString*) v
{
    self = [super initType:ZG_DOMNodeType_TEXT_NODE name:@"#text" value:v];
    if (self) {
		
    }
    return self;
}
-(ZG_Text*) splitText:(unsigned long) offset;
{
	NSAssert( FALSE, @"Not implemented yet" );
	return nil;
}

@end
