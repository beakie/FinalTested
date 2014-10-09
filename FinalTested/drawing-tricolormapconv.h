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

		//move lastIndex, spacing etc into here and constructor

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

			TUNITINTERVAL spacing = ((TUNITINTERVAL)1 / lastIndex);
			TUNITINTERVAL indexUnrounded = value / spacing;
			UInt8 index = (UInt8)indexUnrounded;

			if (indexUnrounded == index)
				return Drawing::TriChanPixel<TPIXEL>(_colorMap->Values[0][index], _colorMap->Values[1][index], _colorMap->Values[2][index]);

			TUNITINTERVAL channel1;
			TUNITINTERVAL channel2;
			TUNITINTERVAL channel3;

			TUNITINTERVAL fromIndexValue = index * spacing;
			TUNITINTERVAL toIndexValue = (index + 1) * spacing;
			TUNITINTERVAL valueDiff = (value - fromIndexValue) / (toIndexValue - fromIndexValue);

			//// for each channel

			TUNITINTERVAL fromMapping1 = _colorMap->Values[0][index];
			TUNITINTERVAL toMapping1 = _colorMap->Values[0][index + 1];

			if (fromMapping1 == toMapping1)
				channel1 = fromMapping1;
			else
			{
				TUNITINTERVAL mappingDiff1 = toMapping1 - fromMapping1;
				TUNITINTERVAL newValue1 = (mappingDiff1 * valueDiff) + fromMapping1;
				channel1 = newValue1;
			}

			////

			return Drawing::TriChanPixel<TPIXEL>(channel1, channel2, channel3);
		}
	};

}

#endif // DRAWINGTRICOLORMAPCONV_H
