#ifndef COMMON_H
#define COMMON_H

#include "core.h"
#include "common-array.h"
#include "common-hsvpixel.h"
#include "common-image.h"
#include "common-imatrixadapter.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixadapter.h"
#include "common-matrixn.h"
#include "common-quadchannelpixel.h"
#include "common-rgbpixel.h"
#include "common-static.h"
#include "common-triplechannelpixel.h"

namespace Common
{
	/// <summary>
	/// matrix of size 2 with 1 bit values
	/// </summary>
	typedef Matrix2<UInt_1> Matrix2_1;
	/// <summary>
	/// matrix of size 3 with 1 bit values
	/// </summary>
	typedef Matrix3<UInt_1> Matrix3_1;
	/// <summary>
	/// matrix of size 4 with 1 bit values
	/// </summary>
	typedef Matrix4<UInt_1> Matrix4_1;
	/// <summary>
	/// matrix of size 2 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt_8> Matrix2_8;
	/// <summary>
	/// matrix of size 3 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt_8> Matrix3_8;
	/// <summary>
	/// matrix of size 4 with 1 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt_8> Matrix4_8;
	/// <summary>
	/// matrix of size 2 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt_16> Matrix2_16;
	/// <summary>
	/// matrix of size 3 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt_16> Matrix3_16;
	/// <summary>
	/// matrix of size 4 with 2 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt_16> Matrix4_16;
	/// <summary>
	/// matrix of size 2 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix2<UInt_32> Matrix2_32;
	/// <summary>
	/// matrix of size 3 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix3<UInt_32> Matrix3_32;
	/// <summary>
	/// matrix of size 4 with 4 byte unsigned integer values
	/// </summary>
	typedef Matrix4<UInt_32> Matrix4_32;
	/// <summary>
	/// matrix of size 2 with 1 byte signed integer values
	/// </summary>
	typedef Matrix2<Int_8> Matrix2_I8;
	/// <summary>
	/// matrix of size 3 with 1 byte signed integer values
	/// </summary>
	typedef Matrix3<Int_8> Matrix3_I8;
	/// <summary>
	/// matrix of size 4 with 1 byte signed integer values
	/// </summary>
	typedef Matrix4<Int_8> Matrix4_I8;
	/// <summary>
	/// matrix of size 2 with 2 byte signed integer values
	/// </summary>
	typedef Matrix2<Int_16> Matrix2_I16;
	/// <summary>
	/// matrix of size 3 with 2 byte signed integer values
	/// </summary>
	typedef Matrix3<Int_16> Matrix3_I16;
	/// <summary>
	/// matrix of size 4 with 2 byte signed integer values
	/// </summary>
	typedef Matrix4<Int_16> Matrix4_I16;
	/// <summary>
	/// matrix of size 2 with 4 byte signed integer values
	/// </summary>
	typedef Matrix2<Int_32> Matrix2_I32;
	/// <summary>
	/// matrix of size 3 with 4 byte signed integer values
	/// </summary>
	typedef Matrix3<Int_32> Matrix3_I32;
	/// <summary>
	/// matrix of size 4 with 4 byte signed integer values
	/// </summary>
	typedef Matrix4<Int_32> Matrix4_I32;
	/// <summary>
	/// matrix of size 2 with floating point values
	/// </summary>
	typedef Matrix2<Float> Matrix2_F;
	/// <summary>
	/// matrix of size 3 with floating point values
	/// </summary>
	typedef Matrix3<Float> Matrix3_F;
	/// <summary>
	/// matrix of size 4 with floating point values
	/// </summary>
	typedef Matrix4<Float> Matrix4_F;
	/// <summary>
	/// Adapter for matrix of size 2 with 1 bit values
	/// </summary>
	typedef MatrixAdapter<Matrix2_1, UInt_1> Matrix2Adapter_1;
	/// <summary>
	/// Adapter for matrix of size 3 with 1 bit values
	/// </summary>
	typedef MatrixAdapter<Matrix3_1, UInt_1> Matrix3Adapter_1;
	/// <summary>
	/// Adapter for matrix of size 4 with 1 bit values
	/// </summary>
	typedef MatrixAdapter<Matrix4_1, UInt_1> Matrix4Adapter_1;
	/// <summary>
	/// Adapter for matrix of size 2 with 1 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2_8, UInt_8> Matrix2Adapter_8;
	/// <summary>
	/// Adapter for matrix of size 3 with 1 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3_8, UInt_8> Matrix3Adapter_8;
	/// <summary>
	/// Adapter for matrix of size 4 with 1 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4_8, UInt_8> Matrix4Adapter_8;
	/// <summary>
	/// Adapter for matrix of size 2 with 2 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2_16, UInt_16> Matrix2Adapter_16;
	/// <summary>
	/// Adapter for matrix of size 3 with 2 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3_16, UInt_16> Matrix3Adapter_16;
	/// <summary>
	/// Adapter for matrix of size 4 with 2 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4_16, UInt_16> Matrix4Adapter_16;
	/// <summary>
	/// Adapter for matrix of size 2 with 4 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2_32, UInt_32> Matrix2Adapter_32;
	/// <summary>
	/// Adapter for matrix of size 3 with 4 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3_32, UInt_32> Matrix3Adapter_32;
	/// <summary>
	/// Adapter for matrix of size 4 with 4 byte unsigned integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4_32, UInt_32> Matrix4Adapter_32;
	/// <summary>
	/// Adapter for matrix of size 2 with 1 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2_8, Int_8> Matrix2Adapter_I8;
	/// <summary>
	/// Adapter for matrix of size 3 with 1 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3_8, Int_8> Matrix3Adapter_I8;
	/// <summary>
	/// Adapter for matrix of size 4 with 1 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4_8, Int_8> Matrix4Adapter_I8;
	/// <summary>
	/// Adapter for matrix of size 2 with 2 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2_16, Int_16> Matrix2Adapter_I16;
	/// <summary>
	/// Adapter for matrix of size 3 with 2 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3_16, Int_16> Matrix3Adapter_I16;
	/// <summary>
	/// Adapter for matrix of size 4 with 2 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4_16, Int_16> Matrix4Adapter_I16;
	/// <summary>
	/// Adapter for matrix of size 2 with 4 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix2_32, Int_32> Matrix2Adapter_I32;
	/// <summary>
	/// Adapter for matrix of size 3 with 4 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix3_32, Int_32> Matrix3Adapter_I32;
	/// <summary>
	/// Adapter for matrix of size 4 with 4 byte signed integer values
	/// </summary>
	typedef MatrixAdapter<Matrix4_32, Int_32> Matrix4Adapter_I32;
	/// <summary>
	/// Adapter for matrix of size 2 with floating point values
	/// </summary>
	typedef MatrixAdapter<Matrix2_F, Float> Matrix2Adapter_F;
	/// <summary>
	/// Adapter for matrix of size 3 with floating point values
	/// </summary>
	typedef MatrixAdapter<Matrix3_F, Float> Matrix3Adapter_F;
	/// <summary>
	/// Adapter for matrix of size 4 with floating point values
	/// </summary>
	typedef MatrixAdapter<Matrix4_F, Float> Matrix4Adapter_F;
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
	/// Image with 1 byte dimensions and 1 bit pixels
	/// </summary>
	typedef Image<UInt_1, UInt_8> Image8_1;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte pixels
	/// </summary>
	typedef Image<UInt_8, UInt_8> Image8_8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte pixels
	/// </summary>
	typedef Image<UInt_16, UInt_8> Image8_16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte pixels
	/// </summary>
	typedef Image<UInt_32, UInt_8> Image8_32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 bit pixels
	/// </summary>
	typedef Image<UInt_1, UInt_16> Image16_1;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte pixels
	/// </summary>
	typedef Image<UInt_8, UInt_16> Image16_8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte pixels
	/// </summary>
	typedef Image<UInt_16, UInt_16> Image16_16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte pixels
	/// </summary>
	typedef Image<UInt_32, UInt_16> Image16_32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_8, UInt_8> Image8RGB_8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_16, UInt_8> Image8RGB_16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_32, UInt_8> Image8RGB_32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_8, UInt_16> Image16RGB_8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_16, UInt_16> Image16RGB_16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision RGB pixels
	/// </summary>
	typedef Image<RGBPixel_32, UInt_16> Image16RGB_32;
	/// <summary>
	/// Image with 1 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_8, UInt_8> Image8HSV_8;
	/// <summary>
	/// Image with 1 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_16, UInt_8> Image8HSV_16;
	/// <summary>
	/// Image with 1 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_32, UInt_8> Image8HSV_32;
	/// <summary>
	/// Image with 2 byte dimensions and 1 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_8, UInt_16> Image16HSV_8;
	/// <summary>
	/// Image with 2 byte dimensions and 2 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_16, UInt_16> Image16HSV_16;
	/// <summary>
	/// Image with 2 byte dimensions and 4 byte precision HSV pixels
	/// </summary>
	typedef Image<HSVPixel_32, UInt_16> Image16HSV_32;
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

#endif // COMMON_H
