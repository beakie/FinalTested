
#include <QtCore/QCoreApplication>

#include "common-matrix2.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Matrix2<float> matrix = Common::Matrix2<float>();

	Common::Matrix2<float> matrix2 = Common::Matrix2<float>(matrix);

	return a.exec();
}
