#ifndef COMMON_H
#define COMMON_H

#include "common-image.h"
#include "common-imagefilter.h"
#include "common-imatrixadapter.h"
#include "common-invertimagefilter.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixadapter.h"
#include "common-matrixn.h"
#include "common-static.h"

namespace Common
{

	typedef Matrix2<bool> Matrix2B;
	typedef Matrix3<bool> Matrix3B;
	typedef Matrix4<bool> Matrix4B;
	typedef Matrix2<signed char> Matrix2C;
	typedef Matrix3<signed char> Matrix3C;
	typedef Matrix4<signed char> Matrix4C;
	typedef Matrix2<signed int> Matrix2I;
	typedef Matrix3<signed int> Matrix3I;
	typedef Matrix4<signed int> Matrix4I;
	typedef Matrix2<double> Matrix2D;
	typedef Matrix3<double> Matrix3D;
	typedef Matrix4<double> Matrix4D;
	typedef Matrix2<float> Matrix2F;
	typedef Matrix3<float> Matrix3F;
	typedef Matrix4<float> Matrix4F;

	typedef MatrixAdapter<Matrix2F, bool> MatrixAdapter2B;
	typedef MatrixAdapter<Matrix3F, bool> MatrixAdapter3B;
	typedef MatrixAdapter<Matrix4F, bool> MatrixAdapter4B;
	typedef MatrixAdapter<Matrix2F, signed char> MatrixAdapter2C;
	typedef MatrixAdapter<Matrix3F, signed char> MatrixAdapter3C;
	typedef MatrixAdapter<Matrix4F, signed char> MatrixAdapter4C;
	typedef MatrixAdapter<Matrix2F, signed int> MatrixAdapter2I;
	typedef MatrixAdapter<Matrix3F, signed int> MatrixAdapter3I;
	typedef MatrixAdapter<Matrix4F, signed int> MatrixAdapter4I;
	typedef MatrixAdapter<Matrix2F, double> MatrixAdapter2D;
	typedef MatrixAdapter<Matrix3F, double> MatrixAdapter3D;
	typedef MatrixAdapter<Matrix4F, double> MatrixAdapter4D;
	typedef MatrixAdapter<Matrix2F, float> MatrixAdapter2F;
	typedef MatrixAdapter<Matrix3F, float> MatrixAdapter3F;
	typedef MatrixAdapter<Matrix4F, float> MatrixAdapter4F;

	typedef Image<bool, unsigned char> Image8B;
	typedef Image<unsigned char, unsigned char> Image8C;
	typedef Image<unsigned int, unsigned char> Image8I;
	typedef Image<bool, unsigned int> Image16B;
	typedef Image<unsigned char, unsigned int> Image16C;
	typedef Image<unsigned int, unsigned int> Image16I;

}

#endif // COMMON_H
