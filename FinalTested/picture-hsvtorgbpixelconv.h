#ifndef PICTUREHSVTORGBPIXELCONV_H
#define PICTUREHSVTORGBPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class HsvToRgbConv
	{
		// move function variables to here

	public:
		Common::Vector3<TVALUE> convertPixel(const Common::Vector3<TVALUE>& pixel)
		{
			if (pixel.Values[1] == 0)
				return Common::Vector3<TVALUE>(pixel.Values[2], pixel.Values[2], pixel.Values[2]);

			float h = pixel.Values[0] / 60;
			int i = floor(h);
			float f = h - i;
			float p = pixel.Values[2] * (1 - pixel.Values[1]);
			float q = pixel.Values[2] * (1 - pixel.Values[1] * f);
			float t = pixel.Values[2] * (1 - pixel.Values[1] * (1 - f));
			switch (i) {
			case 0:
				return Common::Vector3<TVALUE>(v, t, p);
			case 1:
				return Common::Vector3<TVALUE>(q, v, p);
			case 2:
				return Common::Vector3<TVALUE>(p, v, t);
			case 3:
				return Common::Vector3<TVALUE>(p, q, v);
			case 4:
				return Common::Vector3<TVALUE>(t, p, v);
			default:
				return Common::Vector3<TVALUE>(v, p, q);
			}
		}
	};

}

#endif // PICTUREHSVTORGBPIXELCONV_H
