#ifndef PICTURERGBTOHSVPIXELCONV_H
#define PICTURERGBTOHSVPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	class RgbToHsvPixelConv
	{
		// move function variables to here

	public:
		Common::Vector3<TUNITINTERVAL> convertPixel(const Common::Vector3<TUNITINTERVAL>& pixel)
		{
			FloatMax r = (FloatMax)pixel.Values[0];
			FloatMax g = (FloatMax)pixel.Values[1];
			FloatMax b = (FloatMax)pixel.Values[2];

			FloatMax max = Common::max(r, g, b);
			FloatMax min = Common::min(r, g, b);
			FloatMax delta = max - min;

			FloatMax h, s, v;

			v = max;

			if (max != 0)
				s = delta / max;		// s
			else {
				s = 0;
				h = -1;
				return Common::Vector3<TUNITINTERVAL>(h, s, v);
			}
			if (r == max)
				h = (g - b) / delta;		// between yellow & magenta
			else if (g == max)
				h = 2 + (b - r) / delta;	// between cyan & yellow
			else
				h = 4 + (r - g) / delta;	// between magenta & cyan
			h *= 60;				// degrees
			if (h < 0)
				h += 360;
			
			return Common::Vector3<TUNITINTERVAL>(h / 360, s, v);
		}

		Common::Vector3<UInt8> convertPixel2(const Common::Vector3<UInt8>& pixel)
		{
			UInt8 upperBound = Common::getUpperBound<UInt8>();

			FloatMax r = (FloatMax)pixel.Values[0] / upperBound;
			FloatMax g = (FloatMax)pixel.Values[1] / upperBound;
			FloatMax b = (FloatMax)pixel.Values[2] / upperBound;

			FloatMax max = Common::max(r, g, b);
			FloatMax min = Common::min(r, g, b);
			FloatMax delta = max - min;

			FloatMax h, s, v;

			if (delta == 0)
				h = 0;
			else if (max == r)
				h = (UInt8)((g - b) / delta) % 6;
			else if (max == g)
				h = (b - r) / delta + 2;
			else
				h = (r - g) / delta + 4;

			h *= 60;

			if (h < 0)
				h += 360;

			v = max;

			if (v == 0)
				s = 0;
			else
				s = delta / v;

			s *= 100;
			v *= 100;

			return Common::Vector3<UInt8>(h, s, v);
		}
	};

}

#endif // PICTURERGBTOHSVPIXELCONV_H

// http://www.cs.rit.edu/~ncs/color/t_convert.html
