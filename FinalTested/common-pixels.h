#ifndef COMMONPIXELS_H
#define COMMONPIXELS_H

#include "common-triplechannelpixel.h"
#include "common-quadchannelpixel.h"

namespace Common
{
	template <typename TVALUE>
	struct Pixels
	{
		/// <summary>
		/// Returns the red from an RGB pixel
		/// </summary>
		static TVALUE getRed(const TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[0];
		}

		/// <summary>
		/// Returns the blues from an RGB pixel
		/// </summary>
		static TVALUE getBlue(const TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[1];
		}

		/// <summary>
		/// Returns the green from an RGB pixel
		/// </summary>
		static TVALUE getGreen(const TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[2];
		}

		/// <summary>
		/// Returns the hue value an HSV pixel
		/// </summary>
		static TVALUE getHue(const TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[0];
		}

		/// <summary>
		/// Returns the saturation from an HSV pixel
		/// </summary>
		static TVALUE getSaturation(const TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[1];
		}

		/// <summary>
		/// Returns the value from an HSV pixel
		/// </summary>
		static TVALUE getValue(const TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[2];
		}

		/// <summary>
		/// Returns the red from an RGBA pixel
		/// </summary>
		static TVALUE getRed(const QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[0];
		}

		/// <summary>
		/// Returns the blue from an RGBA pixel
		/// </summary>
		static TVALUE getBlue(const QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[1];
		}

		/// <summary>
		/// Returns the green from an RGBA pixel
		/// </summary>
		static TVALUE getGreen(const QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[2];
		}

		/// <summary>
		/// Returns the alpha from an RGBA pixel
		/// </summary>
		static TVALUE getAlpha(const QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[3];
		}
	};
}

#endif // COMMONPIXELS_H
