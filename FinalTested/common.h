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
	typedef bool Int_2;
	typedef unsigned char Int_8;
	typedef unsigned short Int_16;
	typedef unsigned int Int_32;
	typedef float Floating;

	typedef Matrix2<Int_2> Matrix2_2;
	typedef Matrix3<Int_2> Matrix3_2;
	typedef Matrix4<Int_2> Matrix4_2;
	typedef Matrix2<Int_8> Matrix2_8;
	typedef Matrix3<Int_8> Matrix3_8;
	typedef Matrix4<Int_8> Matrix4_8;
	typedef Matrix2<Int_16> Matrix2_16;
	typedef Matrix3<Int_16> Matrix3_16;
	typedef Matrix4<Int_16> Matrix4_16;
	typedef Matrix2<Int_32> Matrix2_32;
	typedef Matrix3<Int_32> Matrix3_32;
	typedef Matrix4<Int_32> Matrix4_32;
	typedef Matrix2<Floating> Matrix2_F;
	typedef Matrix3<Floating> Matrix3_F;
	typedef Matrix4<Floating> Matrix4_F;

	typedef MatrixAdapter<Matrix2_2, Int_2> Matrix2Adapter_2;
	typedef MatrixAdapter<Matrix3_2, Int_2> Matrix3Adapter_2;
	typedef MatrixAdapter<Matrix4_2, Int_2> Matrix4Adapter_2;
	typedef MatrixAdapter<Matrix2_8, Int_8> Matrix2Adapter_8;
	typedef MatrixAdapter<Matrix3_8, Int_8> Matrix3Adapter_8;
	typedef MatrixAdapter<Matrix4_8, Int_8> Matrix4Adapter_8;
	typedef MatrixAdapter<Matrix2_16, Int_16> Matrix2Adapter_16;
	typedef MatrixAdapter<Matrix3_16, Int_16> Matrix3Adapter_16;
	typedef MatrixAdapter<Matrix4_16, Int_16> Matrix4Adapter_16;
	typedef MatrixAdapter<Matrix2_32, Int_32> Matrix2Adapter_32;
	typedef MatrixAdapter<Matrix3_32, Int_32> Matrix3Adapter_32;
	typedef MatrixAdapter<Matrix4_32, Int_32> Matrix4Adapter_32;
	typedef MatrixAdapter<Matrix2_F, Floating> Matrix2Adapter_F;
	typedef MatrixAdapter<Matrix3_F, Floating> Matrix3Adapter_F;
	typedef MatrixAdapter<Matrix4_F, Floating> Matrix4Adapter_F;

	typedef RGBPixel<Int_8> RGBPixel_8;
	typedef RGBPixel<Int_16> RGBPixel_16;
	typedef RGBPixel<Int_32> RGBPixel_32;

	typedef HSVPixel<Int_8> HSVPixel_8;
	typedef HSVPixel<Int_16> HSVPixel_16;
	typedef HSVPixel<Int_32> HSVPixel_32;

	typedef Int_8 GreyPixel_8;
	typedef Int_16 GreyPixel_16;
	typedef Int_32 GreyPixel_32;

	typedef Image<Int_2, Int_8> Image8_2;
	typedef Image<Int_8, Int_8> Image8_8;
	typedef Image<Int_16, Int_8> Image8_16;
	typedef Image<Int_32, Int_8> Image8_32;
	typedef Image<Int_2, Int_16> Image16_2;
	typedef Image<Int_8, Int_16> Image16_8;
	typedef Image<Int_16, Int_16> Image16_16;
	typedef Image<Int_32, Int_16> Image16_32;

	typedef Image<RGBPixel_8, Int_8> Image8RGB_8;
	typedef Image<RGBPixel_16, Int_8> Image8RGB_16;
	typedef Image<RGBPixel_32, Int_8> Image8RGB_32;
	typedef Image<RGBPixel_8, Int_16> Image16RGB_8;
	typedef Image<RGBPixel_16, Int_16> Image16RGB_16;
	typedef Image<RGBPixel_32, Int_16> Image16RGB_32;

	typedef Image<HSVPixel_8, Int_8> Image8HSV_8;
	typedef Image<HSVPixel_16, Int_8> Image8HSV_16;
	typedef Image<HSVPixel_32, Int_8> Image8HSV_32;
	typedef Image<HSVPixel_8, Int_16> Image16HSV_8;
	typedef Image<HSVPixel_16, Int_16> Image16HSV_16;
	typedef Image<HSVPixel_32, Int_16> Image16HSV_32;

	typedef Image<GreyPixel_8, Int_8> Image8Grey_8;
	typedef Image<GreyPixel_16, Int_8> Image8Grey_16;
	typedef Image<GreyPixel_32, Int_8> Image8Grey_32;
	typedef Image<GreyPixel_8, Int_16> Image16Grey_8;
	typedef Image<GreyPixel_16, Int_16> Image16Grey_16;
	typedef Image<GreyPixel_32, Int_16> Image16Grey_32;

}

#endif // COMMON_H
