#ifndef COMMON_H
#define COMMON_H

#include "common-array.h"
#include "common-hsvpixel.h"
#include "common-image.h"
#include "common-imatrixadapter.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixadapter.h"
#include "common-matrixn.h"
#include "common-rgbpixel.h"
#include "common-static.h"

namespace Common
{
	typedef Matrix2<bool> Matrix2_2;
	typedef Matrix3<bool> Matrix3_2;
	typedef Matrix4<bool> Matrix4_2;
	typedef Matrix2<signed char> Matrix2_8;
	typedef Matrix3<signed char> Matrix3_8;
	typedef Matrix4<signed char> Matrix4_8;
	typedef Matrix2<signed short> Matrix2_16;
	typedef Matrix3<signed short> Matrix3_16;
	typedef Matrix4<signed short> Matrix4_16;
	typedef Matrix2<signed int> Matrix2_32;
	typedef Matrix3<signed int> Matrix3_32;
	typedef Matrix4<signed int> Matrix4_32;
	typedef Matrix2<double> Matrix2_64;
	typedef Matrix3<double> Matrix3_64;
	typedef Matrix4<double> Matrix4_64;
	typedef Matrix2<float> Matrix2_F;
	typedef Matrix3<float> Matrix3_F;
	typedef Matrix4<float> Matrix4_F;

	typedef MatrixAdapter<Matrix2_2, bool> Matrix2Adapter_2;
	typedef MatrixAdapter<Matrix3_2, bool> Matrix3Adapter_2;
	typedef MatrixAdapter<Matrix4_2, bool> Matrix4Adapter_2;
	typedef MatrixAdapter<Matrix2_8, signed char> Matrix2Adapter_8;
	typedef MatrixAdapter<Matrix3_8, signed char> Matrix3Adapter_8;
	typedef MatrixAdapter<Matrix4_8, signed char> Matrix4Adapter_8;
	typedef MatrixAdapter<Matrix2_16, signed short> Matrix2Adapter_16;
	typedef MatrixAdapter<Matrix3_16, signed short> Matrix3Adapter_16;
	typedef MatrixAdapter<Matrix4_16, signed short> Matrix4Adapter_16;
	typedef MatrixAdapter<Matrix2_32, signed int> Matrix2Adapter_32;
	typedef MatrixAdapter<Matrix3_32, signed int> Matrix3Adapter_32;
	typedef MatrixAdapter<Matrix4_32, signed int> Matrix4Adapter_32;
	typedef MatrixAdapter<Matrix2_64, double> Matrix2Adapter_64;
	typedef MatrixAdapter<Matrix3_64, double> Matrix3Adapter_64;
	typedef MatrixAdapter<Matrix4_64, double> Matrix4Adapter_64;
	typedef MatrixAdapter<Matrix2_F, float> Matrix2Adapter_F;
	typedef MatrixAdapter<Matrix3_F, float> Matrix3Adapter_F;
	typedef MatrixAdapter<Matrix4_F, float> Matrix4Adapter_F;

	typedef RGBPixel<unsigned char> RGBPixel_8;
	typedef RGBPixel<unsigned short> RGBPixel_16;
	typedef RGBPixel<unsigned int> RGBPixel_32;

	typedef HSVPixel<unsigned char> HSVPixel_8;
	typedef HSVPixel<unsigned short> HSVPixel_16;
	typedef HSVPixel<unsigned int> HSVPixel_32;

	typedef unsigned char GreyPixel_8;
	typedef unsigned short GreyPixel_16;
	typedef unsigned int GreyPixel_32;

	typedef Image<bool, unsigned char> Image8_2;
	typedef Image<unsigned char, unsigned char> Image8_8;
	typedef Image<unsigned short, unsigned char> Image8_16;
	typedef Image<unsigned int, unsigned char> Image8_32;
	typedef Image<bool, unsigned short> Image16_2;
	typedef Image<unsigned char, unsigned short> Image16_8;
	typedef Image<unsigned short, unsigned short> Image16_16;
	typedef Image<unsigned int, unsigned short> Image16_32;

	typedef Image<RGBPixel_8, unsigned char> Image8RGB_8;
	typedef Image<RGBPixel_16, unsigned char> Image8RGB_16;
	typedef Image<RGBPixel_32, unsigned char> Image8RGB_32;
	typedef Image<RGBPixel_8, unsigned short> Image16RGB_8;
	typedef Image<RGBPixel_16, unsigned short> Image16RGB_16;
	typedef Image<RGBPixel_32, unsigned short> Image16RGB_32;

	typedef Image<HSVPixel_8, unsigned char> Image8HSV_8;
	typedef Image<HSVPixel_16, unsigned char> Image8HSV_16;
	typedef Image<HSVPixel_32, unsigned char> Image8HSV_32;
	typedef Image<HSVPixel_8, unsigned short> Image16HSV_8;
	typedef Image<HSVPixel_16, unsigned short> Image16HSV_16;
	typedef Image<HSVPixel_32, unsigned short> Image16HSV_32;

	typedef Image<GreyPixel_8, unsigned char> Image8Grey_8;
	typedef Image<GreyPixel_16, unsigned char> Image8Grey_16;
	typedef Image<GreyPixel_32, unsigned char> Image8Grey_32;
	typedef Image<GreyPixel_8, unsigned short> Image16Grey_8;
	typedef Image<GreyPixel_16, unsigned short> Image16Grey_16;
	typedef Image<GreyPixel_32, unsigned short> Image16Grey_32;

}

#endif // COMMON_H
