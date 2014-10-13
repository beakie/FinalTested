#ifndef PICTUREQUADCOLORMAPCONV_H
#define PICTUREQUADCOLORMAPCONV_H

#include "core.h"
#include "common.h"
#include "picture-quadchanpixel.h"

namespace Picture
{
	template <typename TUNITINTERVAL, typename TPIXELIN, typename TPIXELOUT>
	class QuadColorMapConv
	{
	private:
		const Picture::QuadColorMap<TUNITINTERVAL>* _colorMap; // transform this on population. lowerbound defines offset, upperbound lets calc of multiplication
		TPIXELIN _inLowerBound;
		TPIXELIN _inUpperBound;
		TPIXELIN _inBoundDiff;
		TPIXELOUT _outLowerBound;
		TPIXELOUT _outUpperBound;
		TPIXELOUT _outBoundDiff;
		UInt8 _lastIndex;
		TUNITINTERVAL _spacing;
		TUNITINTERVAL _indexUnrounded;
		UInt8 _index;
		TUNITINTERVAL _fromIndexValue;
		TUNITINTERVAL _toIndexValue;
		TUNITINTERVAL _valueDiff;
		TUNITINTERVAL _fromMapping;
		TUNITINTERVAL _toMapping;
		TUNITINTERVAL _newValue;
		TPIXELOUT _channel[4];

		// move _lastIndex, _spacing etc into here and constructor

		// *****************
		// you NEED to add rounding when do data conversion to TPIXELOUT or it will always round down with in!
		// *****************

		// when this is finished... copy it to quad

		// move all variables to class so that no reallocation of memory is needed for each pixel?

	public:
		QuadColorMapConv(const Picture::QuadColorMap<TUNITINTERVAL>* colorMap, const TPIXELIN lowerBound, const TPIXELIN upperBound) //should this be input type templates?
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

		QuadColorMapConv(const Picture::QuadColorMap<TUNITINTERVAL>* colorMap)
			: QuadColorMapConv(colorMap, Common::getLowerBound<TPIXELIN>(), Common::getUpperBound<TPIXELIN>())
		{
		}

		Picture::QuadChanPixel<TPIXELOUT> convertPixel(const TPIXELIN& value)
		{
			if (value == _inUpperBound)
				return Picture::QuadChanPixel<TPIXELOUT>(_colorMap->Values[0][_lastIndex], _colorMap->Values[1][_lastIndex], _colorMap->Values[2][_lastIndex], _colorMap->Values[3][_lastIndex]);

			_indexUnrounded = (value - _inLowerBound) / _spacing;
			_index = (UInt8)_indexUnrounded;

			if (_indexUnrounded == _index)
				return Picture::QuadChanPixel<TPIXELOUT>(_colorMap->Values[0][_index], _colorMap->Values[1][_index], _colorMap->Values[2][_index], _colorMap->Values[3][_index]);

			_fromIndexValue = _index * _spacing;
			_toIndexValue = (_index + 1) * _spacing;
			_valueDiff = (value - _fromIndexValue - _inLowerBound) / (_toIndexValue - _fromIndexValue - _inLowerBound);

			for (UInt8 i = 0; i < 3; i++)
			{
				_fromMapping = _colorMap->Values[i][_index];
				_toMapping = _colorMap->Values[i][_index + 1];

				if (_fromMapping == _toMapping)
					_channel[i] = (TPIXELOUT)Common::Math::round(((Float32)_fromMapping * (1 / _inBoundDiff) * _outBoundDiff) + _outLowerBound); // round all this
				else
				{
					_newValue = ((_toMapping - _fromMapping) * _valueDiff) + _fromMapping;
					_channel[i] = (TPIXELOUT)Common::Math::round(((Float32)_newValue * (1 / _inBoundDiff) * _outBoundDiff) + _outLowerBound); // round all this
				}
			}

			return Picture::QuadChanPixel<TPIXELOUT>(_channel[0], _channel[1], _channel[2], _channel[3]);
		}
	};

}

#endif // PICTUREQUADCOLORMAPCONV_H