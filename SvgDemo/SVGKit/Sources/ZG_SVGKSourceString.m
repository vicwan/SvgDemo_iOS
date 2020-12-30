#import "ZG_SVGKSourceString.h"

@implementation ZG_SVGKSourceString

-(NSString *)keyForAppleDictionaries
{
	return self.rawString;
}

+ (ZG_SVGKSource*)sourceFromContentsOfString:(NSString*)rawString {
	NSInputStream* stream = [NSInputStream inputStreamWithData:[rawString dataUsingEncoding:NSUTF8StringEncoding]];
	//DO NOT DO THIS: let the parser do it at last possible moment (Apple has threading problems otherwise!) [stream open];
	
	ZG_SVGKSource* s = [[ZG_SVGKSourceString alloc] initWithInputSteam:stream];
	s.approximateLengthInBytesOr0 = [rawString lengthOfBytesUsingEncoding:NSUTF8StringEncoding];
	
	return s;
}

-(id)copyWithZone:(NSZone *)zone
{
	id copy = [super copyWithZone:zone];
	
	if( copy )
	{	
		/** clone bits */
		[copy setRawString:[self.rawString copy]];
		
		/** Finally, manually intialize the input stream, as required by super class */
		[copy setStream:[NSInputStream inputStreamWithData:[((ZG_SVGKSourceString*)copy).rawString dataUsingEncoding:NSUTF8StringEncoding]]];
	}
	
	return copy;
}

@end
