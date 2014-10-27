#ifndef SPACE3DTRANSFORMMATRIXBUILDERS_H
#define SPACE3DTRANSFORMMATRIXBUILDERS_H

#include "common.h"
#include "space3d-axis.h"

namespace Space3d
{
	template <typename TVALUE>
	Common::Matrix4<TVALUE> getTranslationMatrix(const TVALUE x, const TVALUE y, const TVALUE z)
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,    x,
										 0.0,  1.0,  0.0,    y,
										 0.0,  0.0,  1.0,    z,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getScalingMatrix(const TVALUE x, const TVALUE y, const TVALUE z)
	{
		return Common::Matrix4<TVALUE>(    x,  0.0,  0.0,  0.0,
										 0.0,    y,  0.0,  0.0,
										 0.0,  0.0,    z,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotationMatrix(const TVALUE rotation)
	{
		TVALUE c = Common::cos(rotation);
		TVALUE s = Common::sin(rotation);

		return Common::Matrix4<TVALUE>(   c,     s,  0.0,  0.0,
										  -s,    c,  0.0,  0.0,
										 0.0,  0.0,  1.0,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotationMatrix(Axis::Enum axis, const TVALUE rotation)
	{
		switch (axis)
		{
		case Axis::X:
			return getRotationMatrixAxisX(rotation);
			break;
		case Axis::Y:
			return getRotationMatrixAxisY(rotation);
			break;
		case Axis::Z:
			return getRotationMatrixAxisZ(rotation);
			break;
		}
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotationMatrixAxisX(const TVALUE rotation)
	{
		TVALUE c = Common::cos(rotation);
		TVALUE s = Common::sin(rotation);

		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  0.0,
										 0.0,    c,    s,  0.0,
										 0.0,   -s,    c,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotationMatrixAxisY(const TVALUE rotation)
	{
		TVALUE c = Common::cos(rotation);
		TVALUE s = Common::sin(rotation);

		return Common::Matrix4<TVALUE>(    c,  0.0,   -s,  0.0,
										 0.0,  1.0,  0.0,  0.0,
										   s,  0.0,    c,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotationMatrixAxisZ(const TVALUE rotation)
	{
		TVALUE c = Common::cos(rotation);
		TVALUE s = Common::sin(rotation);

		return Common::Matrix4<TVALUE>(   c,     s,  0.0,  0.0,
										  -s,    c,  0.0,  0.0,
										 0.0,  0.0,  1.0,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}
}

#endif // SPACE3DTRANSFORMMATRIXBUILDERS_H
