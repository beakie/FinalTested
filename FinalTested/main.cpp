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

	Picture::Image8RgbPixel8 testImageDisk = Picture::Qt::getRgbPixel8Image<UInt8>(QImage("c:\\Test8.jpg"))
															.getImage<UInt8>(&Picture::getSelect0TriChanPixelConv<UInt8>()).invert()
															.getImage<Picture::RgbPixel8>(&Picture::TriColorMapPixelConv<Common::UnitInterval32, UInt8, UInt8>(&Picture::getRgbHotColorMap<Common::UnitInterval32>()));

	QWidget widget;
	QLabel* label = new QLabel(&widget);
	label->setPixmap(Picture::Qt::getQPixmap<UInt8>(testImageDisk));
	label->show();
	widget.show();

	std::cout << "Finished\n";

	Common::Vector3<UInt8> red = Picture::getRedRgb<UInt8>();

	return a.exec();

}
