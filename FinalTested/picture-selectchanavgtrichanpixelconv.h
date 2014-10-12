#ifndef PICTURESELECTCHANAVGTRICHANPIXELCONV_H
#define PICTURESELECTCHANAVGTRICHANPIXELCONV_H

#include "core.h"
#include "common.h"
#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE>
	class SelectChanAvgTriChanPixelConv
	{
	public:
		TVALUE convertPixel(const Picture::TriChanPixel<TVALUE>& pixel)
		{
			return (TVALUE)Common::Math::round((Common::FloatMax)(pixel.Channels[0] + pixel.Channels[1] + pixel.Channels[2]) / 3);
		}
	};
}

#endif // PICTURESELECTCHANAVGTRICHANPIXELCONV_H
