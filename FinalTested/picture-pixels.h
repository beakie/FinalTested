#ifndef PICTUREPIXELS_H
#define PICTUREPIXELS_H

#include "picture-trichanpixel.h"
#include "picture-quadchanpixel.h"

namespace Picture
{
	static class Pixels
	{
	public:
		/// <summary>
		/// Returns the red from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelRed(const Picture::TriChanPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[0];
		}

		/// <summary>
		/// Returns the blues from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelBlue(const Picture::TriChanPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[1];
		}

		/// <summary>
		/// Returns the green from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelGreen(const Picture::TriChanPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Channels[2];
		}

		/// <summary>
		/// Returns the hue value an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelHue(const Picture::TriChanPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[0];
		}

		/// <summary>
		/// Returns the saturation from an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelSaturation(const Picture::TriChanPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[1];
		}

		/// <summary>
		/// Returns the value from an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelValue(const Picture::TriChanPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Channels[2];
		}

		/// <summary>
		/// Returns the red from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelRed(const Picture::QuadChanPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[0];
		}

		/// <summary>
		/// Returns the blue from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelBlue(const Picture::QuadChanPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[1];
		}

		/// <summary>
		/// Returns the green from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelGreen(const Picture::QuadChanPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[2];
		}

		/// <summary>
		/// Returns the alpha from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelAlpha(const Picture::QuadChanPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Channels[3];
		}

		/// <summary>
		/// Returns the alpha from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelAlpha(const Picture::QuadChanPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[0];
		}

		/// <summary>
		/// Returns the red from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBPixelRed(const Picture::QuadChanPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[1];
		}

		/// <summary>
		/// Returns the blue from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelBlue(const Picture::QuadChanPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[2];
		}

		/// <summary>
		/// Returns the green from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelGreen(const Picture::QuadChanPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Channels[3];
		}
	};
}

#endif // PICTUREPIXELS_H
