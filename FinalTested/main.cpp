
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
	
	Common::Matrix3<float> mmm;

	Common::MatrixAdapter2F adapter;
	adapter.get(0, 0);
	adapter.inverse();
	adapter + adapter;
	//adapter.set(adapter); // how to do this???
	adapter.scalar(12);

	return a.exec();
}

// add functions to matrixadapter to add TMATRIX items where IMatrixAdapter is being passed.
// make sure adapter comments are up to date with matrix vs matrixadapter name
