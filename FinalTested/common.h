#include "common-image.h"
#include "common-imatrixadapter.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixadapter.h"
#include "common-matrixn.h"

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

	typedef MatrixAdapter<Matrix2F, bool, unsigned char> MatrixAdapter2B;
	typedef MatrixAdapter<Matrix3F, bool, unsigned char> MatrixAdapter3B;
	typedef MatrixAdapter<Matrix4F, bool, unsigned char> MatrixAdapter4B;
	typedef MatrixAdapter<Matrix2F, signed char, unsigned char> MatrixAdapter2C;
	typedef MatrixAdapter<Matrix3F, signed char, unsigned char> MatrixAdapter3C;
	typedef MatrixAdapter<Matrix4F, signed char, unsigned char> MatrixAdapter4C;
	typedef MatrixAdapter<Matrix2F, signed int, unsigned char> MatrixAdapter2I;
	typedef MatrixAdapter<Matrix3F, signed int, unsigned char> MatrixAdapter3I;
	typedef MatrixAdapter<Matrix4F, signed int, unsigned char> MatrixAdapter4I;
	typedef MatrixAdapter<Matrix2F, double, unsigned char> MatrixAdapter2D;
	typedef MatrixAdapter<Matrix3F, double, unsigned char> MatrixAdapter3D;
	typedef MatrixAdapter<Matrix4F, double, unsigned char> MatrixAdapter4D;
	typedef MatrixAdapter<Matrix2F, float, unsigned char> MatrixAdapter2F;
	typedef MatrixAdapter<Matrix3F, float, unsigned char> MatrixAdapter3F;
	typedef MatrixAdapter<Matrix4F, float, unsigned char> MatrixAdapter4F;

	bool getUpperBoundBool()
	{
		return true;
	}

	unsigned char getUpperBoundChar()
	{
		return 255;
	}

	unsigned int getUpperBoundInt()
	{
		return 65535;
	}

}
