#ifndef PICTURETRICHANPIXEL_H
#define PICTURETRICHANPIXEL_H

namespace Picture
{
	template <typename TVALUE>
	/// <summary>
	/// Triple channel pixel
	/// </summary>
	struct TriChanPixel
	{
		TVALUE Channels[3];

		TriChanPixel()
		{
		}

		TriChanPixel(TVALUE chan1, TVALUE chan2, TVALUE chan3)
		{
			Channels[0] = chan1;
			Channels[1] = chan2;
			Channels[2] = chan3;
		}

		/// <summary>
		/// Operator
		/// </summary>
		TriChanPixel<TVALUE>& operator=(const TriChanPixel<TVALUE>& pixel)
		{
			Channels[0] = pixel.Channels[0];
			Channels[1] = pixel.Channels[1];
			Channels[2] = pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		TriChanPixel<TVALUE>& operator=(const TVALUE value)
		{
			Channels[0] = value;
			Channels[1] = value;
			Channels[2] = value;

			return *this;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		TriChanPixel<TVALUE> operator*(const TriChanPixel<TVALUE>& pixel) const
		{
			TriChanPixel<TVALUE> p = *this;

			p *= pixel;

			return p;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		TriChanPixel<TVALUE>& operator*=(const TriChanPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] * pixel.Channels[0];
			Channels[1] = Channels[1] * pixel.Channels[1];
			Channels[2] = Channels[2] * pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		TriChanPixel<TVALUE> operator/(const TriChanPixel<TVALUE>& pixel) const
		{
			TriChanPixel<TVALUE> p = *this;

			p /= pixel;

			return p;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		TriChanPixel<TVALUE>& operator/=(const TriChanPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] / pixel.Channels[0];
			Channels[1] = Channels[1] / pixel.Channels[1];
			Channels[2] = Channels[2] / pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		TriChanPixel<TVALUE> operator|(const TriChanPixel<TVALUE>& pixel) const
		{
			TriChanPixel<TVALUE> p = *this;

			p |= pixel;

			return p;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		TriChanPixel<TVALUE>& operator|=(const TriChanPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] | pixel.Channels[0];
			Channels[1] = Channels[1] | pixel.Channels[1];
			Channels[2] = Channels[2] | pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		TriChanPixel<TVALUE> operator&(const TriChanPixel<TVALUE>& pixel) const
		{
			TriChanPixel<TVALUE> p = *this;

			p &= pixel;

			return p;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		TriChanPixel<TVALUE>& operator&=(const TriChanPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] & pixel.Channels[0];
			Channels[1] = Channels[1] & pixel.Channels[1];
			Channels[2] = Channels[2] & pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		TriChanPixel<TVALUE> operator!() const
		{
			TriChanPixel<TVALUE> p = *this;

			p != p;

			return p;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator==(const TriChanPixel<TVALUE>& pixel) const
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
		bool operator!=(const TriChanPixel<TVALUE>& pixel) const
		{
			return operator==(pixel);
		}
	};
}

#endif // PICTURETRICHANPIXEL_H
