#ifndef IMAGECROPPER_H
#define IMAGECROPPER_H

#include "common-image.h"

namespace Common
{
	template <typename TVALUE, typename TINDEX>
	class ImageCropper
	{
	public:

		TINDEX X1;
		TINDEX Y1;
		TINDEX X2;
		TINDEX Y2;

		ImageCropper()
		{
		}

		ImageCropper(TINDEX x1, TINDEX y1, TINDEX x2, TINDEX y2)
		{
			X1 = x1;
			Y1 = y1;
			X2 = x2;
			Y2 = y2;
		}

		TINDEX getX(const TINDEX x) const
		{
			return X1 + x;
		}

		TINDEX getY(const TINDEX y) const
		{
			return Y1 + y;
		}

		TINDEX getWidth() const
		{
			return X2 - x1;
		}

		TINDEX getHeight() const
		{
			return Y2 - y1;
		}

		bool validateX(const TINDEX x) const
		{
			return (X1 >= x) && (X2 <= x);
		}

		bool validateY(const TINDEX y) const
		{
			return (Y1 >= y) && (Y2 <= y);
		}

		Image<TVALUE, TINDEX> getCroppedImage(const Image<TVALUE, TINDEX>& image)
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(X2 - X1, Y2 - Y1);
			
			for (TINDEX x = 0; x < i.getWidth(); x++)
				for (TINDEX y = 0; y < i.getHeight(); y++)
					i.Values[x][y] = image.Values[X1 + x][Y1 + y];

			return i;
		}

		~ImageCropper()
		{
		}
	};
}

#endif // IMAGECROPPER_H
