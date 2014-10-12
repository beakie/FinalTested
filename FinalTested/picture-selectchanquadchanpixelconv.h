#ifndef PICTURESELECTCHANQUADCHANPIXELCONV_H
#define PICTURESELECTCHANQUADCHANPIXELCONV_H

#include "core.h"
#include "common.h"
#include "picture-quadchanpixel.h"

namespace Picture
{
	template <typename TVALUE, typename TINDEX>
	class SelectChanQuadChanPixelConv
	{
	public:
		TINDEX _channel;

		SelectChanQuadChanPixelConv(const TINDEX channel)
		{
			_channel = channel;
		}

		TVALUE convertPixel(const Picture::QuadChanPixel<TVALUE>& pixel)
		{
			return pixel.Channels[_channel];
		}
	};
}

#endif // PICTURESELECTCHANQUADCHANPIXELCONV_H
