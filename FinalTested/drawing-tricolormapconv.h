#ifndef DRAWINGTRICOLORMAPCONV_H
#define DRAWINGTRICOLORMAPCONV_H

#include "core.h"
#include "common.h"
#include "drawing-trichanpixel.h"

namespace Drawing
{
	template <typename TPIXEL, typename TUNITINTERVAL>
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
			UInt8 size = _colorMap->Size - 1;

			if (value == 1.0)
				return Drawing::TriChanPixel<TPIXEL>(_colorMap->Values[0][size], _colorMap->Values[1][size], _colorMap->Values[2][size]);

			TUNITINTERVAL spacing = ((TUNITINTERVAL)1 / (size - 1));
			UInt8 index = (UInt8)(value / spacing);

			return Drawing::TriChanPixel<TPIXEL>(value, 14, 21);
		}
	};

}

#endif // DRAWINGTRICOLORMAPCONV_H
