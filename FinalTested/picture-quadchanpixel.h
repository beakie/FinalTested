#ifndef PICTUREQUADCHANPIXEL_H
#define PICTUREQUADCHANPIXEL_H

namespace Picture
{
	template <typename TVALUE>
	/// <summary>
	/// Quadruple chan pixel
	/// </summary>
	struct QuadChanPixel
	{
		TVALUE Channels[3];

		QuadChanPixel()
		{
		}

		QuadChanPixel(TVALUE chan1, TVALUE chan2, TVALUE chan3, TVALUE chan4)
		{
			Channels[0] = chan1;
			Channels[1] = chan2;
			Channels[2] = chan3;
			Channels[3] = chan4;
		}

		/// <summary>
		/// Operator
		/// </summary>
		QuadChanPixel<TVALUE>& operator=(const QuadChanPixel<TVALUE>& pixel)
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
		QuadChanPixel<TVALUE> operator*(const QuadChanPixel<TVALUE>& pixel) const
		{
			QuadChanPixel<TVALUE> p = *this;

			p *= pixel;

			return p;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		QuadChanPixel<TVALUE>& operator*=(const QuadChanPixel<TVALUE>& pixel)
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
		QuadChanPixel<TVALUE> operator/(const QuadChanPixel<TVALUE>& pixel) const
		{
			QuadChanPixel<TVALUE> p = *this;

			p /= pixel;

			return p;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		QuadChanPixel<TVALUE>& operator/=(const QuadChanPixel<TVALUE>& pixel)
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
		QuadChanPixel<TVALUE> operator|(const QuadChanPixel<TVALUE>& pixel) const
		{
			QuadChanPixel<TVALUE> p = *this;

			p |= pixel;

			return p;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		QuadChanPixel<TVALUE>& operator|=(const QuadChanPixel<TVALUE>& pixel)
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
		QuadChanPixel<TVALUE> operator&(const QuadChanPixel<TVALUE>& pixel) const
		{
			QuadChanPixel<TVALUE> p = *this;

			p &= pixel;

			return p;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		QuadChanPixel<TVALUE>& operator&=(const QuadChanPixel<TVALUE>& pixel)
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
		QuadChanPixel<TVALUE> operator!() const
		{
			QuadChanPixel<TVALUE> p = *this;

			p != p;

			return p;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator==(const QuadChanPixel<TVALUE>& pixel) const
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
		bool operator!=(const QuadChanPixel<TVALUE>& pixel) const
		{
			return operator==(pixel);
		}
	};
}

#endif // PICTUREQUADCHANPIXEL_H
