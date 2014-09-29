#ifndef COMMONQUADCHANNELPIXEL_H
#define COMMONQUADCHANNELPIXEL_H

namespace Common
{
	template <typename TVALUE>
	/// <summary>
	/// Quadruple channel pixel
	/// </summary>
	struct QuadChannelPixel
	{
		TVALUE Channel1;
		TVALUE Channel2;
		TVALUE Channel3;
		TVALUE Channel4;

		QuadChannelPixel()
		{
		}

		QuadChannelPixel(TVALUE channel1, TVALUE channel2, TVALUE channel3, TVALUE channel4)
		{
			Channel1 = channel1;
			Channel2 = channel2;
			Channel3 = channel3;
			Channel4 = channel4;
		}

		/// <summary>
		/// Operator
		/// </summary>
		QuadChannelPixel<TVALUE>& operator =(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channel1 = pixel.Channel1;
			Channel2 = pixel.Channel2;
			Channel3 = pixel.Channel3;
			Channel4 = pixel.Channel4;

			return *this;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		QuadChannelPixel<TVALUE> operator *(const QuadChannelPixel<TVALUE>& pixel) const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p *= pixel;

			return p;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		QuadChannelPixel<TVALUE>& operator *=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channel1 = Channel1 * pixel.Channel1;
			Channel2 = Channel2 * pixel.Channel2;
			Channel3 = Channel3 * pixel.Channel3;
			Channel4 = Channel4 * pixel.Channel4;

			return *this;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		QuadChannelPixel<TVALUE> operator /(const QuadChannelPixel<TVALUE>& pixel) const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p /= pixel;

			return p;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		QuadChannelPixel<TVALUE>& operator /=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channel1 = Channel1 / pixel.Channel1;
			Channel2 = Channel2 / pixel.Channel2;
			Channel3 = Channel3 / pixel.Channel3;
			Channel4 = Channel4 / pixel.Channel4;

			return *this;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		QuadChannelPixel<TVALUE> operator |(const QuadChannelPixel<TVALUE>& pixel) const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p |= pixel;

			return p;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		QuadChannelPixel<TVALUE>& operator |=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channel1 = Channel1 | pixel.Channel1;
			Channel2 = Channel2 | pixel.Channel2;
			Channel3 = Channel3 | pixel.Channel3;
			Channel4 = Channel4 | pixel.Channel4;

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		QuadChannelPixel<TVALUE> operator &(const QuadChannelPixel<TVALUE>& pixel) const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p &= pixel;

			return p;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		QuadChannelPixel<TVALUE>& operator &=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channel1 = Channel1 & pixel.Channel1;
			Channel2 = Channel2 & pixel.Channel2;
			Channel3 = Channel3 & pixel.Channel3;
			Channel4 = Channel4 & pixel.Channel4;

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		QuadChannelPixel<TVALUE> operator !() const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p != p;

			return p;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator ==(const QuadChannelPixel<TVALUE>& pixel) const
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
		bool operator !=(const QuadChannelPixel<TVALUE>& pixel) const
		{
			return operator ==(pixel);
		}
	};
}

#endif // COMMONQUADCHANNELPIXEL_H
