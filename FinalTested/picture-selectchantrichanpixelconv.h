#ifndef PICTURESELECTCHANTRICHANPIXELCONV_H
#define PICTURESELECTCHANTRICHANPIXELCONV_H

#include "core.h"
#include "common.h"
#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE, typename TINDEX>
	class SelectChanTriChanPixelConv
	{
	public:
		TINDEX _channel;

		SelectChanTriChanPixelConv(const TINDEX channel)
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
