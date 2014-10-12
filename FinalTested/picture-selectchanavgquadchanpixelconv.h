#ifndef PICTURESELECTRGBPIXELINTENSITYCONV_H
#define PICTURESELECTRGBPIXELINTENSITYCONV_H

#include "core.h"
#include "common.h"
#include "picture-quadchanpixel.h"

namespace Picture
{
	template <typename TVALUE, typename TINDEX>
	class SelectChanAvgQuadChanPixelConv
	{
	public:
		TVALUE convertPixel(const Picture::QuadChanPixel<TVALUE>& pixel)
		{
			return (TVALUE)Common::Math::round((Common::FloatMax)(pixel.Channels[0] + pixel.Channels[1] + pixel.Channels[2] + pixel.Channels[3]) / 4);
		}
	};
}

#endif // PICTURESELECTRGBPIXELINTENSITYCONV_H
