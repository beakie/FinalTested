#ifndef PICTUREQUADCOLORMAPPIXELCONV_H
#define PICTUREQUADCOLORMAPPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	//template specialization the main function. will be quicker, and end resulting would be the same... code base is bigger but worth every bytes

	template <typename TUNITINTERVAL, typename TPIXELIN, typename TPIXELOUT>
	class QuadColorMapPixelConv
	{
	private:
		const QuadColorMap<TUNITINTERVAL>* _colorMap; // transform this on population. lowerbound defines offset, upperbound lets calc of multiplication
		FloatMax _inLowerBound;
		FloatMax _inUpperBound;
		FloatMax _inBoundDiff;
		FloatMax _outLowerBound;
		FloatMax _outUpperBound;
		FloatMax _outBoundDiff;
		UInt8 _lastIndex;
		TUNITINTERVAL _spacing;
		FloatMax _indexUnfloored;
		UInt8 _index;
		TUNITINTERVAL _fromMapping;
		TUNITINTERVAL _toMapping;
		FloatMax _toUnitInterval;
		FloatMax _diffUnitInterval;
		FloatMax _channel[4];

	public:
		QuadColorMapPixelConv(const QuadColorMap<TUNITINTERVAL>* colorMap, const TPIXELIN lowerBound, const TPIXELIN upperBound) //should this be input type templates?
		{
			_colorMap = colorMap;
			_inLowerBound = lowerBound;
			_inUpperBound = upperBound;
			_inBoundDiff = upperBound - lowerBound;
			_lastIndex = _colorMap->Size - 1;
			_spacing = ((TUNITINTERVAL)1 / _lastIndex);
			_outLowerBound = Common::getLowerBound<TPIXELOUT>();
			_outUpperBound = Common::getUpperBound<TPIXELOUT>();
			_outBoundDiff = _outUpperBound - _outLowerBound;
		}

		QuadColorMapPixelConv(const QuadColorMap<TUNITINTERVAL>* colorMap)
			: QuadColorMapPixelConv(colorMap, Common::getLowerBound<TPIXELIN>(), Common::getUpperBound<TPIXELIN>())
		{
		}

		Common::Vector4<TPIXELOUT> convertPixel(const TPIXELIN& value)
		{
			if (value == _inUpperBound)
				return Common::Vector4<TPIXELOUT>((_colorMap->Values[0][_lastIndex] * _outBoundDiff) + _outLowerBound,
												(_colorMap->Values[1][_lastIndex] * _outBoundDiff) + _outLowerBound,
												(_colorMap->Values[2][_lastIndex] * _outBoundDiff) + _outLowerBound,
												(_colorMap->Values[3][_lastIndex] * _outBoundDiff) + _outLowerBound);

			_indexUnfloored = ((FloatMax)value - _inLowerBound) / _inBoundDiff / _spacing;
			_index = (UInt8)_indexUnfloored;

			if (_indexUnfloored == _index)
				return Common::Vector4<TPIXELOUT>((_colorMap->Values[0][_index] * _outBoundDiff) + _outLowerBound,
												(_colorMap->Values[1][_index] * _outBoundDiff) + _outLowerBound,
												(_colorMap->Values[2][_index] * _outBoundDiff) + _outLowerBound,
												(_colorMap->Values[3][_index] * _outBoundDiff) + _outLowerBound);


			_toUnitInterval = (_index + 1) * _spacing;
			_diffUnitInterval = 1 - ((_toUnitInterval - (((FloatMax)value - _inLowerBound) / _inBoundDiff)) / (_toUnitInterval - (_index * _spacing)));

			for (UInt8 i = 0; i < 4; i++)
			{
				_fromMapping = _colorMap->Values[i][_index];
				_toMapping = _colorMap->Values[i][_index + 1];

				if (_fromMapping == _toMapping)
					_channel[i] = _fromMapping;
				else
					_channel[i] = ((_toMapping - _fromMapping) * _diffUnitInterval) + _fromMapping;
			}

			return Common::Vector4<TPIXELOUT>((_channel[0] * _outBoundDiff) + _outLowerBound,
											(_channel[1] * _outBoundDiff) + _outLowerBound,
											(_channel[2] * _outBoundDiff) + _outLowerBound,
											(_channel[3] * _outBoundDiff) + _outLowerBound);
		}
	};

}

#endif // PICTUREQUADCOLORMAPPIXELCONV_H