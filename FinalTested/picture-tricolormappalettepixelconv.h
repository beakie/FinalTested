#ifndef PICTURETRICOLORMAPPALETTEPIXELCONV_H
#define PICTURETRICOLORMAPPALETTEPIXELCONV_H

#include "core.h"
#include "common.h"

namespace Picture
{
	//template specialization the main function. will be quicker, and end resulting would be the same... code base is bigger but worth every bytes

	template <typename TUNITINTERVAL, typename TPIXELIN, typename TPIXELOUT>
	class TriColorMapPalettePixelConv
	{
	private:
		const TriColorMap<TUNITINTERVAL>* _colorMap; // transform this on population. lowerbound defines offset, upperbound lets calc of multiplication
		FloatMax _inLowerBound;
		FloatMax _inUpperBound;
		FloatMax _inBoundDiff;
		FloatMax _outLowerBound;
		FloatMax _outUpperBound;
		FloatMax _outBoundDiff;
		FloatMax _channel[3]; // this should be color not [3]

	public:
		TriColorMapPalettePixelConv(const TriColorMap<TUNITINTERVAL>* colorMap, const TPIXELIN lowerBound, const TPIXELIN upperBound) //should this be input type templates?
		{
			_colorMap = colorMap;
			_inLowerBound = lowerBound;
			_inUpperBound = upperBound;
			_inBoundDiff = upperBound - lowerBound;
			_outLowerBound = Common::getLowerBound<TPIXELOUT>();
			_outUpperBound = Common::getUpperBound<TPIXELOUT>();
			_outBoundDiff = _outUpperBound - _outLowerBound;
		}

		TriColorMapPalettePixelConv(const TriColorMap<TUNITINTERVAL>* colorMap)
			: TriColorMapPalettePixelConv(colorMap, Common::getLowerBound<TPIXELIN>(), Common::getUpperBound<TPIXELIN>())
		{
		}

		Common::Vector3<TPIXELOUT> convertPixel(const TPIXELIN& value)
		{
			//return Common::Vector3<TPIXELOUT>((_channel[0] * _outBoundDiff) + _outLowerBound,
			//	(_channel[1] * _outBoundDiff) + _outLowerBound,
			//	(_channel[2] * _outBoundDiff) + _outLowerBound);
		}
	};

}

#endif // PICTURETRICOLORMAPPALETTEPIXELCONV_H
