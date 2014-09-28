#ifndef COMMONHSVPIXEL_H
#define COMMONHSVPIXEL_H

namespace Common
{
	template <typename TVALUE>
	/// <summary>
	/// RGB pixel
	/// </summary>
	struct HSVPixel
	{
		TVALUE H;
		TVALUE S;
		TVALUE V;

		/// <summary>
		/// Operator
		/// </summary>
		HSVPixel<TVALUE>& operator =(const HSVPixel<TVALUE>& pixel)
		{
			H = pixel.H;
			S = pixel.S;
			V = pixel.V;

			return *this;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		HSVPixel<TVALUE> operator *(const HSVPixel<TVALUE>& pixel) const
		{
			HSVPixel<TVALUE> p = *this;

			p *= pixel;

			return p;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		HSVPixel<TVALUE>& operator *=(const HSVPixel<TVALUE>& pixel)
		{
			H = H * pixel.H;
			S = S * pixel.S;
			V = V * pixel.V;

			return *this;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		HSVPixel<TVALUE> operator /(const HSVPixel<TVALUE>& pixel) const
		{
			HSVPixel<TVALUE> p = *this;

			p /= pixel;

			return p;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		HSVPixel<TVALUE>& operator /=(const HSVPixel<TVALUE>& pixel)
		{
			H = H / pixel.H;
			S = S / pixel.S;
			V = V / pixel.V;

			return *this;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		HSVPixel<TVALUE> operator |(const HSVPixel<TVALUE>& pixel) const
		{
			HSVPixel<TVALUE> p = *this;

			p |= pixel;

			return p;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		HSVPixel<TVALUE>& operator |=(const HSVPixel<TVALUE>& pixel)
		{
			H = H | pixel.H;
			S = S | pixel.S;
			V = V | pixel.V;

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		HSVPixel<TVALUE> operator &(const HSVPixel<TVALUE>& pixel) const
		{
			HSVPixel<TVALUE> p = *this;

			p &= pixel;

			return p;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		HSVPixel<TVALUE>& operator &=(const HSVPixel<TVALUE>& pixel)
		{
			H = H & pixel.H;
			S = S & pixel.S;
			V = V & pixel.V;

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		HSVPixel<TVALUE> operator !() const
		{
			HSVPixel<TVALUE> p = *this;

			p != p;

			return p;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator ==(const HSVPixel<TVALUE>& pixel) const
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
		bool operator !=(const HSVPixel<TVALUE>& pixel) const
		{
			return operator ==(pixel);
		}
	};
}

#endif // COMMONHSVPIXEL_H
