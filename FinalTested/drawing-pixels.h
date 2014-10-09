#ifndef DRAWINGPIXELS_H
#define DRAWINGPIXELS_H

#include "drawing-trichanpixel.h"
#include "drawing-quadchanpixel.h"

namespace Drawing
{
	static class Pixels
	{
	public:
		/// <summary>
		/// Returns the red from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelRed(const Drawing::TriChanPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Chans[0];
		}

		/// <summary>
		/// Returns the blues from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelBlue(const Drawing::TriChanPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Chans[1];
		}

		/// <summary>
		/// Returns the green from an RGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBPixelGreen(const Drawing::TriChanPixel<TVALUE>& rgbPixel)
		{
			return rgbPixel.Chans[2];
		}

		/// <summary>
		/// Returns the hue value an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelHue(const Drawing::TriChanPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Chans[0];
		}

		/// <summary>
		/// Returns the saturation from an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelSaturation(const Drawing::TriChanPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Chans[1];
		}

		/// <summary>
		/// Returns the value from an HSV pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getHSVPixelValue(const Drawing::TriChanPixel<TVALUE>& hsvPixel)
		{
			return hsvPixel.Chans[2];
		}

		/// <summary>
		/// Returns the red from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelRed(const Drawing::QuadChanPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Chans[0];
		}

		/// <summary>
		/// Returns the blue from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelBlue(const Drawing::QuadChanPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Chans[1];
		}

		/// <summary>
		/// Returns the green from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelGreen(const Drawing::QuadChanPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Chans[2];
		}

		/// <summary>
		/// Returns the alpha from an RGBA pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getRGBAPixelAlpha(const Drawing::QuadChanPixel<TVALUE>& rgbaPixel)
		{
			return rgbaPixel.Chans[3];
		}

		/// <summary>
		/// Returns the alpha from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelAlpha(const Drawing::QuadChanPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Chans[0];
		}

		/// <summary>
		/// Returns the red from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBPixelRed(const Drawing::QuadChanPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Chans[1];
		}

		/// <summary>
		/// Returns the blue from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelBlue(const Drawing::QuadChanPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Chans[2];
		}

		/// <summary>
		/// Returns the green from an ARGB pixel
		/// </summary>
		template <typename TVALUE>
		static TVALUE getARGBAPixelGreen(const Drawing::QuadChanPixel<TVALUE>& argbPixel)
		{
			return argbPixel.Chans[3];
		}
	};
}

#endif // DRAWINGPIXELS_H
