#ifndef INVERTIMAGEFILTER_H
#define INVERTIMAGEFILTER_H

#include "common-matrix4.h"
#include "common-static.h"

namespace Common
{
	template <typename TVALUE>
	static struct InvertImageFilter
	{
		template <typename TMATRIX>
		static TMATRIX getMatrix()
		{
		}

		static TVALUE setValue(TVALUE value)
		{
			return getUpperBound<TVALUE>() - value;
		}
	};
}

#endif // INVERTIMAGEFILTER_H
