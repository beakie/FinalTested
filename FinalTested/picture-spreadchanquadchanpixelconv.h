#ifndef PICTURESPREADCHANQUADCHANPIXELCONV_H
#define PICTURESPREADCHANQUADCHANPIXELCONV_H

#include "picture-quadchanpixel.h"

namespace Picture
{
	template <typename TVALUE>
	class SpreadChanQuadChanPixelConv
	{
	public:
		UInt8 _channel;

		SpreadChanQuadChanPixelConv(const UInt8 channel)
		{
			_channel = channel;
		}

		Picture::QuadChanPixel<TVALUE> convertPixel(const Picture::QuadChanPixel<TVALUE>& pixel)
		{
			TVALUE value = pixel.Channels[_channel];
			return Picture::QuadChanPixel<TVALUE>(value, value, value, value);
		}
	};
}

#endif // PICTURESPREADCHANQUADCHANPIXELCONV_H
