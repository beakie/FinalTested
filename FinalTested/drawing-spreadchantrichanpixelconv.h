#ifndef DRAWINGSPREADCHANTRICHANPIXELCONV_H
#define DRAWINGSPREADCHANTRICHANPIXELCONV_H

#include "drawing-trichanpixel.h"

namespace Drawing
{
	template <typename TVALUE, typename TINDEX>
	class SpreadChanTriChanPixelConv
	{
	public:
		TINDEX _channel;

		SelectChanTriChanPixelConv(const TINDEX channel)
		{
			_channel = channel;
		}

		Drawing::TriChanPixel<TVALUE> convertPixel(const Drawing::TriChanPixel<TVALUE>& pixel)
		{
			TVALUE value = pixel.Channels[_channel];
			return Drawing::TriChanPixel<TVALUE>(value, value, value);
		}
	};
}

#endif // DRAWINGSPREADCHANTRICHANPIXELCONV_H
