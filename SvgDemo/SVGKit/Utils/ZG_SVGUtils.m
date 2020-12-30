//
//  ZG_SVGUtils.m
//  ZG_SVGKit
//
//  Copyright Matt Rajca 2010-2011. All rights reserved.
//

#import "ZG_SVGUtils.h"
#import "ZG_SVGKDefine_Private.h"

#define MAX_ACCUM 64
#define NUM_COLORS 148


ZG_SVGColor ZG_ColorValueWithName (const char *name);

static const char *gColorNames[NUM_COLORS] = {
	"aliceblue",
	"antiquewhite",
	"aqua",
	"aquamarine",
	"azure",
	"beige",
	"bisque",
	"black",
	"blanchedalmond",
	"blue",
	"blueviolet",
	"brown",
	"burlywood",
	"cadetblue",
	"chartreuse",
	"chocolate",
	"coral",
	"cornflowerblue",
	"cornsilk",
	"crimson",
	"cyan",
	"darkblue",
	"darkcyan",
	"darkgoldenrod",
	"darkgray",
	"darkgreen",
	"darkgrey",
	"darkkhaki",
	"darkmagenta",
	"darkolivegreen",
	"darkorange",
	"darkorchid",
	"darkred",
	"darksalmon",
	"darkseagreen",
	"darkslateblue",
	"darkslategray",
	"darkslategrey",
	"darkturquoise",
	"darkviolet",
	"deeppink",
	"deepskyblue",
	"dimgray",
	"dimgrey",
	"dodgerblue",
	"firebrick",
	"floralwhite",
	"forestgreen",
	"fuchsia",
	"gainsboro",
	"ghostwhite",
	"gold",
	"goldenrod",
	"gray",
	"green",
	"greenyellow",
	"grey",
	"honeydew",
	"hotpink",
	"indianred",
	"indigo",
	"ivory",
	"khaki",
	"lavender",
	"lavenderblush",
	"lawngreen",
	"lemonchiffon",
	"lightblue",
	"lightcoral",
	"lightcyan",
	"lightgoldenrodyellow",
	"lightgray",
	"lightgreen",
	"lightgrey",
	"lightpink",
	"lightsalmon",
	"lightseagreen",
	"lightskyblue",
	"lightslategray",
	"lightslategrey",
	"lightsteelblue",
	"lightyellow",
	"lime",
	"limegreen",
	"linen",
	"magenta",
	"maroon",
	"mediumaquamarine",
	"mediumblue",
	"mediumorchid",
	"mediumpurple",
	"mediumseagreen",
	"mediumslateblue",
	"mediumspringgreen",
	"mediumturquoise",
	"mediumvioletred",
	"midnightblue",
	"mintcream",
	"mistyrose",
	"moccasin",
	"navajowhite",
	"navy",
	"oldlace",
	"olive",
	"olivedrab",
	"orange",
	"orangered",
	"orchid",
	"palegoldenrod",
	"palegreen",
	"paleturquoise",
	"palevioletred",
	"papayawhip",
	"peachpuff",
	"peru",
	"pink",
	"plum",
	"powderblue",
	"purple",
	"red",
	"rosybrown",
	"royalblue",
	"saddlebrown",
	"salmon",
	"sandybrown",
	"seagreen",
	"seashell",
	"sienna",
	"silver",
	"skyblue",
	"slateblue",
	"slategray",
	"slategrey",
	"snow",
	"springgreen",
	"steelblue",
	"tan",
	"teal",
	"thistle",
	"tomato",
	"turquoise",
	"violet",
	"wheat",
	"white",
	"whitesmoke",
	"yellow",
	"yellowgreen",
    // CSS Color
    "transparent"
};

