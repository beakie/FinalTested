#ifndef SPACE2DLINESEGMENT_H
#define SPACE2DLINESEGMENT_H

#include "common.h"
#include "space2d-plot.h"

namespace Space2d
{

	template <typename TVALUE = FloatMax>
	struct LineSegment2d
	{
		Common::Vector2<TVALUE> PlotFrom;
		Common::Vector2<TVALUE> PlotTo;
	};

}

#endif // SPACE2DLINESEGMENT_H
