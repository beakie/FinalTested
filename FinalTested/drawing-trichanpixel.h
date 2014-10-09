#ifndef DRAWINGTRICHANPIXEL_H
#define DRAWINGTRICHANPIXEL_H

namespace Drawing
{
	template <typename TVALUE>
	/// <summary>
	/// Triple channel pixel
	/// </summary>
	struct TriChanPixel
	{
		TVALUE Chans[3];

		TriChanPixel()
		{
		}

		TriChanPixel(TVALUE chan1, TVALUE chan2, TVALUE chan3)
		{
			Chans[0] = chan1;
			Chans[1] = chan2;
			Chans[2] = chan3;
		}

		/// <summary>
		/// Operator
		/// </summary>
		TriChanPixel<TVALUE>& operator=(const TriChanPixel<TVALUE>& pixel)
		{
			Chans[0] = pixel.Chans[0];
			Chans[1] = pixel.Chans[1];
			Chans[2] = pixel.Chans[2];

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
			Chans[0] = Chans[0] * pixel.Chans[0];
			Chans[1] = Chans[1] * pixel.Chans[1];
			Chans[2] = Chans[2] * pixel.Chans[2];

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
			Chans[0] = Chans[0] / pixel.Chans[0];
			Chans[1] = Chans[1] / pixel.Chans[1];
			Chans[2] = Chans[2] / pixel.Chans[2];

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
			Chans[0] = Chans[0] | pixel.Chans[0];
			Chans[1] = Chans[1] | pixel.Chans[1];
			Chans[2] = Chans[2] | pixel.Chans[2];

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
			Chans[0] = Chans[0] & pixel.Chans[0];
			Chans[1] = Chans[1] & pixel.Chans[1];
			Chans[2] = Chans[2] & pixel.Chans[2];

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

#endif // DRAWINGTRICHANPIXEL_H
