#ifndef DRAWINGQUADCOLORMAPCONV_H
#define DRAWINGQUADCOLORMAPCONV_H

#include "core.h"
#include "common.h"
#include "drawing-Quadchanpixel.h"

namespace Drawing
{
	template <typename TUNITINTERVAL, typename TPIXEL>
	class QuadColorMapConv
	{
	private:
		const Drawing::QuadColorMap<TUNITINTERVAL>* _colorMap;

	public:
		QuadColorMapConv(const Drawing::QuadColorMap<TUNITINTERVAL>* colorMap)
		{
			_colorMap = colorMap;
		}

		Drawing::QuadChanPixel<TPIXEL> convertPixel(const TUNITINTERVAL& value)
		{
			UInt8 size = _colorMap->Size - 1;

			if (value == 1.0)
				return Drawing::QuadChanPixel<TPIXEL>(_colorMap->Values[0][size], _colorMap->Values[1][size], _colorMap->Values[2][size], _colorMap->Values[3][size]);

			TUNITINTERVAL spacing = ((TUNITINTERVAL)1 / (size - 1));
			UInt8 index = (UInt8)(value / spacing);

			return Drawing::QuadChanPixel<TPIXEL>(value, 14, 21, 28);
		}
	};

}

#endif // DRAWINGQUADCOLORMAPCONV_H
