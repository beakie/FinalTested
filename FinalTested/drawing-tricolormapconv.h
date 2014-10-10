#ifndef DRAWINGTRICOLORMAPCONV_H
#define DRAWINGTRICOLORMAPCONV_H

#include "core.h"
#include "common.h"
#include "drawing-trichanpixel.h"

namespace Drawing
{
	template <typename TUNITINTERVAL, typename TPIXELIN, typename TPIXELOUT>
	class TriColorMapConv
	{
	private:
		const Drawing::TriColorMap<TUNITINTERVAL>* _colorMap; // transform this on population. lowerbound defines offset, upperbound lets calc of multiplication
		TPIXELIN _lowerBound;
		TPIXELIN _upperBound;

		//move lastIndex, spacing etc into here and constructor

	public:
		TriColorMapConv(const Drawing::TriColorMap<TUNITINTERVAL>* colorMap, const TPIXELIN lowerBound, const TPIXELIN upperBound) //should this be input type templates?
		{
			_colorMap = colorMap;
			_lowerBound = lowerBound;
			_upperBound = upperBound;
		}

		Drawing::TriChanPixel<TPIXELOUT> convertPixel(const Float32& value)
		{
			UInt8 lastIndex = _colorMap->Size - 1;

			if (value == _upperBound)
				return Drawing::TriChanPixel<TPIXELOUT>(_colorMap->Values[0][lastIndex], _colorMap->Values[1][lastIndex], _colorMap->Values[2][lastIndex]);

			TUNITINTERVAL spacing = ((TUNITINTERVAL)1 / lastIndex);
			TUNITINTERVAL indexUnrounded = (value - _lowerBound) / spacing;
			UInt8 index = (UInt8)indexUnrounded;

			if (indexUnrounded == index)
				return Drawing::TriChanPixel<TPIXELOUT>(_colorMap->Values[0][index], _colorMap->Values[1][index], _colorMap->Values[2][index]);

			TUNITINTERVAL fromIndexValue = index * spacing;
			TUNITINTERVAL toIndexValue = (index + 1) * spacing;
			TUNITINTERVAL valueDiff = (value - fromIndexValue - _lowerBound) / (toIndexValue - fromIndexValue - _lowerBound);

			TPIXELOUT outLowerBound = Common::getLowerBound<TPIXELOUT>();
			TPIXELOUT outUpperBound = Common::getUpperBound<TPIXELOUT>();

			TUNITINTERVAL channel[3];

			for (UInt8 i = 0; i < 3; i++)
			{
				TUNITINTERVAL fromMapping = _colorMap->Values[i][index];
				TUNITINTERVAL toMapping = _colorMap->Values[i][index + 1];

				if (fromMapping == toMapping)
					channel[i] = (fromMapping * (outUpperBound - outLowerBound)) + outLowerBound;
				else
				{
					TUNITINTERVAL mappingDiff = toMapping - fromMapping;
					TUNITINTERVAL newValue = (mappingDiff * valueDiff) + fromMapping;
					channel[i] = (newValue * (outUpperBound - outLowerBound)) + outLowerBound;
				}
			}

			return Drawing::TriChanPixel<TPIXELOUT>(channel[0], channel[1], channel[2]);
		}
	};

}

#endif // DRAWINGTRICOLORMAPCONV_H
