#ifndef PICTURETRICOLORMAPCONV_H
#define PICTURETRICOLORMAPCONV_H

#include "core.h"
#include "common.h"
#include "picture-trichanpixel.h"

namespace Picture
{
	//template specialization the main function. will be quicker, and end resulting would be the same... code base is bigger but worth every bytes

	template <typename TUNITINTERVAL, typename TPIXELIN, typename TPIXELOUT>
	class TriColorMapConv
	{
	private:
		const Picture::TriColorMap<TUNITINTERVAL>* _colorMap; // transform this on population. lowerbound defines offset, upperbound lets calc of multiplication
		FloatMax _inLowerBound;
		FloatMax _inUpperBound;
		FloatMax _inBoundDiff;
		FloatMax _outLowerBound;
		FloatMax _outUpperBound;
		FloatMax _outBoundDiff;
		UInt8 _lastIndex;
		TUNITINTERVAL _spacing;
		TUNITINTERVAL _indexUnfloored;
		UInt8 _index;
		TUNITINTERVAL _fromMapping;
		TUNITINTERVAL _toMapping;
		TUNITINTERVAL _newValue;
		TPIXELOUT _channel[3];

	public:
		TriColorMapConv(const Picture::TriColorMap<TUNITINTERVAL>* colorMap, const TPIXELIN lowerBound, const TPIXELIN upperBound) //should this be input type templates?
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

		TriColorMapConv(const Picture::TriColorMap<TUNITINTERVAL>* colorMap)
			: TriColorMapConv(colorMap, Common::getLowerBound<TPIXELIN>(), Common::getUpperBound<TPIXELIN>())
		{
		}

		Picture::TriChanPixel<TPIXELOUT> convertPixel(const TPIXELIN& value)
		{
			if (value == _inUpperBound)
				return Picture::TriChanPixel<TPIXELOUT>((_colorMap->Values[0][_lastIndex] * _outBoundDiff) + _outLowerBound,
														(_colorMap->Values[1][_lastIndex] * _outBoundDiff) + _outLowerBound,
														(_colorMap->Values[2][_lastIndex] * _outBoundDiff) + _outLowerBound);

			_indexUnfloored = ((FloatMax)value - _inLowerBound) / _inBoundDiff / _spacing;
			_index = (UInt8)_indexUnfloored;

			if (_indexUnfloored == _index)
				return Picture::TriChanPixel<TPIXELOUT>((_colorMap->Values[0][_index] * _outBoundDiff) + _outLowerBound,
														(_colorMap->Values[1][_index] * _outBoundDiff) + _outLowerBound,
														(_colorMap->Values[2][_index] * _outBoundDiff) + _outLowerBound);


			FloatMax _valueUnitInterval = ((FloatMax)value - _inLowerBound) / _inBoundDiff;
			FloatMax _fromUnitInterval = _index * _spacing;
			FloatMax _toUnitInterval = (_index + 1) * _spacing;
			FloatMax _diffUnitInterval = (1 - (_valueUnitInterval - _fromUnitInterval) / (_toUnitInterval - _fromUnitInterval));

			for (UInt8 i = 0; i < 3; i++)
			{
				_fromMapping = _colorMap->Values[i][_index];
				_toMapping = _colorMap->Values[i][_index + 1];

				if (_fromMapping == _toMapping)
					_newValue = _fromMapping;
				else
					_newValue = ((_toMapping - _fromMapping) * _diffUnitInterval) + _fromMapping;

				_channel[i] = (TPIXELOUT)Common::round(((Float32)_newValue * _outBoundDiff) + _outLowerBound); // round all this (as will always be out going int?)
			}

			return Picture::TriChanPixel<TPIXELOUT>((_channel[0] * _outBoundDiff) + _outLowerBound,
													(_channel[1] * _outBoundDiff) + _outLowerBound,
													(_channel[2] * _outBoundDiff) + _outLowerBound);
		}
	};

}

#endif // PICTURETRICOLORMAPCONV_H
