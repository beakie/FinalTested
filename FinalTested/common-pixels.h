#ifndef COMMONPIXELS_H
#define COMMONPIXELS_H

#include "common-triplechannelpixel.h"

namespace Common
{
	template <typename TVALUE>
	struct Pixels
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

		static TVALUE getHue(const TripleChannelPixel<TVALUE>& pixel)
		{
			return pixel.Channel1;
		}

		static TVALUE getSaturation(const TripleChannelPixel<TVALUE>& pixel)
		{
			return pixel.Channel2;
		}

		static TVALUE getValue(const TripleChannelPixel<TVALUE>& pixel)
		{
			return pixel.Channel3;
		}
	};
}

#endif // COMMONPIXELS_H
