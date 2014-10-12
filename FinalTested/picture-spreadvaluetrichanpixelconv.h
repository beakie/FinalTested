#ifndef PICTURESPREADVALUETRICHANPIXELCONV_H
#define PICTURESPREADVALUETRICHANPIXELCONV_H

#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE, typename TINDEX>
	class SpreadValueTriChanPixelConv
	{
	public:
		Picture::TriChanPixel<TVALUE> convertPixel(const TVALUE value)
		{
			return Picture::TriChanPixel<TVALUE>(value, value, value);
		}
	};
}

#endif // PICTURESPREADVALUETRICHANPIXELCONV_H
