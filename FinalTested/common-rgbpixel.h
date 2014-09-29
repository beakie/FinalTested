#ifndef COMMONRGBPIXEL_H
#define COMMONRGBPIXEL_H

namespace Common
{
	template <typename TVALUE>
	/// <summary>
	/// HSV pixel
	/// </summary>
	struct RGBPixel
	{
		/// <summary>
		/// Red value
		/// </summary>
		TVALUE R;
		/// <summary>
		/// Green value
		/// </summary>
		TVALUE G;
		/// <summary>
		/// Blue value
		/// </summary>
		TVALUE B;

		RGBPixel()
		{
		}

		RGBPixel(TVALUE r, TVALUE g, TVALUE b)
		{
			R = r;
			G = g;
			B = b;
		}

		/// <summary>
		/// Operator
		/// </summary>
		RGBPixel<TVALUE>& operator =(const RGBPixel<TVALUE>& pixel)
		{
			R = pixel.R;
			G = pixel.G;
			B = pixel.B;

			return *this;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		RGBPixel<TVALUE> operator *(const RGBPixel<TVALUE>& pixel) const
		{
			RGBPixel<TVALUE> p = *this;

			p *= pixel;

			return p;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		RGBPixel<TVALUE>& operator *=(const RGBPixel<TVALUE>& pixel)
		{
			R = R * pixel.R;
			G = G * pixel.G;
			B = B * pixel.B;

			return *this;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		RGBPixel<TVALUE> operator /(const RGBPixel<TVALUE>& pixel) const
		{
			RGBPixel<TVALUE> p = *this;

			p /= pixel;

			return p;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		RGBPixel<TVALUE>& operator /=(const RGBPixel<TVALUE>& pixel)
		{
			R = R / pixel.R;
			G = G / pixel.G;
			B = B / pixel.B;

			return *this;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		RGBPixel<TVALUE> operator |(const RGBPixel<TVALUE>& pixel) const
		{
			RGBPixel<TVALUE> p = *this;

			p |= pixel;

			return p;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		RGBPixel<TVALUE>& operator |=(const RGBPixel<TVALUE>& pixel)
		{
			R = R | pixel.R;
			G = G | pixel.G;
			B = B | pixel.B;

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		RGBPixel<TVALUE> operator &(const RGBPixel<TVALUE>& pixel) const
		{
			RGBPixel<TVALUE> p = *this;

			p &= pixel;

			return p;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		RGBPixel<TVALUE>& operator &=(const RGBPixel<TVALUE>& pixel)
		{
			R = R & pixel.R;
			G = G & pixel.G;
			B = B & pixel.B;

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		RGBPixel<TVALUE> operator !() const
		{
			RGBPixel<TVALUE> p = *this;

			p != p;

			return p;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator ==(const RGBPixel<TVALUE>& pixel) const
		{
			if ((Width != pixel.Width) || (Height != pixel.Height))
				return false;

			for (TINDEX x = 0; x < Width; x++)
				for (TINDEX y = 0; y < Height; y++)
					if (Values[x][y] != pixel.Values[x][y])
						return false;

			return true;
		}

		/// <summary>
		/// Not comparison
		/// </summary>
		bool operator !=(const RGBPixel<TVALUE>& pixel) const
		{
			return operator ==(pixel);
		}
	};
}

#endif // COMMONRGBPIXEL_H