static const ZG_SVGColor gColorValues[NUM_COLORS] = {
	(ZG_SVGColor) { 240,248,255,255 }, (ZG_SVGColor) { 250,235,215,255 },
	(ZG_SVGColor) { 0,255,255,255 }, (ZG_SVGColor) { 127,255,212,255 },
	(ZG_SVGColor) { 240,255,255,255 }, (ZG_SVGColor) { 245,245,220,255 },
	(ZG_SVGColor) { 255,228,196,255 }, (ZG_SVGColor) { 0,0,0,255 },
	(ZG_SVGColor) { 255,235,205,255 }, (ZG_SVGColor) { 0,0,255,255 },
	(ZG_SVGColor) { 138,43,226,255 }, (ZG_SVGColor) { 165,42,42,255 },
	(ZG_SVGColor) { 222,184,135,255 }, (ZG_SVGColor) { 95,158,160,255 },
	(ZG_SVGColor) { 127,255,0,255 }, (ZG_SVGColor) { 210,105,30,255 },
	(ZG_SVGColor) { 255,127,80,255 }, (ZG_SVGColor) { 100,149,237,255 },
	(ZG_SVGColor) { 255,248,220,255 }, (ZG_SVGColor) { 220,20,60,255 },
	(ZG_SVGColor) { 0,255,255,255 }, (ZG_SVGColor) { 0,0,139,255 },
	(ZG_SVGColor) { 0,139,139,255 }, (ZG_SVGColor) { 184,134,11,255 },
	(ZG_SVGColor) { 169,169,169,255 }, (ZG_SVGColor) { 0,100,0,255 },
	(ZG_SVGColor) { 169,169,169,255 }, (ZG_SVGColor) { 189,183,107,255 },
	(ZG_SVGColor) { 139,0,139,255 }, (ZG_SVGColor) { 85,107,47,255 },
	(ZG_SVGColor) { 255,140,0,255 }, (ZG_SVGColor) { 153,50,204,255 },
	(ZG_SVGColor) { 139,0,0,255 }, (ZG_SVGColor) { 233,150,122,255 },
	(ZG_SVGColor) { 143,188,143,255 }, (ZG_SVGColor) { 72,61,139,255 },
	(ZG_SVGColor) { 47,79,79,255 }, (ZG_SVGColor) { 47,79,79,255 },
	(ZG_SVGColor) { 0,206,209,255 }, (ZG_SVGColor) { 148,0,211,255 },
	(ZG_SVGColor) { 255,20,147,255 }, (ZG_SVGColor) { 0,191,255,255 },
	(ZG_SVGColor) { 105,105,105,255 }, (ZG_SVGColor) { 105,105,105,255 },
	(ZG_SVGColor) { 30,144,255,255 }, (ZG_SVGColor) { 178,34,34,255 },
	(ZG_SVGColor) { 255,250,240,255 }, (ZG_SVGColor) { 34,139,34,255 },
	(ZG_SVGColor) { 255,0,255,255 }, (ZG_SVGColor) { 220,220,220,255 },
	(ZG_SVGColor) { 248,248,255,255 }, (ZG_SVGColor) { 255,215,0,255 },
	(ZG_SVGColor) { 218,165,32,255 }, (ZG_SVGColor) { 128,128,128,255 },
	(ZG_SVGColor) { 0,128,0,255 }, (ZG_SVGColor) { 173,255,47,255 },
	(ZG_SVGColor) { 128,128,128,255 }, (ZG_SVGColor) { 240,255,240,255 },
	(ZG_SVGColor) { 255,105,180,255 }, (ZG_SVGColor) { 205,92,92,255 },
	(ZG_SVGColor) { 75,0,130,255 }, (ZG_SVGColor) { 255,255,240,255 },
	(ZG_SVGColor) { 240,230,140,255 }, (ZG_SVGColor) { 230,230,250,255 },
	(ZG_SVGColor) { 255,240,245,255 }, (ZG_SVGColor) { 124,252,0,255 },
	(ZG_SVGColor) { 255,250,205,255 }, (ZG_SVGColor) { 173,216,230,255 },
	(ZG_SVGColor) { 240,128,128,255 }, (ZG_SVGColor) { 224,255,255,255 },
	(ZG_SVGColor) { 250,250,210,255 }, (ZG_SVGColor) { 211,211,211,255 },
	(ZG_SVGColor) { 144,238,144,255 }, (ZG_SVGColor) { 211,211,211,255 },
	(ZG_SVGColor) { 255,182,193,255 }, (ZG_SVGColor) { 255,160,122,255 },
	(ZG_SVGColor) { 32,178,170,255 }, (ZG_SVGColor) { 135,206,250,255 },
	(ZG_SVGColor) { 119,136,153,255 }, (ZG_SVGColor) { 119,136,153,255 },
	(ZG_SVGColor) { 176,196,222,255 }, (ZG_SVGColor) { 255,255,224,255 },
	(ZG_SVGColor) { 0,255,0,255 }, (ZG_SVGColor) { 50,205,50,255 },
	(ZG_SVGColor) { 250,240,230,255 }, (ZG_SVGColor) { 255,0,255,255 },
	(ZG_SVGColor) { 128,0,0,255 }, (ZG_SVGColor) { 102,205,170,255 },
	(ZG_SVGColor) { 0,0,205,255 }, (ZG_SVGColor) { 186,85,211,255 },
	(ZG_SVGColor) { 147,112,219,255 }, (ZG_SVGColor) { 60,179,113,255 },
	(ZG_SVGColor) { 123,104,238,255 }, (ZG_SVGColor) { 0,250,154,255 },
	(ZG_SVGColor) { 72,209,204,255 }, (ZG_SVGColor) { 199,21,133,255 },
	(ZG_SVGColor) { 25,25,112,255 }, (ZG_SVGColor) { 245,255,250,255 },
	(ZG_SVGColor) { 255,228,225,255 }, (ZG_SVGColor) { 255,228,181,255 },
	(ZG_SVGColor) { 255,222,173,255 }, (ZG_SVGColor) { 0,0,128,255 },
	(ZG_SVGColor) { 253,245,230,255 }, (ZG_SVGColor) { 128,128,0,255 },
	(ZG_SVGColor) { 107,142,35,255 }, (ZG_SVGColor) { 255,165,0,255 },
	(ZG_SVGColor) { 255,69,0,255 }, (ZG_SVGColor) { 218,112,214,255 },
	(ZG_SVGColor) { 238,232,170,255 }, (ZG_SVGColor) { 152,251,152,255 },
	(ZG_SVGColor) { 175,238,238,255 }, (ZG_SVGColor) { 219,112,147,255 },
	(ZG_SVGColor) { 255,239,213,255 }, (ZG_SVGColor) { 255,218,185,255 },
	(ZG_SVGColor) { 205,133,63,255 }, (ZG_SVGColor) { 255,192,203,255 },
	(ZG_SVGColor) { 221,160,221,255 }, (ZG_SVGColor) { 176,224,230,255 },
	(ZG_SVGColor) { 128,0,128,255 }, (ZG_SVGColor) { 255,0,0,255 },
	(ZG_SVGColor) { 188,143,143,255 }, (ZG_SVGColor) { 65,105,225,255 },
	(ZG_SVGColor) { 139,69,19,255 }, (ZG_SVGColor) { 250,128,114,255 },
	(ZG_SVGColor) { 244,164,96,255 }, (ZG_SVGColor) { 46,139,87,255 },
	(ZG_SVGColor) { 255,245,238,255 }, (ZG_SVGColor) { 160,82,45,255 },
	(ZG_SVGColor) { 192,192,192,255 }, (ZG_SVGColor) { 135,206,235,255 },
	(ZG_SVGColor) { 106,90,205,255 }, (ZG_SVGColor) { 112,128,144,255 },
	(ZG_SVGColor) { 112,128,144,255 }, (ZG_SVGColor) { 255,250,250,255 },
	(ZG_SVGColor) { 0,255,127,255 }, (ZG_SVGColor) { 70,130,180,255 },
	(ZG_SVGColor) { 210,180,140,255 }, (ZG_SVGColor) { 0,128,128,255 },
	(ZG_SVGColor) { 216,191,216,255 }, (ZG_SVGColor) { 255,99,71,255 },
	(ZG_SVGColor) { 64,224,208,255 }, (ZG_SVGColor) { 238,130,238,255 },
	(ZG_SVGColor) { 245,222,179,255 }, (ZG_SVGColor) { 255,255,255,255 },
	(ZG_SVGColor) { 245,245,245,255 }, (ZG_SVGColor) { 255,255,0,255 },
	(ZG_SVGColor) { 154,205,50,255 },
    // CSS Color
    (ZG_SVGColor) { 0, 0, 0, 0}
};

