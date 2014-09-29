#ifndef COMMONIMAGE_H
#define COMMONIMAGE_H

#include "common-static.h"

namespace Common
{
	template <typename TVALUE, typename TINDEX>
	/// <summary>
	/// 2 dimensional array of pixels
	/// </summary>
	struct Image
	{
		/// <summary>
		/// The values of the image stored in [x][y] form
		/// </summary>
		TVALUE** Values;

		/// <summary>
		/// The width of the image
		/// </summary>
		TINDEX Width;
		/// <summary>
		/// The height of the image
		/// </summary>
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
			createPixelArray(Width, Height);
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

		/// <summary>
		/// Crops the image
		/// </summary>
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

			deletePixelArray();

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
		Image<TVALUE, TINDEX> operator >>(const TVALUE value) const
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] < value)
						Value[x][y] = value;

			return *this;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& operator <<(const TVALUE value)
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] > value)
						Value[x][y] = value;

			return *this;
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
		/// Threshold
		/// </summary>
		Image<bool, TINDEX> getAboveThreshold(const TVALUE value) const
		{
			Image<bool, TINDEX> i = Image<bool, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					i.Values[x][y] = (Values[x][y] >= value);

			return i;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<bool, TINDEX> getBelowThreshold(const TVALUE value) const
		{
			Image<bool, TINDEX> i = Image<bool, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					i.Values[x][y] = (Values[x][y] <= value);

			return i;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& trimAboveThreshold(const TVALUE value) const
		{
			return operator >>(value);
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& trimBelowThreshold(const TVALUE value) const
		{
			return operator <<(value);
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& trimBetweenThresholds(const TVALUE lower, const TVALUE upper) const
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] < lower) // use max function?
						Value[x][y] = lower;
					else if (Values[x][y] > upper) // use max function?
						Value[x][y] = upper;

			return *this;
		}

		/// <summary>
		/// Horizontally flips the image
		/// </summary>
		Image<TVALUE, TINDEX>& flipHorizontally() const
		{
			Image<TVALUE, TINDEX> i = *this;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Values[x][y] = i.Values[Width - x][y];

			return this*
		}

		/// <summary>
		/// Vertically flips the image
		/// </summary>
		Image<TVALUE, TINDEX>& flipVertically() const
		{
			Image<TVALUE, TINDEX> i = *this;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Values[x][y] = i.Values[x][Height - y];

			return this*
		}

		/// <summary>
		/// Inverts the image
		/// </summary>
		Image<TVALUE, TINDEX>& invert(const Image<TVALUE, TINDEX>& image) const;

	private:
		void createPixelArray(TINDEX width, TINDEX height)
		{
			TVALUE** values = new TVALUE*[width];

			for (TINDEX i = 0; i < width; i++)
				values[i] = new TVALUE[height];

			setPixelArray(width, height, values);
		}

		void setPixelArray(TINDEX width, TINDEX height, TVALUE** values)
		{
			Width = width;
			Height = height;
			Values = values;
		}

		void deletePixelArray()
		{
			for (TINDEX x = 0; x < Width; x++)
				delete[] Values[x];

			delete[] Values;
		}

		void recreatePixelArray(TINDEX width, TINDEX height)
		{
			deletePixelArray();
			createPixelArray(width, height);
		}

		void replacePixelArray(TINDEX width, TINDEX height, TVALUE** values)
		{
			deletePixelArray();
			setPixelArray(width, height, values);
		}

	public:
		virtual ~Image()
		{
			deletePixelArray();
		}

	};
}

#endif // COMMONIMAGE_H
