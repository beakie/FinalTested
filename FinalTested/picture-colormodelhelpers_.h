#ifndef PICTURECOLORMODELHELPERS_H
#define PICTURECOLORMODELHELPERS_H

#include "common.h"

namespace Picture
{
	/// <summary>
	/// Returns the red from an RGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbRed(const Common::Vector3<TVALUE>& rgbPixel)
	{
		return rgbPixel.Channels[0];
	}

	/// <summary>
	/// Returns the blues from an RGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbBlue(const Common::Vector3<TVALUE>& rgbPixel)
	{
		return rgbPixel.Channels[1];
	}

	/// <summary>
	/// Returns the green from an RGB pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbGreen(const Common::Vector3<TVALUE>& rgbPixel)
	{
		return rgbPixel.Channels[2];
	}

	/// <summary>
	/// Returns the hue value an HSV pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getHsvHue(const Common::Vector3<TVALUE>& hsvPixel)
	{
		return hsvPixel.Channels[0];
	}

	/// <summary>
	/// Returns the saturation from an HSV pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getHsvSaturation(const Common::Vector3<TVALUE>& hsvPixel)
	{
		return hsvPixel.Channels[1];
	}

	/// <summary>
	/// Returns the value from an HSV pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getHsvValue(const Common::Vector3<TVALUE>& hsvPixel)
	{
		return hsvPixel.Channels[2];
	}

	/// <summary>
	/// Returns the red from an RGBA pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbaRed(const Common::Vector4<TVALUE>& rgbaPixel)
	{
		return rgbaPixel.Channels[0];
	}

	/// <summary>
	/// Returns the blue from an RGBA pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbaBlue(const Common::Vector4<TVALUE>& rgbaPixel)
	{
		return rgbaPixel.Channels[1];
	}

	/// <summary>
	/// Returns the green from an RGBA pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbaGreen(const Common::Vector4<TVALUE>& rgbaPixel)
	{
		return rgbaPixel.Channels[2];
	}

	/// <summary>
	/// Returns the alpha from an RGBA pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getRgbaAlpha(const Common::Vector4<TVALUE>& rgbaPixel)
	{
		return rgbaPixel.Channels[3];
	}

	/// <summary>
	/// Returns the red from an CMYK pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getCmykCyan(const Common::Vector4<TVALUE>& cmykPixel)
	{
		return cmykPixel.Channels[0];
	}

	/// <summary>
	/// Returns the blue from an CMYK pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getCmykMagenta(const Common::Vector4<TVALUE>& cmykPixel)
	{
		return cmykPixel.Channels[1];
	}

	/// <summary>
	/// Returns the green from an CMYK pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getCmykYellow(const Common::Vector4<TVALUE>& cmykPixel)
	{
		return cmykPixel.Channels[2];
	}

	/// <summary>
	/// Returns the alpha from an CMYK pixel
	/// </summary>
	template <typename TVALUE>
	static TVALUE getCmykKey(const Common::Vector4<TVALUE>& cmykPixel)
	{
		return cmykPixel.Channels[3];
	}
}

#endif // PICTURECOLORMODELHELPERS_H
