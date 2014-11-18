#ifndef SPACE3DLINESEGMENT_H
#define SPACE3DLINESEGMENT_H

#include "common.h"

namespace Space3d
{

	template <typename TVALUE = FloatMax>
	struct LineSegment3d
	{
		Common::Vector3<TVALUE> CoordinateFrom;
		Common::Vector3<TVALUE> CoordinateTo;

		Common::Vector3<TVALUE> getOffset() const
		{
			return CoordinateTo - CoordinateFrom;
		}

		TVALUE getLength() const
		{
			return Common::power(Common::power(PlotTo.Values[0] - PlotFrom.Values[0], 2) + Common::power(PlotTo.Values[1] - PlotFrom.Values[1], 2) + Common::power(PlotTo.Values[2] - PlotFrom.Values[2], 2), 0.5);
		}
	};

}

#endif // SPACE3DLINESEGMENT_H
