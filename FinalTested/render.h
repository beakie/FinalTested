#ifndef RENDER_H
#define RENDER_H

#include "core.h"
#include "common.h"

namespace Render
{
	/// <summary>
	/// 1 byte precision RGB pixel
	/// </summary>
	typedef TripleChannelPixel<UInt_8> RGBPixel_8;
	/// <summary>
	/// 2 byte precision RGB pixel
	/// </summary>
	typedef TripleChannelPixel<UInt_16> RGBPixel_16;
	/// <summary>
	/// 4 byte precision RGB pixel
	/// </summary>
	typedef TripleChannelPixel<UInt_32> RGBPixel_32;
	/// <summary>
	/// 1 byte precision HSV pixel
	/// </summary>
	typedef TripleChannelPixel<UInt_8> HSVPixel_8;
	/// <summary>
	/// 2 byte precision HSV pixel
	/// </summary>
	typedef TripleChannelPixel<UInt_16> HSVPixel_16;
	/// <summary>
	/// 4 byte precision HSV pixel
	/// </summary>
	typedef TripleChannelPixel<UInt_32> HSVPixel_32;
	/// <summary>
	/// 1 byte precision RGBA pixel
	/// </summary>
	typedef QuadChannelPixel<UInt_8> RGBAPixel_8;
	/// <summary>
	/// 2 byte precision RGBA pixel
	/// </summary>
	typedef QuadChannelPixel<UInt_16> RGBAPixel_16;
	/// <summary>
	/// 4 byte precision RGBA pixel
	/// </summary>
	typedef QuadChannelPixel<UInt_32> RGBAPixel_32;
	/// <summary>
	/// 1 byte precision greyscale pixel
	/// </summary>
	typedef UInt_8 GreyPixel_8;
	/// <summary>
	/// 2 byte precision greyscale pixel
	/// </summary>
	typedef UInt_16 GreyPixel_16;
	/// <summary>
	/// 4 byte precision greyscale pixel
	/// </summary>
	typedef UInt_32 GreyPixel_32;

	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_8, UInt_8> Image8RGBPixel_8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_16, UInt_8> Image8RGBPixel_16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_32, UInt_8> Image8RGBPixel_32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_8, UInt_16> Image16RGBPixel_8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_16, UInt_16> Image16RGBPixel_16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_32, UInt_16> Image16RGBPixel_32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_8, UInt_8> Image8HSVPixel_8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_16, UInt_8> Image8HSVPixel_16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_32, UInt_8> Image8HSVPixel_32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_8, UInt_16> Image16HSVPixel_8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_16, UInt_16> Image16HSVPixel_16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_32, UInt_16> Image16HSVPixel_32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision RGBA pixels
	/// </summary>
	typedef Image<RGBAPixel_8, UInt_8> Image8RGBAPixel_8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision RGBA pixels
	/// </summary>
	typedef Image<RGBAPixel_16, UInt_8> Image8RGBAPixel_16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision RGBA pixels
	/// </summary>
	typedef Image<RGBAPixel_32, UInt_8> Image8RGBAPixel_32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision RGBA pixels
	/// </summary>
	typedef Image<RGBAPixel_8, UInt_16> Image16RGBAPixel_8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision RGBA pixels
	/// </summary>
	typedef Image<RGBAPixel_16, UInt_16> Image16RGBAPixel_16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision RGBA pixels
	/// </summary>
	typedef Image<RGBAPixel_32, UInt_16> Image16RGBAPixel_32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte greyscale pixels
	/// </summary>
	typedef Image<GreyPixel_8, UInt_8> Image8Grey_8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte greyscale pixels
	/// </summary>
	typedef Image<GreyPixel_16, UInt_8> Image8Grey_16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte greyscale pixels
	/// </summary>
	typedef Image<GreyPixel_32, UInt_8> Image8Grey_32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte greyscale pixels
	/// </summary>
	typedef Image<GreyPixel_8, UInt_16> Image16Grey_8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte greyscale pixels
	/// </summary>
	typedef Image<GreyPixel_16, UInt_16> Image16Grey_16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte greyscale pixels
	/// </summary>
	typedef Image<GreyPixel_32, UInt_16> Image16Grey_32;

}

#endif // RENDER_H
