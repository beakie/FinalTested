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
		TVALUE convertPixel(const Picture::TriChanPixel<TVALUE>& value)
		{
			return (TVALUE)Common::Math::round((Common::FloatMax)(value.Channels[0] + value.Channels[0] + value.Channels[0]) / 3);
		}
	};
}

#endif // PICTURESELECTRGBPIXELINTENSITYCONV_H
