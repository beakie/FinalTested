#ifndef PICTURESELECTCHANQUADCHANPIXELCONV_H
#define PICTURESELECTCHANQUADCHANPIXELCONV_H

#include "core.h"
#include "common.h"
#include "picture-quadchanpixel.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanQuadChanPixelConv
	{
	public:
		UInt8 _channel;

		SelectChanQuadChanPixelConv(const UInt8 channel)
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
