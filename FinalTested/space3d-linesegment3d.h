#ifndef SPACE3DLINESEGMENT_H
#define SPACE3DLINESEGMENT_H

#include "common.h"

namespace Space3d
{

	template <typename TVALUE = FloatMax>
	struct LineSegment3d
	{
		Common::Vector3<TVALUE> From;
		Common::Vector3<TVALUE> To;
	};

}

#endif // SPACE3DLINESEGMENT_H
