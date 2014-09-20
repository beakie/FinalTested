
#include <QtCore/QCoreApplication>

#include "common.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Matrix2<float> matrix = Common::Matrix2<float>(0, 1, 2, 3);
	Common::Matrix2<float> matrix2 = Common::Matrix2<float>(matrix);
	Common::Matrix2<float> matrix3 = Common::Matrix2<float>(1);
	Common::Matrix2<float> matrix4 = Common::Matrix2<float>().identity();
	//matrix.inverse();
	matrix2.inverse(matrix);
	float d = matrix.getDeterminant();
	
	Common::Matrix2<float> mmm2;
	Common::Matrix3<float> mmm3;
	Common::Matrix4<float> mmm4;

	Common::MatrixA2F adapter;
	adapter.allOnes();
	adapter.getMatrix().zero();
	Common::Matrix2F mmmmm = matrix / matrix4;
	Common::Matrix2F mmmmm2 = matrix * mmmmm;
	
	unsigned char rowCount = adapter.getColumnCount();

	Common::Image<bool, char> image = Common::Image<bool, char>(3, 4, false);
	image.Values[0][0] = false;

	return a.exec();
}
