
#include <QtCore/QCoreApplication>

#include "common.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Matrix2<float> matrix = Common::Matrix2<float>(0, 1, 2, 3);
	Common::Matrix2<float> matrix2 = Common::Matrix2<float>(matrix);
	Common::Matrix2<float> matrix3 = Common::Matrix2<float>(1);
	Common::Matrix2<float> matrix4 = Common::Matrix2<float>().identity();
	matrix2.inverse(matrix);
	float d = matrix.getDeterminant();
	
	Common::MatrixAdapter2F adapter;
	adapter.allOnes();
	adapter.getMatrix().zero();
	Common::Matrix2F mmmmm = matrix / matrix4;
	Common::Matrix2F mmmmm2 = matrix * mmmmm;
	
	unsigned char rowCount = adapter.getColumnCount();

	Common::Image8B image = Common::Image8B(3, 4);
	//image.Values[0][0] = false;

	unsigned int z = Common::Image8C::getMaxValue();

	Common::Image16B img = Common::Image16B(100, 100, 1);

	img.cropImage(0, 0, 10, 10);

	//img + img << 4 >> 2;

	Common::Array<unsigned int> array;

	array.addItem(0);
	array.addItem(1);
	array.addItem(2);
	array.addItem(3);
	array.addItem(4);
	array.addItem(5);
	array.addItem(6);
	array.addItem(7);
	array.addItem(8);
	array.addItem(9);
	array.remove(4);
	array.addArray(array);
	//array++;
	//++array;

	Common::Image<Common::RGBPixel8, unsigned int> i123;

//	i123 &= i123;

	return a.exec();
}
