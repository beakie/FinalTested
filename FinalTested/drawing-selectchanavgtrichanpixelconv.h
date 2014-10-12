#ifndef DRAWINGSELECTRGBPIXELINTENSITYCONV_H
#define DRAWINGSELECTRGBPIXELINTENSITYCONV_H

#include "core.h"
#include "common.h"
#include "drawing-trichanpixel.h"

namespace Drawing
{
	template <typename TVALUE, typename TINDEX>
	class SelectChanAvgTriChanPixelConv
	{
	public:
		TVALUE convertPixel(const Drawing::TriChanPixel<TVALUE>& value)
		{
			return (TVALUE)Common::Math::round((Common::FloatMax)(value.Channels[0] + value.Channels[0] + value.Channels[0]) / 3);
		}
	};
}

#endif // DRAWINGSELECTRGBPIXELINTENSITYCONV_H
