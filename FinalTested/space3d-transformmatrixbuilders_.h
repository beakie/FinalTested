#ifndef SPACE3DTRANSFORMMATRIXBUILDERS_H
#define SPACE3DTRANSFORMMATRIXBUILDERS_H

#include "common.h"
#include "space3d-axis3d.h"

namespace Space3d
{
	template <typename TVALUE>
	Common::Matrix4<TVALUE> getTranslation3dMatrix(const TVALUE x, const TVALUE y, const TVALUE z)
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,    x,
										 0.0,  1.0,  0.0,    y,
										 0.0,  0.0,  1.0,    z,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getTranslation3dMatrix(const Common::Vector3<TVALUE>& coordinate)
	{
		return getTranslationMatrix<TVALUE>(coordinate.Values[0], coordinate.Values[1], coordinate.Values[2]);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getTranslation3dMatrixAxisX(const TVALUE translation)
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  translation,
										 0.0,  1.0,  0.0,  1.0,
										 0.0,  0.0,  1.0,  1.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getTranslation3dMatrixAxisY(const TVALUE translation)
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  1.0,
										 0.0,  1.0,  0.0,  translation,
										 0.0,  0.0,  1.0,  1.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getTranslation3dMatrixAxisZ(const TVALUE translation)
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  1.0,
										 0.0,  1.0,  0.0,  1.0,
										 0.0,  0.0,  1.0,  translation,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getScaling3dMatrix(const TVALUE x, const TVALUE y, const TVALUE z)
	{
		return Common::Matrix4<TVALUE>(    x,  0.0,  0.0,  0.0,
										 0.0,    y,  0.0,  0.0,
										 0.0,  0.0,    z,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getScaling3dMatrixScaleX(const TVALUE scale)
	{
		return Common::Matrix4<TVALUE>(scale,  0.0,  0.0,  0.0,
										 0.0,  1.0,  0.0,  0.0,
										 0.0,  0.0,  1.0,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getScaling3dMatrixScaleY(const TVALUE scale)
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  0.0,
										 0.0, scale, 0.0,  0.0,
										 0.0,  0.0,  1.0,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getScaling3dMatrixScaleZ(const TVALUE scale)
	{
		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  0.0,
										 0.0,  1.0,  0.0,  0.0,
										 0.0,  0.0, scale, 0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotation3dMatrix(const TVALUE x, const TVALUE y, const TVALUE z, const TVALUE rotation) // this is wrong. this needs changing. what axis am i rotating around? arbitrary? 
	{
		return getTranslationMatrix<TVALUE>(-x, -y, -z) * getRotationMatrix<TVALUE>(rotation) * getTranslationMatrix<TVALUE>(x, y, Z);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotation3dMatrix(const Common::Vector3<TVALUE>& coordinate, const TVALUE rotation)
	{
		return getTranslationMatrix<TVALUE>(-plot.Values[0], -plot.Values[1], -plot.Values[2]) * getRotationMatrix<TVALUE>(rotation) * getTranslationMatrix<TVALUE>(plot.Values[0], plot.Values[1], plot.Values[2]);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotation3dMatrix(Axis3d::Enum axis, const TVALUE rotation)
	{
		switch (axis)
		{
		case Axis3d::X:
			return getRotationMatrixAxisX<TVALUE>(rotation);
			break;
		case Axis3d::Y:
			return getRotationMatrixAxisY<TVALUE>(rotation);
			break;
		case Axis3d::Z:
			return getRotationMatrixAxisZ<TVALUE>(rotation);
			break;
		}
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotation3dMatrixAxisX(const TVALUE rotation)
	{
		TVALUE c = Common::cos<TVALUE>(rotation);
		TVALUE s = Common::sin<TVALUE>(rotation);

		return Common::Matrix4<TVALUE>(  1.0,  0.0,  0.0,  0.0,
										 0.0,    c,    s,  0.0,
										 0.0,   -s,    c,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotation3dMatrixAxisY(const TVALUE rotation)
	{
		TVALUE c = Common::cos<TVALUE>(rotation);
		TVALUE s = Common::sin<TVALUE>(rotation);

		return Common::Matrix4<TVALUE>(    c,  0.0,   -s,  0.0,
										 0.0,  1.0,  0.0,  0.0,
										   s,  0.0,    c,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix4<TVALUE> getRotation3dMatrixAxisZ(const TVALUE rotation)
	{
		TVALUE c = Common::cos<TVALUE>(rotation);
		TVALUE s = Common::sin<TVALUE>(rotation);

		return Common::Matrix4<TVALUE>(   c,     s,  0.0,  0.0,
										  -s,    c,  0.0,  0.0,
										 0.0,  0.0,  1.0,  0.0,
										 0.0,  0.0,  0.0,  1.0);
	}
}

#endif // SPACE3DTRANSFORMMATRIXBUILDERS_H
