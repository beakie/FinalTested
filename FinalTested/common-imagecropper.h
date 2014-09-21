#ifndef IMAGECROPPER_H
#define IMAGECROPPER_H

#include "common-image.h"

namespace Common
{
	template <typename TVALUE, typename TINDEX>
	class ImageCropper
	{
	public:
		ImageCropper(TINDEX x1, TINDEX y1, TINDEX x2, TINDEX y2)
		{
		}

		TINDEX getX(TINDEX x)
		{
			return x1 + x;
		}

		TINDEX getY(TINDEX y)
		{
			return y1 + y;
		}

		TINDEX getWidth()
		{
			return x2 - x1;
		}

		TINDEX getHeight()
		{
			return y2 - y1;
		}

		Image<TVALUE, TINDEX> getCroppedImage(const Image<TVALUE, TINDEX>& image)
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(x2 - x1, y2 - y1);
			
			for (TINDEX x = 0; x < i.getWidth(); x++)
				for (TINDEX y = 0; y < i.getHeight(); y++)
					i.Values[x][y] = image.Values[x1 + x][y1 + y];

			return i;
		}

		~ImageCropper()
		{
		}
	};
}

#endif // IMAGECROPPER_H
