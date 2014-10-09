#ifndef DRAWINGCOLORMAPS_H
#define DRAWINGCOLORMAPS_H

#include "core.h"
#include "common.h"

#include "drawing-tricolormap.h"

namespace Drawing
{
	template <typename TUNITINTERVAL>
	class ColorMaps
	{

	public:
		static TriColorMap<TUNITINTERVAL> getRGBJet()
		{
			TriColorMap<TUNITINTERVAL> map(9);

			map.Values[0][0] = map.Values[0][1] = map.Values[0][2] = map.Values[0][3] = 0.0;
			map.Values[0][4] = 0.5;
			map.Values[0][5] = map.Values[0][6] = map.Values[0][7] = 1.0;
			map.Values[0][8] = 0.5;

			map.Values[1][0] = map.Values[1][1] = 0.0;
			map.Values[1][2] = 0.5;
			map.Values[1][3] = map.Values[1][4] = map.Values[1][5] = 1.0;
			map.Values[1][6] = 0.5;
			map.Values[1][7] = map.Values[1][8] = 0.0;

			map.Values[2][0] = 0.5;
			map.Values[2][1] = map.Values[2][2] = map.Values[2][3] = 1.0;
			map.Values[2][4] = 0.5;
			map.Values[2][5] = map.Values[2][6] = map.Values[2][7] = map.Values[2][8] = 0.0;

			return map;
		}

	};

}

#endif // DRAWINGCOLORMAPS_H
