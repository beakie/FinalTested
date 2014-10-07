#ifndef DRAWINGCOLORMAPBUILDER_H
#define DRAWINGCOLORMAPBUILDER_H

#include "core.h"
#include "common.h"

#include "drawing-triplechannelcolormap.h"

namespace Drawing
{
	template <typename TUNITINTERVAL>
	class ColorMapBuilders
	{

	public:
		static TripleChannelColorMap<TUNITINTERVAL> getRGBColorMapJet()
		{
			TripleChannelColorMap<TUNITINTERVAL> map(9);

			map.Values[0][0] = 0.0;
			map.Values[0][1] = 0.0;
			map.Values[0][2] = 0.0;
			map.Values[0][3] = 0.0;
			map.Values[0][4] = 0.5;
			map.Values[0][5] = 1.0;
			map.Values[0][6] = 1.0;
			map.Values[0][7] = 1.0;
			map.Values[0][8] = 0.5;

			map.Values[1][0] = 0.0;
			map.Values[1][1] = 0.0;
			map.Values[1][2] = 0.5;
			map.Values[1][3] = 1.0;
			map.Values[1][4] = 1.0;
			map.Values[1][5] = 1.0;
			map.Values[1][6] = 0.5;
			map.Values[1][7] = 0.0;
			map.Values[1][8] = 0.0;

			map.Values[2][0] = 0.5;
			map.Values[2][1] = 1.0;
			map.Values[2][2] = 1.0;
			map.Values[2][3] = 1.0;
			map.Values[2][4] = 0.5;
			map.Values[2][5] = 0.0;
			map.Values[2][6] = 0.0;
			map.Values[2][7] = 0.0;
			map.Values[2][9] = 0.0;

			return map;
		}

	};

	typedef ColorMapBuilders<Float_32> ColorMapBuilders_32;
}

#endif // DRAWINGCOLORMAPBUILDER_H
