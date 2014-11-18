#ifndef SPACE2DLINESEGMENT_H
#define SPACE2DLINESEGMENT_H

#include "common.h"

namespace Space2d
{

	template <typename TVALUE = FloatMax>
	struct LineSegment2d
	{
		Common::Vector2<TVALUE> From;
		Common::Vector2<TVALUE> To;
	};

}

#endif // SPACE2DLINESEGMENT_H
