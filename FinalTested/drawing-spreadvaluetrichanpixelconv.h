#ifndef DRAWINGSPREADVALUETRICHANPIXELCONV_H
#define DRAWINGSPREADVALUETRICHANPIXELCONV_H

#include "drawing-trichanpixel.h"

namespace Drawing
{
	template <typename TVALUE, typename TINDEX>
	class SpreadValueTriChanPixelConv
	{
	public:
		Drawing::TriChanPixel<TVALUE> convertPixel(const TVALUE value)
		{
			return Drawing::TriChanPixel<TVALUE>(value, value, value);
		}
	};
}

#endif // DRAWINGSPREADVALUETRICHANPIXELCONV_H
