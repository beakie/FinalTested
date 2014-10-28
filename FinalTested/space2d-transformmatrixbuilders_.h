#ifndef SPACE2DTRANSFORMMATRIXBUILDERS_H
#define SPACE2DTRANSFORMMATRIXBUILDERS_H

#include "common.h"

namespace Space2d
{
	template <typename TVALUE>
	Common::Matrix3<TVALUE> getTranslationMatrix(const TVALUE x, const TVALUE y)
	{
		return Common::Matrix3<TVALUE>(  1.0,  0.0,    x,
										 0.0,  1.0,    y,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getTranslationMatrix(const Common::Vector2<TVALUE>& plot)
	{
		return getTranslationMatrix<TVALUE>(plot.Values[0], plot.Values[1]);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getScalingMatrix(const TVALUE x, const TVALUE y)
	{
		return Common::Matrix3<TVALUE>(    x,  0.0,  0.0,
										 0.0,    y,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getRotationMatrix(const TVALUE rotation)
	{
		TVALUE c = Common::cos<TVALUE>(rotation);
		TVALUE s = Common::sin<TVALUE>(rotation);

		return Common::Matrix3<TVALUE>(    c,    s,  0.0,
										  -s,    c,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getRotationMatrix(const TVALUE x, const TVALUE y, const TVALUE rotation)
	{
		return getTranslationMatrix<TVALUE>(-x, -y) * getRotationMatrix<TVALUE>(rotation) * getTranslationMatrix<TVALUE>(x, y);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getRotationMatrix(const Common::Vector2<TVALUE>& plot, const TVALUE rotation)
	{
		return getTranslationMatrix<TVALUE>(-plot.Values[0], -plot.Values[1]) * getRotationMatrix<TVALUE>(rotation) * getTranslationMatrix<TVALUE>(plot.Values[0], plot.Values[1]);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getReflectionMatrixAxisX()
	{
		return Common::Matrix3<TVALUE>(  1.0,  0.0,  0.0,
										 0.0, -1.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getReflectionMatrixAxisY()
	{
		return Common::Matrix3<TVALUE>( -1.0,  0.0,  0.0,
										 0.0,  1.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getReflectionMatrixAxisXY()
	{
		return Common::Matrix3<TVALUE>(  0.0,  1.0,  0.0,
										 1.0,  0.0,  0.0,
										 0.0,  0.0,  1.0);
	}

	template <typename TVALUE>
	Common::Matrix3<TVALUE> getReflectionMatrixAxisYX()
	{
		return Common::Matrix3<TVALUE>(  0.0, -1.0,  0.0,
										-1.0,  0.0,  0.0,
										 0.0,  0.0,  1.0);
	}
}

#endif // SPACE2DTRANSFORMMATRIXBUILDERS_H
