#ifndef DRAWINGPIXELS_H
#define DRAWINGPIXELS_H

#include "common-triplechannelpixel.h"
#include "common-quadchannelpixel.h"

namespace Drawing
{
	static class Pixels
	{
	public:
		/// <summary>
		/// Returns the red from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelRed(const Common::TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[0];
		}

		/// <summary>
		/// Returns the blues from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelBlue(const Common::TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[1];
		}

		/// <summary>
		/// Returns the green from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelGreen(const Common::TripleChannelPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[2];
		}

		/// <summary>
		/// Returns the hue value an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelHue(const Common::TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[0];
		}

		/// <summary>
		/// Returns the saturation from an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelSaturation(const Common::TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[1];
		}

		/// <summary>
		/// Returns the value from an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelValue(const Common::TripleChannelPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[2];
		}

		/// <summary>
		/// Returns the red from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelRed(const Common::QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[0];
		}

		/// <summary>
		/// Returns the blue from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelBlue(const Common::QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[1];
		}

		/// <summary>
		/// Returns the green from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelGreen(const Common::QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[2];
		}

		/// <summary>
		/// Returns the alpha from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelAlpha(const Common::QuadChannelPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[3];
		}

		/// <summary>
		/// Returns the alpha from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelAlpha(const Common::QuadChannelPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[0];
		}

		/// <summary>
		/// Returns the red from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBPixelRed(const Common::QuadChannelPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[1];
		}

		/// <summary>
		/// Returns the blue from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelBlue(const Common::QuadChannelPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[2];
		}

		/// <summary>
		/// Returns the green from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelGreen(const Common::QuadChannelPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[3];
		}
	};
}

#endif // DRAWINGPIXELS_H
