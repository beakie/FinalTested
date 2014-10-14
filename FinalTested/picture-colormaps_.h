#ifndef PICTURECOLORMAPS_H
#define PICTURECOLORMAPS_H

#include "core.h"
#include "common.h"

#include "picture-tricolormap.h"

namespace Picture
{

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	TriColorMap<TUNITINTERVAL> getRGBJetColorMap()
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

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static TriColorMap<TUNITINTERVAL> getRGBGreyColorMap()
	{
		TriColorMap<TUNITINTERVAL> map(2);

		map.Values[0][0] = map.Values[1][0] = map.Values[2][0] = 0.0;
		map.Values[0][1] = map.Values[1][1] = map.Values[2][1] = 1.0;

		return map;
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static TriColorMap<TUNITINTERVAL> getRGBCoolColorMap()
	{
		TriColorMap<TUNITINTERVAL> map(2);

		map.Values[0][0] = 0.0;
		map.Values[1][0] = map.Values[2][0] = 1.0;
		map.Values[0][1] = 1.0;
		map.Values[1][1] = 0.0;
		map.Values[2][1] = 1.0;

		return map;
	}

	template <typename TUNITINTERVAL = Common::UnitIntervalMax>
	static TriColorMap<TUNITINTERVAL> getRGBHotColorMap()
	{
		TriColorMap<TUNITINTERVAL> map(6);

		//black red yellow white

		map.Values[0][0] = 0.0;
		map.Values[0][1] = 0.5;
		map.Values[0][2] = map.Values[0][3] = map.Values[0][4] = map.Values[0][5] = 1.0;

		map.Values[1][0] = map.Values[1][1] = map.Values[1][2] = 0.0;
		map.Values[1][3] = 0.5;
		map.Values[1][4] = map.Values[1][5] = 1.0;

		map.Values[2][0] = map.Values[2][1] = map.Values[2][2] = map.Values[2][3] = map.Values[2][4] = 0.0;
		map.Values[2][5] = 1.0;

		return map;
	}

}

#endif // PICTURECOLORMAPS_H
