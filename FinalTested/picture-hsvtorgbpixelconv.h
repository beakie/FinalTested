#ifndef PICTUREHSVTORGBPIXELCONV_H
#define PICTUREHSVTORGBPIXELCONV_H

#include "core.h"
#include "common.h"
#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE>
	class HsvToRgbPixelConv
	{
	public:
		Picture::TriChanPixel<TVALUE> convertPixel(const Picture::TriChanPixel<TVALUE>& pixel)
		{

		}
	};

}

#endif // PICTUREHSVTORGBPIXELCONV_H

//http://www.cs.rit.edu/~ncs/color/t_convert.html#RGB%20to%20HSV%20&%20HSV%20to%20RGB
