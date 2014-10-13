#ifndef COMMONDUMBCASTPIXELCONV_H
#define COMMONDUMBCASTPIXELCONV_H

#include "core.h"

namespace Common
{
	template <typename TIN, typename TOUT>
	class DumbCastPixelConv
	{
	public:
		TOUT convertPixel(const TIN& pixel)
		{
			return (TOUT)pixel;
		}
	};
}

#endif // COMMONDUMBCASTPIXELCONV_H
