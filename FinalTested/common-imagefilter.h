#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

#include "common-image.h"

namespace Common
{
	template <typename TVALUE, typename TINDEX>
	class ImageFilter
	{
	public:
		template <typename TMATRIX>
		static Image<TVALUE, TINDEX> apply(Image<TVALUE, TINDEX> image, TMATRIX matrix)
		{
			return Image<TVALUE, TINDEX>();
		}

		virtual ~ImageFilter()
		{
		}
	};
}

#endif // IMAGEFILTER_H
