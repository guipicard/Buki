#include "Color.h"


const buki::Color& buki::Color::Red = Color(uchar(255), uchar(0), uchar(0), uchar(255));
const buki::Color& buki::Color::Green = Color(uchar(0), uchar(255), uchar(0), uchar(255));
const buki::Color& buki::Color::Blue = Color(uchar(0), uchar(0), uchar(255), uchar(255));
const buki::Color& buki::Color::Black = Color(uchar(0), uchar(0), uchar(0), uchar(255));
const buki::Color& buki::Color::White = Color(uchar(255), uchar(255), uchar(255), uchar(255));
buki::Color::Color(uchar red, uchar green, uchar blue, uchar alpha)
	: r(red)
	, g(green)
	, b(blue)
	, a(alpha)
{
}
