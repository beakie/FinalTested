#ifndef INVERTIMAGEFILTER_H
#define INVERTIMAGEFILTER_H

#include "common-image.h"
#include "common-imagefilter.h"
#include "common-static.h"

namespace Common
{
	template <typename TVALUE>
	class NegativeImageFilter
	{
	public:
		template <typename TMATRIX>
		static TMATRIX getMatrix()
		{
			
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
