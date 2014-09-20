#ifndef INVERTIMAGEFILTER_H
#define INVERTIMAGEFILTER_H

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

		~NegativeImageFilter()
		{
		}
	};
}

#endif // INVERTIMAGEFILTER_H
