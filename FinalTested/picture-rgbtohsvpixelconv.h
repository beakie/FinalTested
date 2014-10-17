#ifndef PICTURERGBTOHSVPIXELCONV_H
#define PICTURERGBTOHSVPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class RgbToHsvConv
	{
		// move function variables to here

	public:
		Common::Vector3<TVALUE> convertPixel(const Common::Vector3<TVALUE>& pixel)
		{
			float h, s, v;

			float minChannel = Common::min(pixel.Values[0], pixel.Values[1], pixel.Values[2]);
			float maxChannel = Common::max(pixel.Values[0], pixel.Values[1], pixel.Values[2]);
			v = maxChannel;				// v
			float delta = maxChannel - minChannel;
			if (maxChannel != 0)
				s = delta / maxChannel;		// s
			else {
				// r = g = b = 0		// s = 0, v is undefined
				s = 0;
				h = -1;
				return;
			}
			if (r == maxChannel)
				h = (g - b) / delta;		// between yellow & magenta
			else if (g == maxChannel)
				h = 2 + (b - r) / delta;	// between cyan & yellow
			else
				*h = 4 + (r - g) / delta;	// between magenta & cyan
			h *= 60;				// degrees
			if (h < 0)
				h += 360;
		}
	};

}

#endif // PICTURERGBTOHSVPIXELCONV_H

//http://www.cs.rit.edu/~ncs/color/t_convert.html#RGB%20to%20HSV%20&%20HSV%20to%20RGB
