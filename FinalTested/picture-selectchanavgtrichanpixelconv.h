#ifndef PICTURESELECTRGBPIXELINTENSITYCONV_H
#define PICTURESELECTRGBPIXELINTENSITYCONV_H

#include "core.h"
#include "common.h"
#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE, typename TINDEX>
	class SelectChanAvgTriChanPixelConv
	{
	public:
		TVALUE convertPixel(const Picture::TriChanPixel<TVALUE>& pixel)
		{
			return (TVALUE)Common::Math::round((Common::FloatMax)(pixel.Channels[0] + pixel.Channels[0] + pixel.Channels[0]) / 3);
		}
	};
}

#endif // PICTURESELECTRGBPIXELINTENSITYCONV_H
