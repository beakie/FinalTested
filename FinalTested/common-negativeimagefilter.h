#ifndef INVERTIMAGEFILTER_H
#define INVERTIMAGEFILTER_H

#include "common-image.h"
#include "common-imagefilter.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixn.h"
#include "common-static.h"

namespace Common
{
	template <typename TVALUE>
	class NegativeImageFilter
	{
	public:
		//template <typename TMATRIX>
		//static TMATRIX getMatrix()
		//{
		//	
		//}

		template <typename TMATRIX>
		static TMATRIX getMatrix();

		template <>
		static Matrix2<TVALUE> getMatrix<Matrix2<TVALUE>>()
		{
			return 0;
		}

		template <>
		static Matrix3<TVALUE> getMatrix<Matrix3<TVALUE>>()
		{
			return 0;
		}

		template <>
		static Matrix4<TVALUE> getMatrix<Matrix4<TVALUE>>()
		{
			return 0;
		}

		template <>
		static MatrixN<TVALUE> getMatrix<MatrixN<TVALUE>>()
		{
			return 0;
		}

		static TVALUE updateValue(TVALUE value)
		{
			return getUpperBound<TVALUE>() - value;
		}

		template <typename TINDEX>
		static void applyFilter(const Image<TVALUE, TINDEX>& image)
		{
			ImageFilter<TVALUE, TINDEX>::updateValues(image, updateValue);
			//ImageFilter<TVALUE, TINDEX>::applyMatrix(image, getMatrix<Matrix2F>());
		}

		~NegativeImageFilter()
		{
		}
	};
}

#endif // INVERTIMAGEFILTER_H
