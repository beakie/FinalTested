#ifndef COMMONPIXELS_H
#define COMMONPIXELS_H

#include "common-triplechannelpixel.h"
#include "common-quadchannelpixel.h"

namespace Common
{
	struct Pixels
	{
		/// <summary>
		/// Returns the red from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelRed(const TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[0];
		}

		/// <summary>
		/// Returns the blues from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelBlue(const TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[1];
		}

		/// <summary>
		/// Returns the green from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelGreen(const TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[2];
		}

		/// <summary>
		/// Returns the hue value an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelHue(const TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[0];
		}

		/// <summary>
		/// Returns the saturation from an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelSaturation(const TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[1];
		}

		/// <summary>
		/// Returns the value from an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelValue(const TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[2];
		}

		/// <summary>
		/// Returns the red from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelRed(const QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[0];
		}

		/// <summary>
		/// Returns the blue from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelBlue(const QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[1];
		}

		/// <summary>
		/// Returns the green from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelGreen(const QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[2];
		}

		/// <summary>
		/// Returns the alpha from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelAlpha(const QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[3];
		}

		/// <summary>
		/// Returns the alpha from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelAlpha(const QuadChannelPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[0];
		}

		/// <summary>
		/// Returns the red from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBPixelRed(const QuadChannelPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[1];
		}

		/// <summary>
		/// Returns the blue from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelBlue(const QuadChannelPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[2];
		}

		/// <summary>
		/// Returns the green from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelGreen(const QuadChannelPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[3];
		}
	};
}

#endif // COMMONPIXELS_H
