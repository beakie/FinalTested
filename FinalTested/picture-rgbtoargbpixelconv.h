#ifndef PICTURERGBTOARGBPIXELCONV_H
#define PICTURERGBTOARGBPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	class RgbToArgbPixelConv
	{
		// move function variables to here

	public:
		Common::Vector4<TUNITINTERVAL> convertPixel(const Common::Vector3<TUNITINTERVAL>& pixel)
		{
			return Common::Vector4<TUNITINTERVAL>(1, pixel.Values[0], pixel.Values[1], pixel.Values[2]);
		}
	};

}

#endif // PICTURERGBTOARGBPIXELCONV_H

// http://www.javascripter.net/faq/rgb2cmyk.htm
