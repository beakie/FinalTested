#include "common-imatrixadapter.h"
#include "common-matrix2.h"
#include "common-matrix3.h"
#include "common-matrix4.h"
#include "common-matrixadapter.h"

namespace Common
{

	typedef Matrix2<float> Matrix2F;
	typedef Matrix3<float> Matrix3F;
	typedef Matrix4<float> Matrix4F;

	typedef MatrixAdapter<Matrix2F, float, unsigned char> MatrixAdapter2F;
	typedef MatrixAdapter<Matrix3F, float, unsigned char> MatrixAdapter3F;
	typedef MatrixAdapter<Matrix4F, float, unsigned char> MatrixAdapter4F;

}
