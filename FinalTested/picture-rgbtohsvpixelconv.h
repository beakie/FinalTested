#ifndef PICTURERGBTOHSVPIXELCONV_H
#define PICTURERGBTOHSVPIXELCONV_H

#include "core.h"
#include "common.h"
#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUE>
	class RgbToHsvPixelConv
	{
	public:
		Picture::TriChanPixel<TVALUE> convertPixel(const Picture::TriChanPixel<TVALUE>& pixel)
		{

		}
	};

}

#endif // PICTURERGBTOHSVPIXELCONV_H

//http://www.cs.rit.edu/~ncs/color/t_convert.html#RGB%20to%20HSV%20&%20HSV%20to%20RGB
