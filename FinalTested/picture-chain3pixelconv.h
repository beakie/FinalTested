#ifndef PICTURECHAIN3PIXELCONV_H
#define PICTURECHAIN3PIXELCONV_H

#include "core.h"
#include "common.h"
#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TVALUEOUT, typename TCONVERTER1, typename TCONVERTER2, typename TCONVERTER3, typename TVALUEIN>
	class Chain3PixelConv
	{
	private:
		TCONVERTER1* _Converter1;
		TCONVERTER2* _Converter2;
		TCONVERTER3* _Converter3;

		Chain3PixelConv(TCONVERTER1* converter1, TCONVERTER2* converter2, TCONVERTER3* converter3)
		{
			_Converter1 = converter1;
			_Converter2 = converter2;
			_Converter3 = converter3;
		}

	public:
		TVALUEOUT convertPixel(const TVALUEIN& pixel)
		{
			return _Converter3->convertPixel(_Converter2->convertPixel(_Converter1->convertPixel(pixel)));
		}
	};

}

#endif // PICTURECHAIN3PIXELCONV_H
