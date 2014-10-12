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
void renderImage(const TIMAGE& image);

template <typename TUNITINTERVAL>
class GreyPixelFloatConv
{
public:
	Picture::TriChanPixel<UInt8> convertPixel(const TUNITINTERVAL& value)
	{
		return Picture::TriChanPixel<UInt8>(value * 255, value * 255, value * 255);
	}
};

template <typename TVALUE, typename TINDEX>
class ImageChannelConv
{
public:
	TINDEX _channel;

	ImageChannelConv(const TINDEX channel)
	{
		_channel = channel;
	}

	TVALUE convertPixel(const Picture::TriChanPixel<TVALUE>& value)
	{
		return value.Channels[_channel];
	}
};

typedef ImageChannelConv<UInt8, UInt8> Image8ChannelConv8;

template <typename TVALUE, typename TINDEX>
class ImageChannelExpandConv
{
public:
	TINDEX _channel;

	ImageChannelExpandConv(const TINDEX channel)
	{
		_channel = channel;
	}

	Picture::TriChanPixel<TVALUE> convertPixel(const Picture::TriChanPixel<TVALUE>& value)
	{
		TVALUE v = value.Channels[_channel];
		return Picture::TriChanPixel<TVALUE>(v, v, v);
	}
};

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

typedef ImageChannelExpandConv<UInt8, UInt8> Image8ChannelExpandConv8;

typedef ImageChannelExpandFloatConv<Common::UnitInterval32, Float32, UInt8> Image8ChannelExpandFloatConvU8ToF32;

static Picture::TriChanPixel<UInt8> staticConvertPixel(const Float32& value)
{
	return Picture::TriChanPixel<UInt8>(0, 0, 0);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//Common::Image16U8 testImageb = Common::Image16U8(10, 10, 0); // Errors
	Common::Image8F32 testImage = Common::Image8F32(100, 100, 0.51);

	Picture::TriColorMap32 map = Picture::ColorMaps32::getRGBJet();

	//Picture::Image8RGBPixel8 testImageDisk = Picture::Qt::ImageMapper8::getImage(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
	//																	.getImage<UInt8>(&Image8ChannelConv8(0))
	//																	.getImage<Picture::TriChanPixel<UInt8>>(&GreyPixelConv());
	//Picture::Image8RGBPixel8 testImageDisk = Picture::Qt::ImageMapper8::getImage(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
	//																	.getImage<Picture::RGBPixel8>(&Image8ChannelExpandConv8(0));
	//Picture::Image8RGBPixel8 testImageDisk = Picture::Qt::ImageMapper8::getRGBImage(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
	//																	.getImage<Float32>(&Image8ChannelExpandFloatConvU8ToF32(0))
	//																	.getImage<Picture::TriChanPixel<UInt8>>(&Picture::TriColorMap32Conv8(&map, 0.0, 0.1));
	//Picture::Image8RGBPixel8 testImageDisk = Picture::Qt::ImageMapper8::getRGBImage(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
	//															.getImage<UInt8>(&Picture::getSelect0TriChanPixelConv<UInt8, UInt8>())
	//															.getImage<Picture::RGBPixel8>(&Picture::SpreadValueTriChanPixelConv<UInt8, UInt8>());
	Picture::Image8RGBPixel8 testImageDisk = Picture::Qt::ImageMapper8::getRGBImage(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
																.getImage<Picture::RGBPixel8>(&Picture::getSpread0TriChanPixelConv<UInt8, UInt8>());

	//**********
	// getChannel1() fromIntensity()
	// this should prob be new toImage() func passing different function pointers
	//**********

	QWidget widget;

	QLabel* label = new QLabel(&widget);
	label->setPixmap(Picture::Qt::ImageMapper8::getQPixmap(testImageDisk));
	label->show();
	
	widget.show();

	// 137, 255, 117
	return a.exec();
}

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

// http://qt-project.org/forums/viewthread/30871
