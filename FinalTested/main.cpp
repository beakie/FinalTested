
#include <QApplication>
#include <QImage>
#include <QPixmap>
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <iostream>

#include "core.h"
#include "common.h"
#include "drawing.h"
#include "drawing-qt.h"

template <typename TIMAGE>
void renderImage(const TIMAGE& image);

struct GreyPixelConv
{
	Drawing::TriChanPixel<UInt8> convertPixel(const Float32& value)
	{
		return Drawing::TriChanPixel<UInt8>(value * 255, value * 255, value * 255);
	}
};

template <typename TVALUE, typename TINDEX>
struct ImageChannelConv
{
	TINDEX _channel;

	ImageChannelConv(const TINDEX channel)
	{
		_channel = channel;
	}

	TVALUE convertPixel(const Drawing::TriChanPixel<TVALUE>& value)
	{
		return value.Channels[_channel];
	}
};

typedef ImageChannelConv<UInt8, UInt8> Image8ChannelConv8;

template <typename TVALUE, typename TINDEX>
struct ImageChannelExpandConv
{
	TINDEX _channel;

	ImageChannelExpandConv(const TINDEX channel)
	{
		_channel = channel;
	}

	Drawing::TriChanPixel<TVALUE> convertPixel(const Drawing::TriChanPixel<TVALUE>& value)
	{
		TVALUE v = value.Channels[_channel];
		return Drawing::TriChanPixel<TVALUE>(v, v, v);
	}
};

template <typename TINTERVAL, typename TFLOATING, typename TINDEX>
struct ImageChannelExpandFloatConv
{
	TINDEX _channel;

	ImageChannelExpandFloatConv(const TINDEX channel)
	{
		_channel = channel;
	}

	TINTERVAL convertPixel(const Drawing::TriChanPixel<UInt8>& value)
	{
		return (TINTERVAL)((TFLOATING)value.Channels[_channel] / 255);
	}
};

typedef ImageChannelExpandConv<UInt8, UInt8> Image8ChannelExpandConv8;

typedef ImageChannelExpandFloatConv<Common::UnitInterval32, Float32, UInt8> Image8ChannelExpandFloatConvU8ToF32;

static Drawing::TriChanPixel<UInt8> staticConvertPixel(const Float32& value)
{
	return Drawing::TriChanPixel<UInt8>(0, 0, 0);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Common::Image8U1 image = Common::Image8U1(10, 10, false);

	image.Values[0][0] = image.Values[0][7] = image.Values[8][1] = image.Values[8][2] = image.Values[8][9] = true;

	renderImage(image);
	
	image.cropImage(0, 1, 8, 8);

	image.rotate90();

	renderImage(image);

	///////////////////

	//Common::Image16U8 testImageb = Common::Image16U8(10, 10, 0); // Errors
	Common::Image8F32 testImage = Common::Image8F32(100, 100, 0.51);

	//Drawing::Image8RGBPixel8 rgbImageMEMBER = Drawing::ImageRender::renderImageAsTriChanImage(testImage, &SomePixelConverter());
	//Drawing::Image8RGBPixel8 rgbImageSTATIC = Drawing::ImageRender::renderImageAsTriChanImage(testImage, &staticConvertPixel);
	Drawing::TriColorMap32 map = Drawing::ColorMaps32::getRGBJet();

	Drawing::Image8RGBPixel8 testImageJet = testImage.getImage<Drawing::TriChanPixel<UInt8>>(&Drawing::TriColorMap32Conv8(&map, 0.0, 1.0));
	Drawing::Image8RGBPixel8 testImageJetHalf = testImage.getImage<Drawing::TriChanPixel<UInt8>>(&Drawing::TriColorMap32Conv8(&map, 0.0, 2.0));
	Drawing::Image8RGBPixel8 testImageJetFull = testImage.getImage<Drawing::TriChanPixel<UInt8>>(&Drawing::TriColorMap32Conv8(&map));
	Drawing::Image8RGBPixel8 testImageGrey = testImage.getImage<Drawing::TriChanPixel<UInt8>>(&GreyPixelConv());
	Drawing::Image8RGBPixel8 testImageBlack = testImage.getImage<Drawing::TriChanPixel<UInt8>>(&staticConvertPixel);
	//Drawing::Image8RGBPixel8 testImageDisk = Drawing::Qt::ImageMapper8::getImage(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
	//																	.getImage<UInt8>(&Image8ChannelConv8(0))
	//																	.getImage<Drawing::TriChanPixel<UInt8>>(&GreyPixelConv());
	//Drawing::Image8RGBPixel8 testImageDisk = Drawing::Qt::ImageMapper8::getImage(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
	//																	.getImage<Drawing::RGBPixel8>(&Image8ChannelExpandConv8(0));
	Drawing::Image8RGBPixel8 testImageDisk = Drawing::Qt::ImageMapper8::getImage(QImage("D:\\Win7Users\\Beakie\\Desktop\\Test8.jpg"))
																		.getImage<Float32>(&Image8ChannelExpandFloatConvU8ToF32(0))
																		.getImage<Drawing::TriChanPixel<UInt8>>(&Drawing::TriColorMap32Conv8(&map, 0.0, 0.1));

	//**********
	// Need to do some mutli channel to single channel image converters so that i can test all image functions.
	// getChannel1() fromIntensity()
	// this should prob be new toImage() func passing different function pointers
	//**********

	QWidget widget;

	QLabel* label = new QLabel(&widget);
	label->setPixmap(Drawing::Qt::ImageMapper8::getQPixmap(testImageDisk));
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
