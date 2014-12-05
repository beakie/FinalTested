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
			FloatMax h, s, v;

			TUNSIGNEDINT upperBound = 255;

			//r = document.calcform.r.value;
			FloatMax r = pixel.Values[0];
			//g = document.calcform.g.value;
			FloatMax g = pixel.Values[1];
			//b = document.calcform.b.value;
			FloatMax b = pixel.Values[2];
			//r /= 255;
			r /= upperBound;
			//g /= 255;
			g /= upperBound;
			//b /= 255;
			b /= upperBound;
			//M = Math.max(r, g, b);
			FloatMax max = Common::max(r, g, b);
			//m = Math.min(r, g, b);
			FloatMax min = Common::min(r, g, b);
			//C = M - m;
			FloatMax range = max - min;
			//if (C == 0) h = 0;
			if (range == 0) h = 0;
			//else if (M == r) h = ((g - b) / C) % 6;
			else if (max == r) h = (TUNSIGNEDINT)((g - b) / range) % 6;
			//else if (M == g) h = (b - r) / C + 2;
			else if (max == g) h = (b - r) / range + 2;
			//else h = (r - g) / C + 4;
			else h = (r - g) / range + 4;
			//h *= 60;
			h *= 60;
			//if (h<0) h += 360;
			if (h < 0) h += 360;
			//v = M;
			v = max;
			//if (v == 0)
			if (v == 0)
			//s = 0;
			s = 0;
			//else
			else
			//s = C / v;
			s = range / v;
			//s *= 100;
			s *= 100;
			//v *= 100;
			v *= 100;
			return Common::Vector3<TUNSIGNEDINT>(h, s, v);
		}
	};

}

#endif // PICTURERGBTOHSVPIXELCONV_H

// view-source:http://www.rapidtables.com/convert/color/rgb-to-hsv.htm