ZG_SVGColor ZG_ColorValueWithName (const char *name) {
	int idx = -1;
	
	for (int n = 0; n < NUM_COLORS; n++) {
		if (!strcmp(gColorNames[n], name)) {
			idx = n;
			break;
		}
	}
	
	if (idx == -1) {
		return ZG_SVGColorMake(0, 0, 0, 255); // black
	}
	
	return gColorValues[idx];
}

ZG_SVGColor ZG_SVGColorMake (uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
	ZG_SVGColor color = { .r = r, .g = g, .b = b, .a = a };
	return color;
}

typedef enum {
	ZG_PhaseNone = 0,
	ZG_PhaseRGB,
    ZG_PhaseRGBA
} ZG_Phase;

ZG_SVGColor ZG_SVGColorFromString (const char *string) {
	NSCAssert(string != NULL, @"NullPointerException: you gave us a null pointer, very bad thing to do...");
	ZG_SVGColor color;
	bzero(&color, sizeof(color));
	
	color.a = 0xFF;
	
	if (!strncmp(string, "rgb(", 4) || !strncmp(string, "rgba(", 5)) {
		size_t len = strlen(string);
		
		char accum[MAX_ACCUM];
		bzero(accum, MAX_ACCUM);
		
		int accumIdx = 0, currComponent = 0;
		ZG_Phase phase = ZG_PhaseNone;
		
		for (size_t n = 0; n < len; n++) {
			char c = string[n];
			
			if (c == '\n' || c == '\t' || c == ' ') {
				continue;
			}
			
            if (!strcmp(accum, "rgba(")) {
                phase = ZG_PhaseRGBA;
                bzero(accum, MAX_ACCUM);
                accumIdx = 0;
            } else if (!strcmp(accum, "rgb(")) {
				phase = ZG_PhaseRGB;
                bzero(accum, MAX_ACCUM);
                accumIdx = 0;
			}
			
			if (phase == ZG_PhaseRGB || phase == ZG_PhaseRGBA) {
				if (c == ',') {
					if (currComponent == 0) {
						color.r = atoi(accum);
						currComponent++;
					}
					else if (currComponent == 1) {
						color.g = atoi(accum);
						currComponent++;
					}
                    else if (phase == ZG_PhaseRGBA && currComponent == 2) {
                        color.b = atoi(accum);
                        currComponent++;
                    }
					bzero(accum, MAX_ACCUM);
					accumIdx = 0;
					
					continue;
				}
                else if (c == ')' && currComponent == 2) {
                    color.b = atoi(accum);
                    break;
                }
                else if (c == ')' && currComponent == 3) {
                    color.a = (uint8_t)lround(atof(accum) * 255.0f);
                    break;
                }
			}
			
			accum[accumIdx++] = c;
		}
	}
	else if (!strncmp(string, "#", 1)) {
		const char *hexString = string + 1;
		
		if (strlen(hexString) == 6)
		{
			char r[3], g[3], b[3];
			r[2] = g[2] = b[2] = '\0';
			
			strncpy(r, hexString, 2);
			strncpy(g, hexString + 2, 2);
			strncpy(b, hexString + 4, 2);
			
			color.r = strtol(r, NULL, 16);
			color.g = strtol(g, NULL, 16);
			color.b = strtol(b, NULL, 16);
		}
		else if( strlen(hexString) == 3 )
		{
			char r[2], g[2], b[2];
			r[1] = g[1] = b[1] = '\0';
			
			strncpy(r, hexString, 1);
			strncpy(g, hexString + 1, 1);
			strncpy(b, hexString + 2, 1);
			
			color.r = strtol(r, NULL, 16);
			color.g = strtol(g, NULL, 16);
			color.b = strtol(b, NULL, 16);
			
			/** because 3-digit hex notation "F" means "FF" ... "1" means "11" ... etc */
			color.r += color.r * 16;
			color.g += color.g * 16;
			color.b += color.b * 16;
		}
		else
		{
			color = ZG_SVGColorMake(0, 0, 0, 255);
		}
		
	}
	else {
		color = ZG_ColorValueWithName(string);
	}
	
	return color;
}

