#ifndef COMMONTRIPLECHANNELPIXEL_H
#define COMMONTRIPLECHANNELPIXEL_H

namespace Common
{
	template <typename TVALUE>
	/// <summary>
	/// Quadruple channel pixel
	/// </summary>
	struct TripleChannelPixel
	{
		TVALUE Channels[3];

		TripleChannelPixel()
		{
		}

		TripleChannelPixel(TVALUE channel1, TVALUE channel2, TVALUE channel3)
		{
			Channels[0] = channel1;
			Channels[1] = channel2;
			Channels[2] = channel3;
		}

		/// <summary>
		/// Operator
		/// </summary>
		TripleChannelPixel<TVALUE>& operator =(const TripleChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = pixel.Channels[0];
			Channels[1] = pixel.Channels[1];
			Channels[2] = pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		TripleChannelPixel<TVALUE> operator *(const TripleChannelPixel<TVALUE>& pixel) const
		{
			TripleChannelPixel<TVALUE> p = *this;

			p *= pixel;

			return p;
		}

		/// <summary>
		/// Increase contrast
		/// </summary>
		TripleChannelPixel<TVALUE>& operator *=(const TripleChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] * pixel.Channels[0];
			Channels[1] = Channels[1] * pixel.Channels[1];
			Channels[2] = Channels[2] * pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		TripleChannelPixel<TVALUE> operator /(const TripleChannelPixel<TVALUE>& pixel) const
		{
			TripleChannelPixel<TVALUE> p = *this;

			p /= pixel;

			return p;
		}

		/// <summary>
		/// Decrease contrast
		/// </summary>
		TripleChannelPixel<TVALUE>& operator /=(const TripleChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] / pixel.Channels[0];
			Channels[1] = Channels[1] / pixel.Channels[1];
			Channels[2] = Channels[2] / pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		TripleChannelPixel<TVALUE> operator |(const TripleChannelPixel<TVALUE>& pixel) const
		{
			TripleChannelPixel<TVALUE> p = *this;

			p |= pixel;

			return p;
		}

		/// <summary>
		/// Logical OR
		/// </summary>
		TripleChannelPixel<TVALUE>& operator |=(const TripleChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] | pixel.Channels[0];
			Channels[1] = Channels[1] | pixel.Channels[1];
			Channels[2] = Channels[2] | pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		TripleChannelPixel<TVALUE> operator &(const TripleChannelPixel<TVALUE>& pixel) const
		{
			TripleChannelPixel<TVALUE> p = *this;

			p &= pixel;

			return p;
		}

		/// <summary>
		/// Logical AND
		/// </summary>
		TripleChannelPixel<TVALUE>& operator &=(const TripleChannelPixel<TVALUE>& pixel)
		{
			Channels[0] = Channels[0] & pixel.Channels[0];
			Channels[1] = Channels[1] & pixel.Channels[1];
			Channels[2] = Channels[2] & pixel.Channels[2];

			return *this;
		}

		/// <summary>
		/// Invert
		/// </summary>
		TripleChannelPixel<TVALUE> operator !() const
		{
			TripleChannelPixel<TVALUE> p = *this;

			p != p;

			return p;
		}

		/// <summary>
		/// Comparison
		/// </summary>
		bool operator ==(const TripleChannelPixel<TVALUE>& pixel) const
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
		bool operator !=(const TripleChannelPixel<TVALUE>& pixel) const
		{
			return operator ==(pixel);
		}
	};
}

#endif // COMMONTRIPLECHANNELPIXEL_H
