#ifndef DRAWING_H
#define DRAWING_H

#include "core.h"
#include "common.h"

#include "drawing-colormapbuilders.h"
#include "drawing-imagerender.h"
#include "drawing-images.h"
#include "drawing-pixels.h"
#include "drawing-quadchannelpixel.h"
#include "drawing-triplecolormap.h"
#include "drawing-triplechannelpixel.h"

///// MOVE THE TRIPLE, QUAD AND IMAGES CODE TO THIS NAMESPACE /////

namespace Drawing
{
	/// <summary>
	/// 1 byte precision RGB pixel
	/// </summary>
	typedef Drawing::TripleChannelPixel<UInt8> RGBPixel8;
	/// <summary>
	/// 2 byte precision RGB pixel
	/// </summary>
	typedef Drawing::TripleChannelPixel<UInt16> RGBPixel16;
	/// <summary>
	/// 4 byte precision RGB pixel
	/// </summary>
	typedef Drawing::TripleChannelPixel<UInt32> RGBPixel32;
	/// <summary>
	/// 1 byte precision HSV pixel
	/// </summary>
	typedef Drawing::TripleChannelPixel<UInt8> HSVPixel8;
	/// <summary>
	/// 2 byte precision HSV pixel
	/// </summary>
	typedef Drawing::TripleChannelPixel<UInt16> HSVPixel16;
	/// <summary>
	/// 4 byte precision HSV pixel
	/// </summary>
	typedef Drawing::TripleChannelPixel<UInt32> HSVPixel32;
	/// <summary>
	/// 1 byte precision RGBA pixel
	/// </summary>
	typedef Drawing::QuadChannelPixel<UInt8> RGBAPixel8;
	/// <summary>
	/// 2 byte precision RGBA pixel
	/// </summary>
	typedef Drawing::QuadChannelPixel<UInt16> RGBAPixel16;
	/// <summary>
	/// 4 byte precision RGBA pixel
	/// </summary>
	typedef Drawing::QuadChannelPixel<UInt32> RGBAPixel32;
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

}

#endif // DRAWING_H
