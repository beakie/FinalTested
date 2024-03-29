#ifndef PICTUREARGBTORGBPIXELCONV_H
#define PICTUREARGBTORGBPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TVALUE>
	class ArgbToRgbPixelConv
	{
	public:
		Common::Vector3<TVALUE> convertPixel(const Common::Vector4<TVALUE>& pixel)
		{
			return Common::Vector3<TVALUE>(pixel.Values[1], pixel.Values[2], pixel.Values[3]);
		}
	};

}

#endif // PICTUREARGBTORGBPIXELCONV_H