CGFloat ZG_SVGPercentageFromString (const char *string) {
	size_t len = strlen(string);
	
	if (string[len-1] != '%') {
		SVGKitLogWarn(@"Invalid percentage: %s", string);
		return -1;
	}
	
	return atoi(string) / 100.0f;
}

CGMutablePathRef ZG_createPathFromPointsInString (const char *string, boolean_t close) {
	CGMutablePathRef path = CGPathCreateMutable();
	
	size_t len = strlen(string);
	
	char accum[MAX_ACCUM];
	bzero(accum, MAX_ACCUM);
	
	int accumIdx = 0, currComponent = 0;
	
	for (size_t n = 0; n <= len; n++) {
		char c = string[n];
		
		if (c == '\n' || c == '\t' || c == ' ' || c == ',' || c == '\0') {
			accum[accumIdx] = '\0';
			
			static float x, y;
			
			if (currComponent == 0 && accumIdx != 0) {
				sscanf( accum, "%g", &x );
				currComponent++;
			}
			else if (currComponent == 1) {
				
				sscanf( accum, "%g", &y );
				
				if (CGPathIsEmpty(path)) {
					CGPathMoveToPoint(path, NULL, x, y);
				}
				else {
					CGPathAddLineToPoint(path, NULL, x, y);
				}
				
				currComponent = 0;
			}
			
			bzero(accum, MAX_ACCUM);
			accumIdx = 0;
		}
		else if (isdigit(c) || c == '-' || c == '.') { // is digit or decimal separator OR A MINUS SIGN!!! ?
			accum[accumIdx++] = c;
		}
	}
	
	if (close) {
		CGPathCloseSubpath(path);
	}
	
	return path;
}

CGColorRef ZG_CGColorWithSVGColor (ZG_SVGColor color) {
	CGColorRef outColor = NULL;
	
	outColor = [UIColor colorWithRed:RGB_N(color.r)
							   green:RGB_N(color.g)
								blue:RGB_N(color.b)
							   alpha:RGB_N(color.a)].CGColor;
	
	return outColor;
}
