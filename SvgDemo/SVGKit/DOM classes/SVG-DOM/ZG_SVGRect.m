#import "ZG_SVGRect.h"
#import "ZG_SVGKDefine_Private.h"

BOOL ZG_SVGRectIsInitialized( ZG_SVGRect rect )
{
	return rect.x != -1 || rect.y != -1 || rect.width != -1 || rect.height != -1;
}

ZG_SVGRect ZG_SVGRectUninitialized( void )
{
	return ZG_SVGRectMake( -1, -1, -1, -1 );
}

ZG_SVGRect ZG_SVGRectMake( float x, float y, float width, float height )
{
	ZG_SVGRect result = { x, y, width, height };
	return result;
}

CGRect ZG_CGRectFromSVGRect( ZG_SVGRect rect )
{
	CGRect result = CGRectMake(rect.x, rect.y, rect.width, rect.height);
	
	return result;
}

CGSize ZG_CGSizeFromSVGRect( ZG_SVGRect rect )
{
	CGSize result = CGSizeMake( rect.width, rect.height );
	
	return result;
}

NSString * ZG_NSStringFromSVGRect( ZG_SVGRect rect ) {
    CGRect cgRect = ZG_CGRectFromSVGRect(rect);
#if SVGKIT_MAC
    return NSStringFromRect(cgRect);
#else
    return NSStringFromCGRect(cgRect);
#endif
}
