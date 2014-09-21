#ifndef IMAGEFILTER_H
#define IMAGEFILTER_H

#include "common-image.h"

namespace Common
{
	template <typename TVALUE, typename TINDEX>
	class ImageProcessor
	{
	public:
		template <typename TMATRIX>
		static void applyMatrix(const Image<TVALUE, TINDEX>& image, const TMATRIX& matrix)
		{
			//todo
		}

		template <typename TFILTER>
		static void applyFilter(const Image<TVALUE, TINDEX>& image)
		{
			//todo
		}

		template <typename TFILTER>
		static void applyFilter(const Image<TVALUE, TINDEX>& image, const TFILTER& filter)
		{
			filter.applyFilter(image);
		}

		static void updateValues(const Image<TVALUE, TINDEX>& image, TVALUE(*f)(TVALUE))
		{
			//todo
		}

		virtual ~ImageProcessor()
		{
		}
	};
}

#endif // IMAGEFILTER_H
