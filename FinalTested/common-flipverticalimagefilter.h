#ifndef FLIPHORIZONTALIMAGEFILTER_H
#define FLIPHORIZONTALIMAGEFILTER_H

#include "common-image.h"
#include "common-imageprocessor.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixn.h"
#include "common-static.h"

namespace Common
{
	template <typename TVALUE>
	class FlipHorizontalImageFilter
	{
	public:
		template <typename TINDEX>
		static Image<TVALUE, TINDEX> updateImage(const Image<TVALUE, TINDEX>& image)
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>();

			TINDEX height = i.getHeight();

			for (TINDEX x = 0; x < i.getwidth(); x++)
				for (TINDEX y = 0; y < height; y++)
					i.Values[x][y] = image.Values[x][height - y];

			return i;
		}

		template <typename TINDEX>
		static void applyFilter(const Image<TVALUE, TINDEX>& image)
		{
			image = updateImage(image);
		}

		~FlipHorizontalImageFilter()
		{
		}
	};
}

#endif // FLIPHORIZONTALIMAGEFILTER_H
