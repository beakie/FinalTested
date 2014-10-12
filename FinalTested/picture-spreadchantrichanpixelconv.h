#ifndef PICTURESPREADCHANTRICHANPIXELCONV_H
#define PICTURESPREADCHANTRICHANPIXELCONV_H

#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE, typename TINDEX>
	class SpreadChanTriChanPixelConv
	{
	public:
		TINDEX _channel;

		SpreadChanTriChanPixelConv(const TINDEX channel)
		{
			_channel = channel;
		}

		Picture::TriChanPixel<TVALUE> convertPixel(const Picture::TriChanPixel<TVALUE>& pixel)
		{
			TVALUE value = pixel.Channels[_channel];
			return Picture::TriChanPixel<TVALUE>(value, value, value);
		}
	};
}

#endif // PICTURESPREADCHANTRICHANPIXELCONV_H
