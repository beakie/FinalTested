#ifndef SPACE2DTRANSFORMMATRIXBUILDERS_H
#define SPACE2DTRANSFORMMATRIXBUILDERS_H

#include "common.h"

namespace Space3d
{
	template <typename TVALUE>
	Common::Matrix3<TVALUE> getTranslationMatrix(const TVALUE x, const TVALUE y)
	{
		return Common::Matrix3<TVALUE>(  1.0,  0.0,    x,
										 0.0,  1.0,    y,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getScalingMatrix(const TVALUE x, const TVALUE y)
	{
		return Common::Matrix3<TVALUE>(    x,  0.0,  0.0,
										 0.0,    y,  0.0,
										 0.0,  0.0,  1.0);
	}
}

#endif // SPACE2DTRANSFORMMATRIXBUILDERS_H
