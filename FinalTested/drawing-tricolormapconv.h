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
		TPIXELIN _inLowerBound;
		TPIXELIN _inUpperBound;
		TPIXELIN _inBoundDiff;
		UInt8 _lastIndex;
		TUNITINTERVAL _spacing;
		TPIXELOUT _outLowerBound;
		TPIXELOUT _outUpperBound;
		TPIXELOUT _outBoundDiff;

		//move _lastIndex, _spacing etc into here and constructor

		// *****************
		// you NEED to add rounding when do data conversion to TPIXELOUT or it will always round down with in!
		// *****************

		//when this is finished... copy it to quad

	public:
		TriColorMapConv(const Drawing::TriColorMap<TUNITINTERVAL>* colorMap, const TPIXELIN lowerBound, const TPIXELIN upperBound) //should this be input type templates?
		{
			_colorMap = colorMap;
			_inLowerBound = lowerBound;
			_inUpperBound = upperBound;
			_inBoundDiff = upperBound - lowerBound;  //?
			_lastIndex = _colorMap->Size - 1;
			_spacing = ((TUNITINTERVAL)1 / _lastIndex);
			_outLowerBound = Common::getLowerBound<TPIXELOUT>();
			_outUpperBound = Common::getUpperBound<TPIXELOUT>();
			_outBoundDiff = _outUpperBound - _outLowerBound;
		}

		TriColorMapConv(const Drawing::TriColorMap<TUNITINTERVAL>* colorMap)
			: TriColorMapConv(colorMap, Common::getLowerBound<TPIXELIN>(), Common::getUpperBound<TPIXELIN>())
		{
		}

		Drawing::TriChanPixel<TPIXELOUT> convertPixel(const Float32& value)
		{
			if (value == _inUpperBound)
				return Drawing::TriChanPixel<TPIXELOUT>(_colorMap->Values[0][_lastIndex], _colorMap->Values[1][_lastIndex], _colorMap->Values[2][_lastIndex]);

			TUNITINTERVAL indexUnrounded = (value - _inLowerBound) / _spacing;
			UInt8 index = (UInt8)indexUnrounded;

			if (indexUnrounded == index)
				return Drawing::TriChanPixel<TPIXELOUT>(_colorMap->Values[0][index], _colorMap->Values[1][index], _colorMap->Values[2][index]);

			TUNITINTERVAL fromIndexValue = index * _spacing;
			TUNITINTERVAL toIndexValue = (index + 1) * _spacing;
			TUNITINTERVAL valueDiff = (value - fromIndexValue - _inLowerBound) / (toIndexValue - fromIndexValue - _inLowerBound);

			TPIXELOUT channel[3];

			for (UInt8 i = 0; i < 3; i++)
			{
				TUNITINTERVAL fromMapping = _colorMap->Values[i][index];
				TUNITINTERVAL toMapping = _colorMap->Values[i][index + 1];

				if (fromMapping == toMapping)
					channel[i] = ((Float32)fromMapping * (1 / _inBoundDiff) * _outBoundDiff) + _outLowerBound; // round all this
				else
				{
					TUNITINTERVAL newValue = ((toMapping - fromMapping) * valueDiff) + fromMapping;
					channel[i] = ((Float32)newValue * (1 / _inBoundDiff) * _outBoundDiff) + _outLowerBound; // round all this
				}
			}

			return Drawing::TriChanPixel<TPIXELOUT>(channel[0], channel[1], channel[2]);
		}
	};

}

#endif // DRAWINGTRICOLORMAPCONV_H
