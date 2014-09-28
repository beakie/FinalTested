
#include <QtCore/QCoreApplication>

#include "core.h"
#include "common.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Matrix2<Float> matrix = Common::Matrix2<Float>(0, 1, 2, 3);
	Common::Matrix2<Float> matrix2 = Common::Matrix2<Float>(matrix);
	Common::Matrix2<Float> matrix3 = Common::Matrix2<Float>(1);
	Common::Matrix2<Float> matrix4 = Common::Matrix2<Float>().identity();
	matrix2.inverse(matrix);
	Float d = matrix.getDeterminant();
	
	Common::Matrix2Adapter_F adapter;
	adapter.allOnes();
	adapter.getMatrix().zero();
	Common::Matrix2_F mmmmm = matrix / matrix4;
	Common::Matrix2_F mmmmm2 = matrix * mmmmm;
	
	UInt_8 rowCount = adapter.getColumnCount();

	Common::Image8_1 image = Common::Image8_1(3, 4);
	//image.Values[0][0] = false;

	UInt_8 z = Common::Image8_8::getMaxValue();

	Common::Image16_1 img = Common::Image16_1(100, 100, 1);

	img.cropImage(0, 0, 10, 10);

	Common::Array<UInt_16> array;

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

	Common::Image<Common::RGBPixel_8, UInt_16> i123;

//	i123 &= i123;

	return a.exec();
}
