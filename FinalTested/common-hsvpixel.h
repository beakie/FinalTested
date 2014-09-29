#ifndef COMMONHSVPIXEL_H
#define COMMONHSVPIXEL_H

#include "common-triplechannelpixel.h"

namespace Common
{
	template <typename TVALUE>
	struct HSVPixel
	{
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

#endif // COMMONHSVPIXEL_H
