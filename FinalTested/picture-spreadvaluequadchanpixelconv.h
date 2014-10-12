#ifndef PICTURESPREADVALUEQUADCHANPIXELCONV_H
#define PICTURESPREADVALUEQUADCHANPIXELCONV_H

#include "picture-quadchanpixel.h"

namespace Picture
{
	template <typename TVALUE>
	class SpreadValueQuadChanPixelConv
	{
	public:
		Picture::QuadChanPixel<TVALUE> convertPixel(const TVALUE value)
		{
			return Picture::QuadChanPixel<TVALUE>(value, value, value, value);
		}
	};
}

#endif // PICTURESPREADVALUEQUADCHANPIXELCONV_H
