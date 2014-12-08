#ifndef PICTURECMYKTORGBPIXELCONV_H
#define PICTURECMYKTORGBPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	class CmykToRgbPixelConv
	{
		// move function variables to here

	public:
		Common::Vector3<TUNITINTERVAL> convertPixel(const Common::Vector3<TUNITINTERVAL>& pixel)
		{
			FloatMax h = (FloatMax)pixel.Values[0];
			FloatMax s = (FloatMax)pixel.Values[1];
			FloatMax v = (FloatMax)pixel.Values[2];

		}
	};

}

#endif // PICTURECMYKTORGBPIXELCONV_H
