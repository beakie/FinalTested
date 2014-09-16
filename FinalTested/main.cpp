
#include <QtCore/QCoreApplication>

#include "common-matrix4.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Matrix4<float> matrix = Common::Matrix4<float>(123);

	return a.exec();
}
