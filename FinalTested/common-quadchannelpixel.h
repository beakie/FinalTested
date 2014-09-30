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
		TVALUE Channels[3];

		QuadChannelPixel()
		{
		}

		QuadChannelPixel(TVALUE channel1, TVALUE channel2, TVALUE channel3, TVALUE channel4)
		{
			Channels[0] = channel1;
			Channels[1] = channel2;
			Channels[2] = channel3;
			Channels[3] = channel4;
		}

		/// <summary>
		/// Operator
		/// </summary>
		QuadChannelPixel<TVALUE>& operator=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = pixel.Channels[0];
			Channels[1] = pixel.Channels[1];
			Channels[2] = pixel.Channels[2];
			Channels[3] = pixel.Channels[3];

			return *this;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		QuadChannelPixel<TVALUE> operator*(const QuadChannelPixel<TVALUE>& pixel) const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p *= pixel;

			return p;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		QuadChannelPixel<TVALUE>& operator*=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] * pixel.Channels[0];
			Channels[1] = Channels[1] * pixel.Channels[1];
			Channels[2] = Channels[2] * pixel.Channels[2];
			Channels[3] = Channels[3] * pixel.Channels[3];

			return *this;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		QuadChannelPixel<TVALUE> operator/(const QuadChannelPixel<TVALUE>& pixel) const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p /= pixel;

			return p;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		QuadChannelPixel<TVALUE>& operator/=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] / pixel.Channels[0];
			Channels[1] = Channels[1] / pixel.Channels[1];
			Channels[2] = Channels[2] / pixel.Channels[2];
			Channels[3] = Channels[3] / pixel.Channels[3];

			return *this;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		QuadChannelPixel<TVALUE> operator|(const QuadChannelPixel<TVALUE>& pixel) const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p |= pixel;

			return p;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		QuadChannelPixel<TVALUE>& operator|=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] | pixel.Channels[0];
			Channels[1] = Channels[1] | pixel.Channels[1];
			Channels[2] = Channels[2] | pixel.Channels[2];
			Channels[3] = Channels[3] | pixel.Channels[3];

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		QuadChannelPixel<TVALUE> operator&(const QuadChannelPixel<TVALUE>& pixel) const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p &= pixel;

			return p;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		QuadChannelPixel<TVALUE>& operator&=(const QuadChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] & pixel.Channels[0];
			Channels[1] = Channels[1] & pixel.Channels[1];
			Channels[2] = Channels[2] & pixel.Channels[2];
			Channels[3] = Channels[3] & pixel.Channels[3];

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		QuadChannelPixel<TVALUE> operator!() const
		{
			QuadChannelPixel<TVALUE> p = *this;

			p != p;

			return p;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator==(const QuadChannelPixel<TVALUE>& pixel) const
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
		bool operator!=(const QuadChannelPixel<TVALUE>& pixel) const
		{
			return operator==(pixel);
		}
	};
}

#endif // COMMONQUADCHANNELPIXEL_H
