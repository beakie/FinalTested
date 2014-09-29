#ifndef COMMONRGBPIXEL_H
#define COMMONRGBPIXEL_H

#include "common-triplechannelpixel.h"

namespace Common
{
	template <typename TVALUE>
	struct RGBPixel
	{
		static TVALUE getRed(const TripleChannelPixel<TVALUE>& pixel)
		{
			return pixel.Channel1;
		}

		static TVALUE getBlue(const TripleChannelPixel<TVALUE>& pixel)
		{
			return pixel.Channel2;
		}

		static TVALUE getGreen(const TripleChannelPixel<TVALUE>& pixel)
		{
			return pixel.Channel3;
		}
	};
}

#endif // COMMONRGBPIXEL_H
