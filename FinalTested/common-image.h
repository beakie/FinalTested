#ifndef IMAGE_H
#define IMAGE_H

#include "common-static.h"

namespace Common
{
	template <typename TVALUE, typename TINDEX>
	struct Image
	{
		/// <summary>
		/// The values of the image stored in [x][y] form
		/// </summary>
		TVALUE** Values;

		TINDEX Width;
		TINDEX Height;

		///// <summary>
		///// Constructs an unpopulated image
		///// </summary>
		Image()
		{
			//todo
		}

		/// <summary>
		/// Constructs an unpopulated image
		/// </summary>
		Image(TINDEX width, TINDEX height)
		{
			Width = width;
			Height = height;

			Values = new TVALUE*[Width];

			for (TINDEX i = 0; i < Width; i++)
				Values[i] = new TVALUE[Height];
		}

		/// <summary>
		/// Constructs a image and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Image(TINDEX width, TINDEX height, const TVALUE value)
			: Image(width, height)
		{
			for (TINDEX x = 0; x < width; x++)
				for (TINDEX y = 0; y < height; y++)
					Values[x][y] = value;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		TINDEX getWidth() const
		{
			return Width;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		TINDEX getHeight() const
		{
			return Height;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		TINDEX getPosition(TINDEX) const
		{
			return Height;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		bool validateX(const TINDEX x) const
		{
			return (x <= Width) && (x >= 0);
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		bool validateY(const TINDEX y) const
		{
			return (y <= Height) && (y >= 0);
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		static TVALUE getMaxValue()
		{
			return Common::getUpperBound<TVALUE>();
		}

		static Image<TVALUE, TINDEX> getCroppedImage(const Image<TVALUE, TINDEX>& image, const TINDEX x1, const TINDEX y1, const TINDEX x2, const TINDEX y2)
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(x2 - x1, y2 - y1);

			for (TINDEX x = 0; x < i.getWidth(); x++)
				for (TINDEX y = 0; y < i.getHeight(); y++)
					i.Values[x][y] = image.Values[x1 + x][y1 + y];

			return i;
		}

		Image<TVALUE, TINDEX>& cropImage(const TINDEX x1, const TINDEX y1, const TINDEX x2, const TINDEX y2)
		{
			TVALUE** valuesBuffer;
			TINDEX newWidth = x2 - x1;
			TINDEX newHeight = y2 - y1;

			valuesBuffer = new TVALUE*[newWidth];

			for (TINDEX x = 0; x < newWidth; x++)
			{
				valuesBuffer[x] = new TVALUE[newHeight];

				for (TINDEX y = 0; y < newHeight; y++)
					valuesBuffer[x][y] = Values[x1 + x][y1 + y];
			}

			for (TINDEX x = 0; x < newWidth; x++)
				delete[] Values[x];

			delete[] Values;

			Width = newWidth;
			Height = newHeight;
			Values = valuesBuffer;

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Image<TVALUE, TINDEX>& operator =(const Image<TVALUE, TINDEX>& image)
		{
			Values = image.Values; // todo: do copy properly
			Width = image.Width;
			Height = image.Height;

			return *this;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		Image<TVALUE, TINDEX> operator *(const TVALUE value) const
		{
			Image<TVALUE, TINDEX> i = *this;
			i *= value;
			return i;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		Image<TVALUE, TINDEX>& operator *=(const TVALUE value);

		/// <summary>
		/// Decrease contrast
		/// </summary>
		Image<TVALUE, TINDEX> operator /(const TVALUE value) const
		{
			Image<TVALUE, TINDEX> i = *this;
			i /= value;
			return i;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		Image<TVALUE, TINDEX>& operator /=(const TVALUE value);

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& operator >=(const Image<TVALUE, TINDEX>& image);

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX> operator >(const Image<TVALUE, TINDEX>& image) const
		{
			Image<TVALUE, TINDEX> i = *this;
			i >= image;
			return i;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& operator <=(const Image<TVALUE, TINDEX>& image);

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX> operator <(const Image<TVALUE, TINDEX>& image) const
		{
			Image<TVALUE, TINDEX> i = *this;
			i <= image;
			return i;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		Image<TVALUE, TINDEX> operator |(const Image<TVALUE, TINDEX>& image) const
		{
			Image<TVALUE, TINDEX> i = *this;
			i |= image;
			return i;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		Image<TVALUE, TINDEX>& operator |=(const Image<TVALUE, TINDEX>& image)
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Values[x][y] |= image.Values[x][y];

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		Image<TVALUE, TINDEX> operator &(const Image<TVALUE, TINDEX>& image) const
		{
			Image<TVALUE, TINDEX> i = *this;
			i &= image;
			return i;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		Image<TVALUE, TINDEX>& operator &=(const Image<TVALUE, TINDEX>& image)
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Values[x][y] &= image.Values[x][y];

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		Image<TVALUE, TINDEX> operator !() const
		{
			Image<TVALUE, TINDEX> i = *this;
			i != i;
			return i;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator ==(const Image<TVALUE, TINDEX>& image) const
		{
			if ((Width != image.Width) || (Height != image.Height))
				return false;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] != image.Values[x][y])
						return false;

			return true;
		}

		/// <summary>
		/// Not comparison
		/// </summary>
		bool operator !=(const Image<TVALUE, TINDEX>& image) const
		{
			return operator ==(image);
		}

		/// <summary>
		/// Clones the image
		/// </summary>
		Image<TVALUE, TINDEX>& clone(const Image<TVALUE, TINDEX>& image) const
		{
			return operator =(image);
		}

		/// <summary>
		/// Inverts the image
		/// </summary>
		Image<TVALUE, TINDEX>& invert(const Image<TVALUE, TINDEX>& image) const;

		virtual ~Image()
		{
			for (TINDEX i = 0; i < Width; i++)
				delete[] Values[i];

			delete[] Values;
		}

	};
}

#endif // IMAGE_H
