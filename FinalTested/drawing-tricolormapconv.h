#ifndef DRAWINGTRICOLORMAPCONV_H
#define DRAWINGTRICOLORMAPCONV_H

#include "core.h"
#include "common.h"
#include "drawing-trichanpixel.h"

namespace Drawing
{
	template <typename TUNITINTERVAL, typename TPIXEL>
	class TriColorMapConv
	{
	private:
		const Drawing::TriColorMap<TUNITINTERVAL>* _colorMap;

	public:
		TriColorMapConv(const Drawing::TriColorMap<TUNITINTERVAL>* colorMap)
		{
			_colorMap = colorMap;
		}

		Drawing::TriChanPixel<TPIXEL> convertPixel(const TUNITINTERVAL& value)
		{
			UInt8 lastIndex = _colorMap->Size - 1;

			if (value == 1.0) // This will ensure index is always 1 less than the highest index
				return Drawing::TriChanPixel<TPIXEL>(_colorMap->Values[0][lastIndex], _colorMap->Values[1][lastIndex], _colorMap->Values[2][lastIndex]);

			TUNITINTERVAL spacing = ((TUNITINTERVAL)1 / (lastIndex - 1));
			UInt8 index = (UInt8)(value / spacing);

			//TUNITINTERVAL from = _colorMap->Values[0][index];
			//TUNITINTERVAL to = _colorMap->Values[0][index + 1];
			//TUNITINTERVAL difference = (value - from) / (to - from);

			return Drawing::TriChanPixel<TPIXEL>(value, 14, 21);
		}
	};

}

#endif // DRAWINGTRICOLORMAPCONV_H
