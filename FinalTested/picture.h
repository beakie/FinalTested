#ifndef PICTURE_H
#define PICTURE_H

#include "core.h"
#include "common.h"

// todo
// picture-rgbtohsvpixelconv
// picture-hsvtorgbpixelconv
//..and the rest

//http://en.wikipedia.org/wiki/List_of_color_spaces_and_their_uses
//color spaces
//rgba
//cmyk
//rgb
//hsv
//yuv


#include "picture-colormaps_.h"
#include "picture-quadchanpixel.h"
#include "picture-quadchanpixelconvbuilders_.h"
#include "picture-quadcolormap.h"
#include "picture-quadcolormapconv.h"
#include "picture-colormodelconvbuilders_.h"
#include "picture-colormodelhelpers_.h"
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
	typedef TriChanPixel<UInt8> RgbPixel8;
	/// <summary>
	/// 2 byte precision RGB pixel
	/// </summary>
	typedef TriChanPixel<UInt16> RgbPixel16;
	/// <summary>
	/// 4 byte precision RGB pixel
	/// </summary>
	typedef TriChanPixel<UInt32> RgbPixel32;
	/// <summary>
	/// 1 byte precision HSV pixel
	/// </summary>
	typedef TriChanPixel<UInt8> HsvPixel8;
	/// <summary>
	/// 2 byte precision HSV pixel
	/// </summary>
	typedef TriChanPixel<UInt16> HsvPixel16;
	/// <summary>
	/// 4 byte precision HSV pixel
	/// </summary>
	typedef TriChanPixel<UInt32> HsvPixel32;
	/// <summary>
	/// 1 byte precision RGBA pixel
	/// </summary>
	typedef QuadChanPixel<UInt8> RgbaPixel8;
	/// <summary>
	/// 2 byte precision RGBA pixel
	/// </summary>
	typedef QuadChanPixel<UInt16> RgbaPixel16;
	/// <summary>
	/// 4 byte precision RGBA pixel
	/// </summary>
	typedef QuadChanPixel<UInt32> RgbaPixel32;
	/// <summary>
	/// 1 byte precision CMYK pixel
	/// </summary>
	typedef QuadChanPixel<UInt8> CmykPixel8;
	/// <summary>
	/// 2 byte precision CMYK pixel
	/// </summary>
	typedef QuadChanPixel<UInt16> CmykPixel16;
	/// <summary>
	/// 4 byte precision CMYK pixel
	/// </summary>
	typedef QuadChanPixel<UInt32> CmykPixel32;
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
	typedef Common::Image<RgbPixel8, UInt8> Image8RgbPixel8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RgbPixel16, UInt8> Image8RgbPixel16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RgbPixel32, UInt8> Image8RgbPixel32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RgbPixel8, UInt16> Image16RgbPixel8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RgbPixel16, UInt16> Image16RgbPixel16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Common::Image<RgbPixel32, UInt16> Image16RgbPixel32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HsvPixel8, UInt8> Image8HsvPixel8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HsvPixel16, UInt8> Image8HsvPixel16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HsvPixel32, UInt8> Image8HsvPixel32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HsvPixel8, UInt16> Image16HsvPixel8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HsvPixel16, UInt16> Image16HsvPixel16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Common::Image<HsvPixel32, UInt16> Image16HsvPixel32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RgbaPixel8, UInt8> Image8RgbaPixel8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RgbaPixel16, UInt8> Image8RgbaPixel16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RgbaPixel32, UInt8> Image8RgbaPixel32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RgbaPixel8, UInt16> Image16RgbaPixel8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RgbaPixel16, UInt16> Image16RgbaPixel16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision RGBA pixels
	/// </summary>
	typedef Common::Image<RgbaPixel32, UInt16> Image16RgbaPixel32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<RgbaPixel8, UInt8> Image8CmykPixel8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<RgbaPixel16, UInt8> Image8CmykPixel16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<RgbaPixel32, UInt8> Image8CmykPixel32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<RgbaPixel8, UInt16> Image16CmykPixel8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<RgbaPixel16, UInt16> Image16CmykPixel16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision CMYK pixels
	/// </summary>
	typedef Common::Image<RgbaPixel32, UInt16> Image16CmykPixel32;
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

	//add the rest of these functions. relying entirly on floats sucks.

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
