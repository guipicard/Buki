#include "Color.h"


const buki::Color& buki::Color::Red{ uchar(255), uchar(0), uchar(0), uchar(255) };
const buki::Color& buki::Color::Green{ uchar(0), uchar(255), uchar(0), uchar(255) };
const buki::Color& buki::Color::Blue{ uchar(0), uchar(0), uchar(255), uchar(255) };
const buki::Color& buki::Color::Black{ uchar(0), uchar(0), uchar(0), uchar(255) };
const buki::Color& buki::Color::White{ uchar(255), uchar(255), uchar(255), uchar(255) };

buki::Color::Color() : Color(0, 0, 0, 0) {}

buki::Color::Color(uchar red, uchar green, uchar blue, uchar alpha)
	: r(red)
	, g(green)
	, b(blue)
	, a(alpha)
{

}