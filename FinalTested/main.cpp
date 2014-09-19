
#include <QtCore/QCoreApplication>

#include "common.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Matrix2<float> matrix = Common::Matrix2<float>(0, 1, 2, 3);
	Common::Matrix2<float> matrix2 = Common::Matrix2<float>(matrix);
	Common::Matrix2<float> matrix3 = Common::Matrix2<float>(1);
	matrix.inverse();
	matrix2.inverse(matrix);
	float d = matrix.getDeterminant();
	
	Common::Matrix2<float> mmm2;
	Common::Matrix3<float> mmm3;
	Common::Matrix4<float> mmm4;

	Common::MatrixA2F adapter;
	adapter.get(0, 0);
	adapter.inverse().inverse();
	adapter + adapter;
	adapter.set(adapter);
	adapter.set(adapter.Matrix);
	adapter.scalar(12);

	return a.exec();
}

// add functions to matrixadapter to add TMATRIX items where IMatrixAdapter is being passed.
// make sure adapter comments are up to date with matrix vs matrixadapter name
