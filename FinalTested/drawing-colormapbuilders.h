#ifndef DRAWINGCOLORMAPBUILDER_H
#define DRAWINGCOLORMAPBUILDER_H

#include "core.h"
#include "common.h"

#include "drawing-triplechannelcolormap.h"

namespace Drawing
{
	template <typename TPIXELVALUE, typename TUNITINTERVAL>
	class ColorMapBuilders
	{

	public:
		static TripleChannelColorMap<TPIXELVALUE, TUNITINTERVAL> getRGBColorMapJet()
		{
			TripleChannelColorMap<TPIXELVALUE, TUNITINTERVAL> map(10);

			map.Values[0][0] = 0.00000;
			map.Values[0][1] = 0.00000;
			map.Values[0][2] = 0.00000;
			map.Values[0][3] = 0.00000;
			map.Values[0][4] = 0.27778;
			map.Values[0][5] = 0.72222;
			map.Values[0][6] = 1.00000;
			map.Values[0][7] = 1.00000;
			map.Values[0][8] = 0.94444;
			map.Values[0][9] = 0.50000;

			map.Values[1][0] = 0.00000;
			map.Values[1][1] = 0.00000;
			map.Values[1][2] = 0.38889;
			map.Values[1][3] = 0.83333;
			map.Values[1][4] = 1.00000;
			map.Values[1][5] = 1.00000;
			map.Values[1][6] = 0.83333;
			map.Values[1][7] = 0.38889;
			map.Values[1][8] = 0.00000;
			map.Values[1][9] = 0.00000;

			map.Values[2][0] = 0.50000;
			map.Values[2][1] = 0.94444;
			map.Values[2][2] = 1.00000;
			map.Values[2][3] = 1.00000;
			map.Values[2][4] = 0.72222;
			map.Values[2][5] = 0.27778;
			map.Values[2][6] = 0.00000;
			map.Values[2][7] = 0.00000;
			map.Values[2][8] = 0.00000;
			map.Values[2][9] = 0.00000;

			return map;
		}

	};

	typedef ColorMapBuilders<UInt_8, Float_32> ColorMapBuilders_8_32;
}

#endif // DRAWINGCOLORMAPBUILDER_H
