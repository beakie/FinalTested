#ifndef COMMON_H
#define COMMON_H

#include "common-array.h"
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
	typedef Matrix2<bool> Matrix2B;
	typedef Matrix3<bool> Matrix3B;
	typedef Matrix4<bool> Matrix4B;
	typedef Matrix2<signed char> Matrix2C;
	typedef Matrix3<signed char> Matrix3C;
	typedef Matrix4<signed char> Matrix4C;
	typedef Matrix2<signed short> Matrix2S;
	typedef Matrix3<signed short> Matrix3S;
	typedef Matrix4<signed short> Matrix4S;
	typedef Matrix2<signed int> Matrix2I;
	typedef Matrix3<signed int> Matrix3I;
	typedef Matrix4<signed int> Matrix4I;
	typedef Matrix2<double> Matrix2D;
	typedef Matrix3<double> Matrix3D;
	typedef Matrix4<double> Matrix4D;
	typedef Matrix2<float> Matrix2F;
	typedef Matrix3<float> Matrix3F;
	typedef Matrix4<float> Matrix4F;

	typedef MatrixAdapter<Matrix2B, bool> MatrixAdapter2B;
	typedef MatrixAdapter<Matrix3B, bool> MatrixAdapter3B;
	typedef MatrixAdapter<Matrix4B, bool> MatrixAdapter4B;
	typedef MatrixAdapter<Matrix2C, signed char> MatrixAdapter2C;
	typedef MatrixAdapter<Matrix3C, signed char> MatrixAdapter3C;
	typedef MatrixAdapter<Matrix4C, signed char> MatrixAdapter4C;
	typedef MatrixAdapter<Matrix2S, signed short> MatrixAdapter2S;
	typedef MatrixAdapter<Matrix3S, signed short> MatrixAdapter3S;
	typedef MatrixAdapter<Matrix4S, signed short> MatrixAdapter4S;
	typedef MatrixAdapter<Matrix2I, signed int> MatrixAdapter2I;
	typedef MatrixAdapter<Matrix3I, signed int> MatrixAdapter3I;
	typedef MatrixAdapter<Matrix4I, signed int> MatrixAdapter4I;
	typedef MatrixAdapter<Matrix2D, double> MatrixAdapter2D;
	typedef MatrixAdapter<Matrix3D, double> MatrixAdapter3D;
	typedef MatrixAdapter<Matrix4D, double> MatrixAdapter4D;
	typedef MatrixAdapter<Matrix2F, float> MatrixAdapter2F;
	typedef MatrixAdapter<Matrix3F, float> MatrixAdapter3F;
	typedef MatrixAdapter<Matrix4F, float> MatrixAdapter4F;

	typedef Image<bool, unsigned char> Image8B;
	typedef Image<unsigned char, unsigned char> Image8C;
	typedef Image<unsigned short, unsigned char> Image8S;
	typedef Image<unsigned int, unsigned char> Image8I;
	typedef Image<bool, unsigned short> Image16B;
	typedef Image<unsigned char, unsigned short> Image16C;
	typedef Image<unsigned short, unsigned short> Image16S;
	typedef Image<unsigned int, unsigned short> Image16I;

	typedef RGBPixel<bool> RGBPixel2;
	typedef RGBPixel<unsigned char> RGBPixel8;
	typedef RGBPixel<unsigned short> RGBPixel16;
	typedef RGBPixel<unsigned int> RGBPixel32;

	typedef bool GreyPixel2;
	typedef unsigned char GreyPixel8;
	typedef unsigned short GreyPixel16;
	typedef unsigned int GreyPixel32;

	//typedef Plot<unsigned char> DimensionsC;

}

#endif // COMMON_H
