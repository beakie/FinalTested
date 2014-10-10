#ifndef COMMONIMAGE_H
#define COMMONIMAGE_H

#include "common-math.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
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

		/// <summary>
		/// Constructs an unpopulated image
		/// </summary>
		Image()
		{
			createPixelArray(0, 0);
		}

		/// <summary>
		/// Constructs an image and copies existing image into it
		/// </summary>
		Image(const Image<TVALUE, TINDEX>& image)
		{
			Values = 0;
			Width = 0;
			Height = 0;
			operator=(image); //use a swap function instead?
		}

		/// <summary>
		/// Constructs an unpopulated image
		/// </summary>
		Image(TINDEX width, TINDEX height)
		{
			createPixelArray(width, height);
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
		/// Constructs a image and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Image(TINDEX width, TINDEX height, const TVALUE** values)
			: Image(width, height)
		{
			for (TINDEX x = 0; x < width; x++)
				for (TINDEX y = 0; y < height; y++)
					Values[x][y] = values[x][y];
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
		static TVALUE getMinValue()
		{
			return Common::getLowerBound<TVALUE>();
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		static TVALUE getMaxValue()
		{
			return getUpperBound<TVALUE>();
		}

		/// <summary>
		/// Clone
		/// </summary>
		Image<TVALUE, TINDEX>& operator=(const Image<TVALUE, TINDEX>& image)  //use a swap function instead?
		{
			if (this != &image)
			{
				TINDEX newWidth = image.Width;
				TINDEX newHeight = image.Height;
				TVALUE** valuesBuffer = new TVALUE*[newWidth];

				for (TINDEX x = 0; x < newWidth; x++)
				{
					valuesBuffer[x] = new TVALUE[newHeight];

					for (TINDEX y = 0; y < newHeight; y++)
						valuesBuffer[x][y] = image.Values[x][y];
				}

				replacePixelArray(newWidth, newHeight, valuesBuffer);
			}

			return *this;
		}

		// ************************************************************************************ // LINE OF HAPPINESS

		/// <summary>
		/// Increase contrast
		/// </summary>
		Image<TVALUE, TINDEX> operator*(const TVALUE value) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			i *= value;

			return i;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		Image<TVALUE, TINDEX>& operator*=(const TVALUE value)
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			TVALUE upperBound = getUpperBound<TVALUE>();
			TVALUE overflowCheck = upperBound / value;

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = (Values[x][y] > overflowCheck ? upperBound : Values[x][y] * value);
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		Image<TVALUE, TINDEX> operator/(const TVALUE value) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			i /= value;

			return i;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		Image<TVALUE, TINDEX>& operator/=(const TVALUE value)
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = Values[x][y] / value;
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX> operator>>(const TVALUE value) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] < value)
						i.Value[x][y] = value;
					else
						i.Value[x][y] = Value[x][y];

			return i
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX> operator<<(const TVALUE value)
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] > value)
						i.Value[x][y] = value;
					else
						i.Value[x][y] = Value[x][y];

			return i
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		Image<TVALUE, TINDEX> operator|(const Image<TVALUE, TINDEX>& image) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			i |= image;

			return i;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		Image<TVALUE, TINDEX>& operator|=(const Image<TVALUE, TINDEX>& image)
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = Values[x][y] | image.Values[x][y];
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		Image<TVALUE, TINDEX> operator&(const Image<TVALUE, TINDEX>& image) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			i &= image;

			return i;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		Image<TVALUE, TINDEX>& operator&=(const Image<TVALUE, TINDEX>& image)
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = Values[x][y] & image.Values[x][y];
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		Image<TVALUE, TINDEX> operator!() const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			TVALUE upperBound = getUpperBound<TVALUE>();

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Values[x][y] = upperBound - i.Values[x][y];

			return i;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator==(const Image<TVALUE, TINDEX>& image) const
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
		bool operator!=(const Image<TVALUE, TINDEX>& image) const
		{
			return operator==(image);
		}

		/// <summary>
		/// Greater than
		/// </summary>
		bool operator>(const TVALUE value) const
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] > values)
						return true;

			return false;
		}

		/// <summary>
		/// Less than
		/// </summary>
		bool operator<(const TVALUE value) const
		{
			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] < values)
						return true;

			return false;
		}

		/// <summary>
		/// Clones the image
		/// </summary>
		Image<TVALUE, TINDEX>& clone(const Image<TVALUE, TINDEX>& image)
		{
			return operator=(image);
		}

		static Image<TVALUE, TINDEX> getCroppedImage(const Image<TVALUE, TINDEX>& image, const TINDEX x1, const TINDEX y1, const TINDEX x2, const TINDEX y2)
		{
			Image<TVALUE, TINDEX> i;

			i.cropImage();

			return i;
		}

		/// <summary>
		/// Crops the image
		/// </summary>
		Image<TVALUE, TINDEX>& cropImage(const TINDEX x1, const TINDEX y1, const TINDEX x2, const TINDEX y2)
		{
			TVALUE** valuesBuffer;
			TINDEX newWidth = x2 - x1 + 1;
			TINDEX newHeight = y2 - y1 + 1;

			valuesBuffer = new TVALUE*[newWidth];

			for (TINDEX x = 0; x < newWidth; x++)
			{
				valuesBuffer[x] = new TVALUE[newHeight];

				for (TINDEX y = 0; y < newHeight; y++)
					valuesBuffer[x][y] = Values[x1 + x][y1 + y];
			}

			replacePixelArray(newWidth, newHeight, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<bool, TINDEX> getIsAboveThreshold(const TVALUE value) const
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
		Image<bool, TINDEX> getIsBelowThreshold(const TVALUE value) const
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
			return operator>>(value);
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& trimBelowThreshold(const TVALUE value) const
		{
			return operator<<(value);
		}

		/// <summary>
		/// Threshold
		/// </summary>
		Image<TVALUE, TINDEX>& trimBetweenThresholds(const TVALUE lower, const TVALUE upper)
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
		/// Rotates the image 90 degrees clockwise
		/// </summary>
		Image<TVALUE, TINDEX>& rotate90()
		{
			TVALUE** valuesBuffer = new TVALUE*[Height];

			for (TINDEX y = 0; y < Height; y++)
			{
				valuesBuffer[y] = new TVALUE[Width];

				for (TINDEX x = 0; x < Width; x++)
					valuesBuffer[y][x] = Values[x][Height - y - 1];
			}

			replacePixelArray(Height, Width, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Rotates the image 180 degrees
		/// </summary>
		Image<TVALUE, TINDEX>& rotate180()
		{
			TVALUE** valuesBuffer = new TVALUE*[Width];

			for (TINDEX x = 0; x < Width; x++)
			{
				valuesBuffer[x] = new TVALUE[Height];

				for (TINDEX y = 0; y < Height; y++)
					valuesBuffer[x][y] = Values[Width - x - 1][Height - y - 1];
			}

			replacePixelArray(Width, Height, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Rotates the image 90 degrees anticlockwise
		/// </summary>
		Image<TVALUE, TINDEX>& rotate270()
		{
			TVALUE** valuesBuffer = new TVALUE*[Height];

			for (TINDEX y = 0; y < Height; y++)
			{
				valuesBuffer[y] = new TVALUE[Width];

				for (TINDEX x = 0; x < Width; x++)
					valuesBuffer[y][x] = Values[Width - x - 1][y];
			}

			replacePixelArray(Height, Width, valuesBuffer);

			return *this;
		}

		/// <summary>
		/// Horizontally flips the image
		/// </summary>
		Image<TVALUE, TINDEX>& flipHorizontally()
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Values[x][y] = i.Values[Width - x - 1][y];

			return *this;
		}

		/// <summary>
		/// Vertically flips the image
		/// </summary>
		Image<TVALUE, TINDEX>& flipVertically()
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX> = *this;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					Values[x][y] = i.Values[x][Height - y - 1];

			return *this;
		}

		/// <summary>
		/// Inverts the image
		/// </summary>
		Image<TVALUE, TINDEX>& invert(const Image<TVALUE, TINDEX>& image)
		{
			return operator=(!image.operator!());
		}

		/// <summary>
		/// Inverts the image
		/// </summary>
		Image<TVALUE, TINDEX>& invert()
		{
			return operator=(operator!());
		}

		/// <summary>
		/// Gets the inverted image
		/// </summary>
		Image<TVALUE, TINDEX> getInverted()
		{
			return operator!();
		}

		/// <summary>
		/// Apply 3x3 convolution matrix to image with cropped edges
		/// </summary>
		Image<TVALUE, TINDEX> getMatrixImageCrop(const Matrix3<TVALUE> matrix) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width - 2, Height - 2);

			for (TINDEX x = 0; x < Width - 2; x++)
				for (TINDEX y = 0; y < Height - 2; y++)
				{
					TINDEX x2 = x + 1;
					TINDEX x3 = x + 2;
					TINDEX y2 = y + 1;
					TINDEX y3 = y + 2;

					i.Values[x][y] = (Values[x][y] * matrix.Values[0][0])
										+ (Values[x2][y] * matrix.Values[1][0])
										+ (Values[x3][y] * matrix.Values[2][0])
										+ (Values[x][y2] * matrix.Values[0][1])
										+ (Values[x2][y2] * matrix.Values[1][1])
										+ (Values[x3][y2] * matrix.Values[2][1])
										+ (Values[x][y3] * matrix.Values[0][2])
										+ (Values[x2][y3] * matrix.Values[1][2])
										+ (Values[x3][y3] * matrix.Values[2][2]);
				}

			return i;
		}

		/// <summary>
		/// Apply 3x3 convolution matrix to image with wrapped edges
		/// </summary>
		Image<TVALUE, TINDEX> getMatrixImageWrap(const Matrix3<TVALUE> matrix) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
				{
					TINDEX xBefore = (x - 1) % width;
					TINDEX xAfter = (x + 1) % width;
					TINDEX yBefore = (y - 1) % height;
					TINDEX yAfter = (y + 1) % height;

					i.Values[x][y] = (Values[xBefore][yBefore] * matrix.Values[0][0])
										+ (Values[x][yBefore] * matrix.Values[1][0])
										+ (Values[xAfter][yBefore] * matrix.Values[2][0])
										+ (Values[xBefore][y] * matrix.Values[0][1])
										+ (Values[x][y] * matrix.Values[1][1])
										+ (Values[xAfter][y] * matrix.Values[2][1])
										+ (Values[xBefore][yAfter] * matrix.Values[0][2])
										+ (Values[x][yAfter] * matrix.Values[1][2])
										+ (Values[xAfter][yAfter] * matrix.Values[2][2]);
				}

			return i;
		}

		/// <summary>
		/// Apply 3x3 convolution matrix to image with extended edges
		/// </summary>
		Image<TVALUE, TINDEX> getMatrixImageExtend(const Matrix3<TVALUE> matrix) const
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
				{
					TINDEX xBefore = (x == 0 ? Width - 1 : x);
					TINDEX xAfter = (x == (Width - 1) ? 0 : x);
					TINDEX yBefore = (y == 0 ? Height - 1 : y);
					TINDEX yAfter = (y == (Height - 1) ? 0 : y);

					i.Values[x][y] = (Values[xBefore][yBefore] * matrix.Values[0][0])
										+ (Values[x][yBefore] * matrix.Values[1][0])
										+ (Values[xAfter][yBefore] * matrix.Values[2][0])
										+ (Values[xBefore][y] * matrix.Values[0][1])
										+ (Values[x][y] * matrix.Values[1][1])
										+ (Values[xAfter][y] * matrix.Values[2][1])
										+ (Values[xBefore][yAfter] * matrix.Values[0][2])
										+ (Values[x][yAfter] * matrix.Values[1][2])
										+ (Values[xAfter][yAfter] * matrix.Values[2][2]);
				}

			return i;
		}

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






		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUENEW, typename TCONVERTER>
		Common::Image<TVALUENEW, TINDEX> getImage(TCONVERTER* converter)
		{
			Common::Image<TVALUENEW, TINDEX> i = Common::Image<TVALUENEW, TINDEX>(Width, Height);

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					i.Values[x][y] = converter->convertPixel(Values[x][y]);

			return i;
		}

	private:
		template <typename TVALUENEW>
		class ImageRenderHelper
		{
		public:
			TVALUENEW(*convertPixel)(const TVALUE&);

			ImageRenderHelper(TVALUENEW(pixelConverter)(const TVALUE&))
			{
				convertPixel = &pixelConverter;
			}
		};

	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUENEW>
		Common::Image<TVALUENEW, TINDEX> getImage(TVALUENEW(pixelConverter)(const TVALUE&))
		{
			return getImage<TVALUENEW>(&ImageRenderHelper<TVALUENEW>(pixelConverter));
		}

	};
}

#endif // COMMONIMAGE_H
