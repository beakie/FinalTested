#ifndef PICTURE_H
#define PICTURE_H

#include "core.h"
#include "common.h"

#include "picture-colormaps_.h"
#include "picture-quadchanpixel.h"
#include "picture-quadchanpixelconvbuilders_.h"
#include "picture-quadcolormap.h"
#include "picture-quadcolormapconv.h"
#include "picture-rgbpixelconvbuilders_.h"
#include "picture-rgbpixelhelpers_.h"
#include "picture-selectchanavgquadchanpixelconv.h"
#include "picture-selectchanavgtrichanpixelconv.h"
#include "picture-selectchanquadchanpixelconv.h"
#include "picture-selectchantrichanpixelconv.h"
#include "picture-spreadchanquadchanpixelconv.h"
#include "picture-spreadchantrichanpixelconv.h"
#include "picture-spreadvaluequadchanpixelconv.h"
#include "picture-spreadvaluetrichanpixelconv.h"
#include "picture-trichanpixel.h"
#include "picture-trichanpixelconvbuilders_.h"
#include "picture-tricolormap.h"
#include "picture-tricolormapconv.h"

namespace Picture
{
	/// <summary>
	/// 1 byte precision RGB pixel
	/// </summary>
	typedef Picture::TriChanPixel<UInt8> RGBPixel8;
	/// <summary>
	/// 2 byte precision RGB pixel
	/// </summary>
	typedef Picture::TriChanPixel<UInt16> RGBPixel16;
	/// <summary>
	/// 4 byte precision RGB pixel
	/// </summary>
	typedef Picture::TriChanPixel<UInt32> RGBPixel32;
	/// <summary>
	/// 1 byte precision HSV pixel
	/// </summary>
	typedef Picture::TriChanPixel<UInt8> HSVPixel8;
	/// <summary>
	/// 2 byte precision HSV pixel
	/// </summary>
	typedef Picture::TriChanPixel<UInt16> HSVPixel16;
	/// <summary>
	/// 4 byte precision HSV pixel
	/// </summary>
	typedef Picture::TriChanPixel<UInt32> HSVPixel32;
	/// <summary>
	/// 1 byte precision RGBA pixel
	/// </summary>
	typedef Picture::QuadChanPixel<UInt8> RGBAPixel8;
	/// <summary>
	/// 2 byte precision RGBA pixel
	/// </summary>
	typedef Picture::QuadChanPixel<UInt16> RGBAPixel16;
	/// <summary>
	/// 4 byte precision RGBA pixel
	/// </summary>
	typedef Picture::QuadChanPixel<UInt32> RGBAPixel32;
	/// <summary>
	/// 1 byte precision greyscale pixel
	/// </summary>
	typedef UInt8 GreyPixel8;
	/// <summary>
	/// 2 byte precision greyscale pixel
	/// </summary>
	typedef UInt16 GreyPixel16;
	/// <summary>
	/// 4 byte precision greyscale pixel
	/// </summary>
	typedef UInt32 GreyPixel32;

	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RGBPixel8, UInt8> Image8RGBPixel8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RGBPixel16, UInt8> Image8RGBPixel16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RGBPixel32, UInt8> Image8RGBPixel32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RGBPixel8, UInt16> Image16RGBPixel8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RGBPixel16, UInt16> Image16RGBPixel16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RGBPixel32, UInt16> Image16RGBPixel32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HSVPixel8, UInt8> Image8HSVPixel8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HSVPixel16, UInt8> Image8HSVPixel16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HSVPixel32, UInt8> Image8HSVPixel32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HSVPixel8, UInt16> Image16HSVPixel8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HSVPixel16, UInt16> Image16HSVPixel16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HSVPixel32, UInt16> Image16HSVPixel32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RGBAPixel8, UInt8> Image8RGBAPixel8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RGBAPixel16, UInt8> Image8RGBAPixel16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RGBAPixel32, UInt8> Image8RGBAPixel32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RGBAPixel8, UInt16> Image16RGBAPixel8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RGBAPixel16, UInt16> Image16RGBAPixel16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RGBAPixel32, UInt16> Image16RGBAPixel32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte greyscale pixels
	/// </summary>
	typedef Common::Image<GreyPixel8, UInt8> Image8Grey8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte greyscale pixels
	/// </summary>
	typedef Common::Image<GreyPixel16, UInt8> Image8Grey16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte greyscale pixels
	/// </summary>
	typedef Common::Image<GreyPixel32, UInt8> Image8Grey32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte greyscale pixels
	/// </summary>
	typedef Common::Image<GreyPixel8, UInt16> Image16Grey8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte greyscale pixels
	/// </summary>
	typedef Common::Image<GreyPixel16, UInt16> Image16Grey16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte greyscale pixels
	/// </summary>
	typedef Common::Image<GreyPixel32, UInt16> Image16Grey32;

	typedef TriColorMap<Float32> TriColorMap32;

	typedef TriColorMap<Float64> TriColorMap64;

	typedef QuadColorMap<Float32> QuadColorMap32;

	typedef QuadColorMap<Float64> QuadColorMap64;

	typedef TriColorMapConv<Common::UnitInterval32, Float32, UInt8> TriColorMap32Conv8;

	typedef TriColorMapConv<Common::UnitInterval32, Float32, UInt16> TriColorMap32Conv16;

	typedef TriColorMapConv<Common::UnitInterval32, Float32, UInt32> TriColorMap32Conv32;

	typedef TriColorMapConv<Common::UnitInterval64, Float64, UInt8> TriColorMap64Conv8;

	typedef TriColorMapConv<Common::UnitInterval64, Float64, UInt16> TriColorMap64Conv16;

	typedef TriColorMapConv<Common::UnitInterval64, Float64, UInt32> TriColorMap64Conv32;

	typedef QuadColorMapConv<Common::UnitInterval32, Float32, UInt8> QuadColorMap32Conv8;

	typedef QuadColorMapConv<Common::UnitInterval32, Float32, UInt16> QuadColorMap32Conv16;

	typedef QuadColorMapConv<Common::UnitInterval32, Float32, UInt32> QuadColorMap32Conv32;

	typedef QuadColorMapConv<Common::UnitInterval64, Float64, UInt8> QuadColorMap64Conv8;

	typedef QuadColorMapConv<Common::UnitInterval64, Float64, UInt16> QuadColorMap64Conv16;

	typedef QuadColorMapConv<Common::UnitInterval64, Float64, UInt32> QuadColorMap64Conv32;

}

#endif // PICTURE_H
