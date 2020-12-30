
#import "ZG_AppleSucksDOMImplementation.h"

@implementation ZG_AppleSucksDOMImplementation

-(BOOL) hasFeature:(NSString*) feature version:(NSString*) version
{
	NSAssert( FALSE, @"Apple has made a private class with the same name as this class - we have to rename it because ObjectiveC sucks, and Apple used a foolish name, so we CANNOT adhere to the spec now" );
	
	NSAssert( FALSE, @"Not implemented yet" );
	return FALSE;
}

// Introduced in DOM Level 2:
-(ZG_DocumentType*) createDocumentType:(NSString*) qualifiedName publicId:(NSString*) publicId systemId:(NSString*) systemId
{
	NSAssert( FALSE, @"Apple has made a private class with the same name as this class - we have to rename it because ObjectiveC sucks, and Apple used a foolish name, so we CANNOT adhere to the spec now" );
	
	NSAssert( FALSE, @"Not implemented yet" );
	return nil;
}


// Introduced in DOM Level 2:
-(ZG_Document*) createDocument:(NSString*) namespaceURI qualifiedName:(NSString*) qualifiedName doctype:(ZG_DocumentType*) doctype
{
	NSAssert( FALSE, @"Apple has made a private class with the same name as this class - we have to rename it because ObjectiveC sucks, and Apple used a foolish name, so we CANNOT adhere to the spec now" );
	
	NSAssert( FALSE, @"Not implemented yet" );
	return nil;
}

@end
