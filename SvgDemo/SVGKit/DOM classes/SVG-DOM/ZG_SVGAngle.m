#import "ZG_SVGAngle.h"

@implementation ZG_SVGAngle

@synthesize unitType;
@synthesize value;
@synthesize valueInSpecifiedUnits;
@synthesize valueAsString;

-(void) newValueSpecifiedUnits:(ZG_SVGKAngleType) unitType valueInSpecifiedUnits:(float) valueInSpecifiedUnits { NSAssert( FALSE, @"Not implemented yet" ); }
-(void) convertToSpecifiedUnits:(ZG_SVGKAngleType) unitType { NSAssert( FALSE, @"Not implemented yet" ); }

@end
