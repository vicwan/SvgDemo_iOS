//
//  ZG_ProcessingInstruction.m
//  ZG_SVGKit
//
//  Created by adam on 22/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ZG_ProcessingInstruction.h"

@interface ZG_ProcessingInstruction()
@property(nonatomic,strong,readwrite) NSString* target;
@property(nonatomic,strong,readwrite) NSString* data;
@end

@implementation ZG_ProcessingInstruction

@synthesize target;
@synthesize data;

-(id) initProcessingInstruction:(NSString*) t value:(NSString*) d
{
    self = [super initType:ZG_DOMNodeType_PROCESSING_INSTRUCTION_NODE name:t value:d];
    if (self) {
		self.target = t;
		self.data = d;
    }
    return self;
}

@end
