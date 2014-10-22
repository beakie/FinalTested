#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QImage>
#include <iostream>

#include "core.h"
#include "common.h"
#include "picture.h"
#include "picture-qt.h"
#include "space2d.h"
#include "space3d.h"

template <>
static Picture::Rgb8 Common::getDefault<Picture::Rgb8>()
{
	return Picture::Rgb8(1, 2, 3);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	std::cout << "Starting\n";

	//Common::Image16U8 testImageb = Common::Image16U8(10, 10, 0); // Errors
	Common::Image8F32 testImage = Common::Image8F32(100, 100, 0.51);

	Picture::Image8Rgb8 testImageDisk = Picture::Qt::getArgb8Image<UInt8>(QImage("c:\\Test8.jpg"))
										.getImage<UInt8>(&Picture::getSelect1QuadChanPixelConv<UInt8>()).invert()
										.getImage<Picture::Rgb8>(&Picture::TriColorMapScaledPixelConv<Common::UnitInterval32, UInt8, UInt8>(&Picture::getRgbJetColorMap<Common::UnitInterval32>()));

	QWidget widget;
	QLabel* label = new QLabel(&widget);
	label->setPixmap(Picture::Qt::getQPixmap<UInt8>(testImageDisk));
	label->show();
	widget.show();

	std::cout << "Finished\n";

	Picture::Rgb8 rg = Picture::getGreenRgb<UInt8>();

	Common::Vector3<Common::UnitIntervalMax> ui = Picture::getGreenRgb();

	Common::UnitInterval64 ppp = 0.99;
	bool x = Common::isValidUnitInterval(ppp);
	Common::UnitInterval64 qqq = Common::trimUnitInterval(ppp);

	Common::Nullable<UInt8> kkk = 1;
	UInt8 oooi = kkk.getValueOrDefault();

	Common::Nullable<Picture::Rgb8> r111 = 1;
	Picture::Rgb8 r222 = r111;

	Common::List<Common::Nullable<int>> l = Common::List<Common::Nullable<int>>();
	l.add(2);
	l.add(Common::Nullable<int>(1));
	l.add(Common::Nullable<int>());
	l.add(Common::NullableNull());
	l.add(Common::Null);

	Common::UnitVector3 uv3 = Common::getUnitVector(Common::Vector3<UInt8>(0, 1, 86)); // wrong?!

	return a.exec();

}
