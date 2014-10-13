#include <QApplication>
#include <QImage>
#include <QPixmap>
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <iostream>

#include "core.h"
#include "common.h"
#include "picture.h"
#include "picture-qt.h"

template <typename TIN, typename TCHAIN1, typename TCHAIN2, typename TOUT>
class ChainPixelConv //could this be done with mixin?
{
private:
	TCHAIN1(*convertPixel1)(const TIN&);
	TCHAIN2(*convertPixel2)(const TCHAIN1&);
	TOUT(*convertPixel3)(const TCHAIN2&);
public:
	TOUT convertPixel(const TIN& pixel)
	{
		return convertPixel3(convertPixel2(convertPixel1(pixel)));
	}
};

template <typename TIN, typename TOUT>
class CastPixelConv
{
public:
	TOUT convertPixel(const TIN& pixel)
	{
		return (TOUT)pixel;
	}
};

template <typename TIN, typename TOUT>
class ScalePixelConv
{
private:
	//Common::FloatMax offset;
	//Common::FloatMax scale;
public:
	ScalePixelConv()
	{
		Common::FloatMax inLower = Common::getLowerBound<TIN>(); //0
		Common::FloatMax inUpper = Common::getUpperBound<TIN>(); //255
		Common::FloatMax outLower = Common::getLowerBound<TOUT>(); //-32767
		Common::FloatMax outUpper = Common::getUpperBound<TOUT>();//32767
	}

	TOUT convertPixel(const TIN& pixel)
	{
		return (TOUT)pixel;
	}
};

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// Add ConvertPixelChainConv (TVALUEIN, TVALUE1), (TVALUE1, TVALUE2), (TVALUE2, TVALUEOUT) -- overloads

	//Common::Image16U8 testImageb = Common::Image16U8(10, 10, 0); // Errors
	Common::Image8F32 testImage = Common::Image8F32(100, 100, 0.51);

	Picture::TriColorMap32 map = Picture::getRGBJetColorMap<Common::UnitInterval32>();
	Picture::Image8RGBPixel8 testImageDisk = Picture::Qt::getRGBImage<UInt8>(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
														 .getImage<UInt8>(&Picture::getSelect0TriChanPixelConv<UInt8>())
														 .getImage<Float32>(&ScalePixelConv<UInt8, Float32>())
														 .getImage<Picture::RGBPixel8>(&Picture::TriColorMap32Conv8(&map, 0.0, 0.1));

	QWidget widget;
	QLabel* label = new QLabel(&widget);
	label->setPixmap(Picture::Qt::getQPixmap<UInt8>(testImageDisk));
	label->show();
	widget.show();

	return a.exec();
}
