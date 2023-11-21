#include "Color.h"

buki::Color::Color(uchar red, uchar green, uchar blue) 
	: Color(red, green, blue, 255)
{
}

buki::Color::Color(uchar red, uchar green, uchar blue, uchar alpha)
	: r(red)
	, g(green)
	, b(blue)
	, a(alpha)
{
}

bool buki::Color::operator==(const Color& c)
{
	return r == c.r && g == c.g && b == c.b && a == c.a;
}

void buki::Color::Set(const Color& other)
{
	r = other.r;
	g = other.g;
	b = other.b;
	a = other.a;
}

const buki::Color& buki::Color::MAROON = buki::Color(128, 0, 0);
const buki::Color& buki::Color::DARKRED = buki::Color(139, 0, 0);
const buki::Color& buki::Color::BROWN = buki::Color(165, 42, 42);
const buki::Color& buki::Color::FIREBRICK = buki::Color(178, 34, 34);
const buki::Color& buki::Color::CRIMSON = buki::Color(220, 20, 60);
const buki::Color& buki::Color::RED = buki::Color(255, 0, 0);
const buki::Color& buki::Color::TOMATO = buki::Color(255, 99, 71);
const buki::Color& buki::Color::CORAL = buki::Color(255, 127, 80);
const buki::Color& buki::Color::INDIANRED = buki::Color(205, 92, 92);
const buki::Color& buki::Color::LIGHTCORAL = buki::Color(240, 128, 128);
const buki::Color& buki::Color::DARKSALMON = buki::Color(233, 150, 122);
const buki::Color& buki::Color::SALMON = buki::Color(250, 128, 114);
const buki::Color& buki::Color::LIGHTSALMON = buki::Color(255, 160, 122);
const buki::Color& buki::Color::ORANGERED = buki::Color(255, 69, 0);
const buki::Color& buki::Color::DARKORANGE = buki::Color(255, 140, 0);
const buki::Color& buki::Color::ORANGE = buki::Color(255, 165, 0);
const buki::Color& buki::Color::GOLD = buki::Color(255, 215, 0);
const buki::Color& buki::Color::DARKGOLDENROD = buki::Color(184, 134, 11);
const buki::Color& buki::Color::GOLDENROD = buki::Color(218, 165, 32);
const buki::Color& buki::Color::PALEGOLDENROD = buki::Color(238, 232, 170);
const buki::Color& buki::Color::DARKKHAKI = buki::Color(189, 183, 107);
const buki::Color& buki::Color::KHAKI = buki::Color(240, 230, 140);
const buki::Color& buki::Color::OLIVE = buki::Color(128, 128, 0);
const buki::Color& buki::Color::YELLOW = buki::Color(255, 255, 0);
const buki::Color& buki::Color::YELLOWGREEN = buki::Color(154, 205, 50);
const buki::Color& buki::Color::DARKOLIVEGREEN = buki::Color(85, 107, 47);
const buki::Color& buki::Color::OLIVEDRAB = buki::Color(107, 142, 35);
const buki::Color& buki::Color::LAWNGREEN = buki::Color(124, 252, 0);
const buki::Color& buki::Color::CHARTREUSE = buki::Color(127, 255, 0);
const buki::Color& buki::Color::GREENYELLOW = buki::Color(173, 255, 47);
const buki::Color& buki::Color::DARKGREEN = buki::Color(0, 100, 0);
const buki::Color& buki::Color::GREEN = buki::Color(0, 128, 0);
const buki::Color& buki::Color::FORESTGREEN = buki::Color(34, 139, 34);
const buki::Color& buki::Color::LIME = buki::Color(0, 255, 0);
const buki::Color& buki::Color::LIMEGREEN = buki::Color(50, 205, 50);
const buki::Color& buki::Color::LIGHTGREEN = buki::Color(144, 238, 144);
const buki::Color& buki::Color::PALEGREEN = buki::Color(152, 251, 152);
const buki::Color& buki::Color::DARKSEAGREEN = buki::Color(143, 188, 143);
const buki::Color& buki::Color::MEDIUMSPRINGGREEN = buki::Color(0, 250, 154);
const buki::Color& buki::Color::SPRINGGREEN = buki::Color(0, 255, 127);
const buki::Color& buki::Color::SEAGREEN = buki::Color(46, 139, 87);
const buki::Color& buki::Color::MEDIUMAQUAMARINE = buki::Color(102, 205, 170);
const buki::Color& buki::Color::MEDIUMSEAGREEN = buki::Color(60, 179, 113);
const buki::Color& buki::Color::LIGHTSEAGREEN = buki::Color(32, 178, 170);
const buki::Color& buki::Color::DARKSLATEGRAY = buki::Color(47, 79, 79);
const buki::Color& buki::Color::TEAL = buki::Color(0, 128, 128);
const buki::Color& buki::Color::DARKCYAN = buki::Color(0, 139, 139);
const buki::Color& buki::Color::AQUA = buki::Color(0, 255, 255);
const buki::Color& buki::Color::CYAN = buki::Color(0, 255, 255);
const buki::Color& buki::Color::LIGHTCYAN = buki::Color(224, 255, 255);
const buki::Color& buki::Color::DARKTURQUOISE = buki::Color(0, 206, 209);
const buki::Color& buki::Color::TURQUOISE = buki::Color(64, 224, 208);
const buki::Color& buki::Color::MEDIUMTURQUOISE = buki::Color(72, 209, 204);
const buki::Color& buki::Color::PALETURQUOISE = buki::Color(175, 238, 238);
const buki::Color& buki::Color::AQUAMARINE = buki::Color(127, 255, 212);
const buki::Color& buki::Color::POWDERBLUE = buki::Color(176, 224, 230);
const buki::Color& buki::Color::CADETBLUE = buki::Color(95, 158, 160);
const buki::Color& buki::Color::STEELBLUE = buki::Color(70, 130, 180);
const buki::Color& buki::Color::CORNFLOWERBLUE = buki::Color(100, 149, 237);
const buki::Color& buki::Color::DEEPSKYBLUE = buki::Color(0, 191, 255);
const buki::Color& buki::Color::DODGERBLUE = buki::Color(30, 144, 255);
const buki::Color& buki::Color::LIGHTBLUE = buki::Color(173, 216, 230);
const buki::Color& buki::Color::SKYBLUE = buki::Color(135, 206, 235);
const buki::Color& buki::Color::LIGHTSKYBLUE = buki::Color(135, 206, 250);
const buki::Color& buki::Color::MIDNIGHTBLUE = buki::Color(25, 25, 112);
const buki::Color& buki::Color::NAVY = buki::Color(0, 0, 128);
const buki::Color& buki::Color::DARKBLUE = buki::Color(0, 0, 139);
const buki::Color& buki::Color::MEDIUMBLUE = buki::Color(0, 0, 205);
const buki::Color& buki::Color::BLUE = buki::Color(0, 0, 255);
const buki::Color& buki::Color::ROYALBLUE = buki::Color(65, 105, 225);
const buki::Color& buki::Color::BLUEVIOLET = buki::Color(138, 43, 226);
const buki::Color& buki::Color::INDIGO = buki::Color(75, 0, 130);
const buki::Color& buki::Color::DARKSLATEBLUE = buki::Color(72, 61, 139);
const buki::Color& buki::Color::SLATEBLUE = buki::Color(106, 90, 205);
const buki::Color& buki::Color::MEDIUMSLATEBLUE = buki::Color(123, 104, 238);
const buki::Color& buki::Color::MEDIUMPURPLE = buki::Color(147, 112, 219);
const buki::Color& buki::Color::DARKMAGENTA = buki::Color(139, 0, 139);
const buki::Color& buki::Color::DARKVIOLET = buki::Color(148, 0, 211);
const buki::Color& buki::Color::DARKORCHID = buki::Color(153, 50, 204);
const buki::Color& buki::Color::MEDIUMORCHID = buki::Color(186, 85, 211);
const buki::Color& buki::Color::PURPLE = buki::Color(128, 0, 128);
const buki::Color& buki::Color::THISTLE = buki::Color(216, 191, 216);
const buki::Color& buki::Color::PLUM = buki::Color(221, 160, 221);
const buki::Color& buki::Color::VIOLET = buki::Color(238, 130, 238);
const buki::Color& buki::Color::MAGENTA = buki::Color(255, 0, 255);
const buki::Color& buki::Color::ORCHID = buki::Color(218, 112, 214);
const buki::Color& buki::Color::MEDIUMVIOLETRED = buki::Color(199, 21, 133);
const buki::Color& buki::Color::PALEVIOLETRED = buki::Color(219, 112, 147);
const buki::Color& buki::Color::DEEPPINK = buki::Color(255, 20, 147);
const buki::Color& buki::Color::HOTPINK = buki::Color(255, 105, 180);
const buki::Color& buki::Color::LIGHTPINK = buki::Color(255, 182, 193);
const buki::Color& buki::Color::PINK = buki::Color(255, 192, 203);
const buki::Color& buki::Color::ANTIQUEWHITE = buki::Color(250, 235, 215);
const buki::Color& buki::Color::BEIGE = buki::Color(245, 245, 220);
const buki::Color& buki::Color::BISQUE = buki::Color(255, 228, 196);
const buki::Color& buki::Color::BLANCHEDALMOND = buki::Color(255, 235, 205);
const buki::Color& buki::Color::WHEAT = buki::Color(245, 222, 179);
const buki::Color& buki::Color::CORNSILK = buki::Color(255, 248, 220);
const buki::Color& buki::Color::LEMONCHIFFON = buki::Color(255, 250, 205);
const buki::Color& buki::Color::LIGHTGOLDENRODYELLOW = buki::Color(250, 250, 210);
const buki::Color& buki::Color::LIGHTYELLOW = buki::Color(255, 255, 224);
const buki::Color& buki::Color::SADDLEBROWN = buki::Color(139, 69, 19);
const buki::Color& buki::Color::SIENNA = buki::Color(160, 82, 45);
const buki::Color& buki::Color::CHOCOLATE = buki::Color(210, 105, 30);
const buki::Color& buki::Color::PERU = buki::Color(205, 133, 63);
const buki::Color& buki::Color::SANDYBROWN = buki::Color(244, 164, 96);
const buki::Color& buki::Color::BURLYWOOD = buki::Color(222, 184, 135);
const buki::Color& buki::Color::TAN = buki::Color(210, 180, 140);
const buki::Color& buki::Color::ROSYBROWN = buki::Color(188, 143, 143);
const buki::Color& buki::Color::MOCCASIN = buki::Color(255, 228, 181);
const buki::Color& buki::Color::NAVAJOWHITE = buki::Color(255, 222, 173);
const buki::Color& buki::Color::PEACHPUFF = buki::Color(255, 218, 185);
const buki::Color& buki::Color::MISTYROSE = buki::Color(255, 228, 225);
const buki::Color& buki::Color::LAVENDERBLUSH = buki::Color(255, 240, 245);
const buki::Color& buki::Color::LINEN = buki::Color(250, 240, 230);
const buki::Color& buki::Color::OLDLACE = buki::Color(253, 245, 230);
const buki::Color& buki::Color::PAPAYAWHIP = buki::Color(255, 239, 213);
const buki::Color& buki::Color::SEASHELL = buki::Color(255, 245, 238);
const buki::Color& buki::Color::MINTCREAM = buki::Color(245, 255, 250);
const buki::Color& buki::Color::SLATEGRAY = buki::Color(112, 128, 144);
const buki::Color& buki::Color::LIGHTSLATEGRAY = buki::Color(119, 136, 153);
const buki::Color& buki::Color::LIGHTSTEELBLUE = buki::Color(176, 196, 222);
const buki::Color& buki::Color::LAVENDER = buki::Color(230, 230, 250);
const buki::Color& buki::Color::FLORALWHITE = buki::Color(255, 250, 240);
const buki::Color& buki::Color::ALICEBLUE = buki::Color(240, 248, 255);
const buki::Color& buki::Color::GHOSTWHITE = buki::Color(248, 248, 255);
const buki::Color& buki::Color::HONEYDEW = buki::Color(240, 255, 240);
const buki::Color& buki::Color::IVORY = buki::Color(255, 255, 240);
const buki::Color& buki::Color::AZURE = buki::Color(240, 255, 255);
const buki::Color& buki::Color::SNOW = buki::Color(255, 250, 250);
const buki::Color& buki::Color::BLACK = buki::Color(0, 0, 0);
const buki::Color& buki::Color::DIMGREY = buki::Color(105, 105, 105);
const buki::Color& buki::Color::GREY = buki::Color(128, 128, 128);
const buki::Color& buki::Color::DARKGREY = buki::Color(169, 169, 169);
const buki::Color& buki::Color::SILVER = buki::Color(192, 192, 192);
const buki::Color& buki::Color::LIGHTGREY = buki::Color(211, 211, 211);
const buki::Color& buki::Color::GAINSBORO = buki::Color(220, 220, 220);
const buki::Color& buki::Color::WHITESMOKE = buki::Color(245, 245, 245);
const buki::Color& buki::Color::WHITE = buki::Color(255, 255, 255);
