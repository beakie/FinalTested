#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <iostream>
#include "core.h"
#include "common.h"
#include "picture.h"
#include "picture-qt.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//Common::Image16U8 testImageb = Common::Image16U8(10, 10, 0); // Errors
	Common::Image8F32 testImage = Common::Image8F32(100, 100, 0.51);

	Picture::Image8Rgb8 testImageDisk = Picture::Qt::getRgb8Image<UInt8>(QImage("c:\\Test8.jpg"))
															.getImage<UInt8>(&Picture::getSelect0TriChanPixelConv<UInt8>()).invert()
															.getImage<Picture::Rgb8>(&Picture::TriColorMapPixelConv<Common::UnitInterval32, UInt8, UInt8>(&Picture::getRgbHotColorMap<Common::UnitInterval32>()));

	QWidget widget;
	QLabel* label = new QLabel(&widget);
	label->setPixmap(Picture::Qt::getQPixmap<UInt8>(testImageDisk));
	label->show();
	widget.show();

	std::cout << "Finished\n";

	Picture::Rgb8 rg = Picture::getGreenRgb<UInt8>();

	Common::Vector3<Common::UnitIntervalMax> ui = Picture::getGreenRgb();

	return a.exec();

}
