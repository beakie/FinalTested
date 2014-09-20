
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
	
	Common::Matrix2F mmm2;
	Common::Matrix3F mmm3;
	Common::Matrix4F mmm4;

	Common::MatrixAdapter2F adapter;
	adapter.allOnes();
	adapter.getMatrix().zero();
	Common::Matrix2F mmmmm = matrix / matrix4;
	Common::Matrix2F mmmmm2 = matrix * mmmmm;
	
	unsigned char rowCount = adapter.getColumnCount();

	Common::Image8B image = Common::Image8B(3, 4);
	//image.Values[0][0] = false;

	unsigned int z = Common::Image8C::getMaxValue();

	Common::ImageFilter8B::updateValues(image, Common::NegativeImageFilterB::updateValue);

	Common::ImageFilter8B::applyMatrix(image, matrix);

	Common::ImageFilter8B::applyFilter<Common::NegativeImageFilterB>(image);

	Common::ImageFilter8B::applyFilter(image, Common::NegativeImageFilterB());

	return a.exec();
}
