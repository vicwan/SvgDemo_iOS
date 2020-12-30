//
//  ZG_Attr.m
//  ZG_SVGKit
//
//  Created by adam on 22/05/2012.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#import "ZG_Attr.h"

#import "ZG_Node+Mutable.h"

@interface ZG_Attr()
 @property(nonatomic,strong,readwrite) NSString* name;
 @property(nonatomic,readwrite) BOOL specified;
 @property(nonatomic,strong,readwrite) NSString* value;
 
 // Introduced in DOM Level 2:
 @property(nonatomic,strong,readwrite) ZG_Element* ownerElement;
@end

@implementation ZG_Attr

@synthesize name;
@synthesize specified;
@synthesize value;

// Introduced in DOM Level 2:
@synthesize ownerElement;

- (id)initWithName:(NSString*) n value:(NSString*) v
{
    self = [super initType:ZG_DOMNodeType_ATTRIBUTE_NODE name:n value:v];
    if (self)
	{
		self.name = n;
		self.value = v;
    }
    return self;
}

- (id)initWithNamespace:(NSString*) ns qualifiedName:(NSString*) qn value:(NSString *)v
{
    self = [super initType:ZG_DOMNodeType_ATTRIBUTE_NODE name:qn value:v inNamespace:ns];
	if (self)
	{
		self.name = qn;
		self.value = v;
    }
    return self;
}


@end
