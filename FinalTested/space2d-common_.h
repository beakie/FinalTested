#ifndef SPACE2DCOMMON_H
#define SPACE2DCOMMON_H

#include "common.h"

#include "space2d-plot.h"

namespace Space2d
{

	template <typename T>
	FloatMax getDistanceBetween(const Common::Vector2<T> &plot1, const Common::Vector2<T> &plot2)
	{
		return Common::power(Common::power((FloatMax)plot1.Values[0] - plot2.Values[0], 2) + Common::power(plot1.Values[1] - plot2.Values[1], 2), 0.5);
	}

}

#endif // SPACE2DCOMMON_H
