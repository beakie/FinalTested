#ifndef SPACE3DCOMMON_H
#define SPACE3DCOMMON_H

#include "common.h"

#include "space3d-coordinate.h"

namespace Space3d
{

	template <typename T>
	FloatMax getDistanceBetween(const Common::Vector3<T> &coordinate1, const Common::Vector3<T> &coordinate2)
	{
		return Common::power(Common::power((FloatMax)coordinate1.Values[0] - coordinate2.Values[0], 2) + Common::power(coordinate1.Values[1] - coordinate2.Values[1], 2) + Common::power(coordinate1.Values[2] - coordinate2.Values[2], 2), 0.5);
	}

}

#endif // SPACE3DCOMMON_H
