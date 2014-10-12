#ifndef PICTURESELECTCHANTRICHANPIXELCONV_H
#define PICTURESELECTCHANTRICHANPIXELCONV_H

#include "core.h"
#include "common.h"
#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanTriChanPixelConv
	{
	public:
		UInt8 _channel;

		SelectChanTriChanPixelConv(const UInt8 channel)
		{
			_channel = channel;
		}

		TVALUE convertPixel(const Picture::TriChanPixel<TVALUE>& pixel)
		{
			return pixel.Channels[_channel];
		}
	};
}

#endif // PICTURESELECTCHANTRICHANPIXELCONV_H
