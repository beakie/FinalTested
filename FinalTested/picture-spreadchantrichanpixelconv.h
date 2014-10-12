#ifndef PICTURESPREADCHANTRICHANPIXELCONV_H
#define PICTURESPREADCHANTRICHANPIXELCONV_H

#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE>
	class SpreadChanTriChanPixelConv
	{
	public:
		UInt8 _channel;

		SpreadChanTriChanPixelConv(const UInt8 channel)
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
