#ifndef INVERTIMAGEFILTER_H
#define INVERTIMAGEFILTER_H

#include "common-matrix4.h"
#include "common-static.h"

namespace Common
{
	template <typename TVALUE>
	struct InvertImageFilter
	{
		template <typename TMATRIX>
		TMATRIX getMatrix()
		{
		}

		TVALUE setValue(TVALUE value)
		{
			return getUpperBound<TVALUE>() - value;
		}
	};
}

#endif // INVERTIMAGEFILTER_H
