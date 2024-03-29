#ifndef PICTURESPREADCHANQUADCHANPIXELCONV_H
#define PICTURESPREADCHANQUADCHANPIXELCONV_H

#include "common.h"

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

		Common::Vector4<TVALUE> convertPixel(const Common::Vector4<TVALUE>& pixel)
		{
			TVALUE value = pixel.Channels[_channel];
			return Common::Vector4<TVALUE>(value, value, value, value);
		}
	};
}

#endif // PICTURESPREADCHANQUADCHANPIXELCONV_H
