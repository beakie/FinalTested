#ifndef SPACE2DTRANSFORMMATRIXBUILDERS_H
#define SPACE2DTRANSFORMMATRIXBUILDERS_H

#include "common.h"

namespace Space2d
{
	template <typename TVALUE>
	Common::Matrix3<TVALUE> getTranslation2dMatrix(const TVALUE x, const TVALUE y)
	{
		return Common::Matrix3<TVALUE>(  1.0,  0.0,    x,
										 0.0,  1.0,    y,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getTranslation2dMatrix(const Common::Vector2<TVALUE>& plot)
	{
		return getTranslationMatrix<TVALUE>(plot.Values[0], plot.Values[1]);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getScaling2dMatrix(const TVALUE x, const TVALUE y)
	{
		return Common::Matrix3<TVALUE>(    x,  0.0,  0.0,
										 0.0,    y,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getRotation2dMatrix(const TVALUE rotation)
	{
		TVALUE c = Common::cos<TVALUE>(rotation);
		TVALUE s = Common::sin<TVALUE>(rotation);

		return Common::Matrix3<TVALUE>(    c,    s,  0.0,
										  -s,    c,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getRotation2dMatrix(const TVALUE rotation, const TVALUE x, const TVALUE y)
	{
		return getTranslationMatrix<TVALUE>(-x, -y) * getRotationMatrix<TVALUE>(rotation) * getTranslationMatrix<TVALUE>(x, y);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getRotation2dMatrix(const TVALUE rotation, const Common::Vector2<TVALUE>& plot)
	{
		return getTranslationMatrix<TVALUE>(-plot.Values[0], -plot.Values[1]) * getRotationMatrix<TVALUE>(rotation) * getTranslationMatrix<TVALUE>(plot.Values[0], plot.Values[1]);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getReflection2dMatrixAxisX()
	{
		return Common::Matrix3<TVALUE>(  1.0,  0.0,  0.0,
										 0.0, -1.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getReflection2dMatrixAxisY()
	{
		return Common::Matrix3<TVALUE>( -1.0,  0.0,  0.0,
										 0.0,  1.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getReflection2dMatrixAxisXY()
	{
		return Common::Matrix3<TVALUE>(  0.0,  1.0,  0.0,
										 1.0,  0.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getReflection2dMatrixAxisYX()
	{
		return Common::Matrix3<TVALUE>(  0.0, -1.0,  0.0,
										-1.0,  0.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getSheer2dMatrix(const TVALUE x, const TVALUE y)
	{
		return Common::Matrix3<TVALUE>(  1.0,    x,  0.0,
										   y,  1.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getSheer2dMatrix(const TVALUE x, const TVALUE y, const Common::Vector2<TVALUE>& plot)
	{
		return getTranslationMatrix<TVALUE>(-plot.Values[0], -plot.Values[1]) * getSheerMatrix<TVALUE>(x, y) * getTranslationMatrix<TVALUE>(plot.Values[0], plot.Values[1]);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getSheer2dMatrixAxisX(const TVALUE x)
	{
		return Common::Matrix3<TVALUE>(  1.0,    x,  0.0,
										 0.0,  1.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getSheer2dMatrixAxisX(const TVALUE x, const Common::Vector2<TVALUE>& plot)
	{
		return getTranslationMatrix<TVALUE>(-plot.Values[0], -plot.Values[1]) * getSheerMatrixAxisX<TVALUE>(x) * getTranslationMatrix<TVALUE>(plot.Values[0], plot.Values[1]);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getSheer2dMatrixAxisY(const TVALUE y)
	{
		return Common::Matrix3<TVALUE>(  1.0,  0.0,  0.0,
										   y,  1.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getSheer2dMatrixAxisY(const TVALUE y, const Common::Vector2<TVALUE>& plot)
	{
		return getTranslationMatrix<TVALUE>(-plot.Values[0], -plot.Values[1]) * getSheerMatrixAxisY<TVALUE>(y) * getTranslationMatrix<TVALUE>(plot.Values[0], plot.Values[1]);
	}

}

#endif // SPACE2DTRANSFORMMATRIXBUILDERS_H
