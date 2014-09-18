
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

	Common::MatrixF8 adapter;
	adapter.get(0, 0);
	adapter.inverse();
	adapter + adapter;
	adapter.set(adapter);

	return a.exec();
}
