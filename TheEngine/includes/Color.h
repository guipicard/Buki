#pragma once

namespace buki {

	typedef unsigned char uchar;
	class Color
	{
	public:
		static const Color& Red;
		static const Color& Green;
		static const Color& Blue;
		static const Color& Black;
		static const Color& White;
		Color();
		Color(uchar red, uchar green, uchar blue, uchar alpha);
		uchar r;
		uchar g;
		uchar b;
		uchar a;
	};
}