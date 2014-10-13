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

template <typename TIMAGE>
void renderImage(const TIMAGE& image)
{
	for (int y = 0; y < image.Height; y++)
	{
		for (int x = 0; x < image.Width; x++)
			std::cout << (image.Values[x][y] ? 1 : 0);

		std::cout << "\n";
	}

	std::cout << "\n";
}

template <typename TINTERVAL, typename TFLOATING, typename TINDEX>
class ImageChannelExpandFloatConv
{
public:
	TINDEX _channel;

	ImageChannelExpandFloatConv(const TINDEX channel)
	{
		_channel = channel;
	}

	TINTERVAL convertPixel(const Picture::TriChanPixel<UInt8>& value)
	{
		return (TINTERVAL)((TFLOATING)value.Channels[_channel] / 255);
	}
};

typedef ImageChannelExpandFloatConv<Common::UnitInterval32, Float32, UInt8> Image8ChannelExpandFloatConvU8ToF32;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	// ************
	// Add RescaleConv with template specialization
	// ************
	// Add ConvertPixelChainConv (TVALUEIN, TVALUE1), (TVALUE1, TVALUE2), (TVALUE2, TVALUEOUT) -- overloads
	// ************

	//Common::Image16U8 testImageb = Common::Image16U8(10, 10, 0); // Errors
	Common::Image8F32 testImage = Common::Image8F32(100, 100, 0.51);

	Picture::TriColorMap32 map = Picture::getRGBJetColorMap<Common::UnitInterval32>();
	Picture::Image8RGBPixel8 testImageDisk = Picture::Qt::getRGBImage<UInt8>(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
																		.getImage<Float32>(&Image8ChannelExpandFloatConvU8ToF32(0))
																		.getImage<Picture::RGBPixel8>(&Picture::TriColorMap32Conv8(&map, 0.0, 0.1));

	QWidget widget;
	QLabel* label = new QLabel(&widget);
	label->setPixmap(Picture::Qt::getQPixmap<UInt8>(testImageDisk));
	label->show();
	widget.show();

	return a.exec();
}
