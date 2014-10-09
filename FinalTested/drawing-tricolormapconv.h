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
		const Drawing::TriColorMap<TUNITINTERVAL>* _colorMap; // transform this on population. lowerbound defines offset, upperbound lets calc of multiplication

		//move lastIndex, spacing etc into here and constructor

	public:
		TriColorMapConv(const Drawing::TriColorMap<TUNITINTERVAL>* colorMap, TPIXEL lowerBound, TPIXEL upperBound) //should this be input type templates?
		{
			_colorMap = colorMap;
		}

		Drawing::TriChanPixel<TPIXEL> convertPixel(const TUNITINTERVAL& value)
		{
			UInt8 lastIndex = _colorMap->Size - 1;

			if (value == 1.0) // This will ensure index is always 1 less than the highest index
				return Drawing::TriChanPixel<TPIXEL>(_colorMap->Values[0][lastIndex], _colorMap->Values[1][lastIndex], _colorMap->Values[2][lastIndex]);

			TUNITINTERVAL spacing = ((TUNITINTERVAL)1 / lastIndex);
			TUNITINTERVAL indexUnrounded = value / spacing;
			UInt8 index = (UInt8)indexUnrounded;

			if (indexUnrounded == index)
				return Drawing::TriChanPixel<TPIXEL>(_colorMap->Values[0][index], _colorMap->Values[1][index], _colorMap->Values[2][index]);

			TUNITINTERVAL fromIndexValue = index * spacing;
			TUNITINTERVAL toIndexValue = (index + 1) * spacing;
			TUNITINTERVAL valueDiff = (value - fromIndexValue) / (toIndexValue - fromIndexValue);

			TUNITINTERVAL channel[3];

			for (UInt8 i = 0; i < 3; i++)
			{
				TUNITINTERVAL fromMapping = _colorMap->Values[i][index];
				TUNITINTERVAL toMapping = _colorMap->Values[i][index + 1];

				if (fromMapping == toMapping)
					channel[i] = fromMapping;
				else
				{
					TUNITINTERVAL mappingDiff = toMapping - fromMapping;
					TUNITINTERVAL newValue = (mappingDiff * valueDiff) + fromMapping;
					channel[i] = newValue;
				}
			}

			return Drawing::TriChanPixel<TPIXEL>(channel[0], channel[1], channel[2]);
		}
	};

}

#endif // DRAWINGTRICOLORMAPCONV_H
