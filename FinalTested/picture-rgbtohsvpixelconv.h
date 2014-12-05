#ifndef PICTURERGBTOHSVPIXELCONV_H
#define PICTURERGBTOHSVPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNSIGNEDINT>
	class RgbToHsvPixelConv
	{
		// move function variables to here

	public:
		Common::Vector3<TUNSIGNEDINT> convertPixel(const Common::Vector3<TUNSIGNEDINT>& pixel)
		{
			TUNSIGNEDINT upperBound = Common::getUpperBound<TUNSIGNEDINT>();

			FloatMax r = pixel.Values[0] / upperBound;
			FloatMax g = pixel.Values[1] / upperBound;
			FloatMax b = pixel.Values[2] / upperBound;

			FloatMax max = Common::max(r, g, b);
			FloatMax min = Common::min(r, g, b);
			FloatMax delta = max - min;

			FloatMax h, s, v;

			if (delta == 0)
				h = 0;
			else if (max == r)
				h = (TUNSIGNEDINT)((g - b) / delta) % 6;
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
			
			return Common::Vector3<TUNSIGNEDINT>(h, s, v);
		}
	};

}

#endif // PICTURERGBTOHSVPIXELCONV_H
