
#include <QtCore/QCoreApplication>
#include <iostream>

#include "core.h"
#include "common.h"
#include "drawing.h"

template <typename TIMAGE>
void renderImage(const TIMAGE& image);

struct SomePixelConverter
{
	Drawing::TripleChannelPixel<UInt8> convertPixel(const Common::UnitInterval32& value)
	{
		return Drawing::TripleChannelPixel<UInt8>(1, 2, 3);
	}
};

static Drawing::TripleChannelPixel<UInt8> staticConvertPixel(const Common::UnitInterval32& value)
{
	return Drawing::TripleChannelPixel<UInt8>(1, 2, 3);
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Image8U1 image = Common::Image8U1(10, 10, false);

	image.Values[0][0] = true;
	image.Values[0][7] = true;
	image.Values[8][1] = true;
	image.Values[8][2] = true;
	image.Values[8][9] = true;

	renderImage(image);
	
	//image.cropImage(0, 1, 8, 8);

	image.rotate90();

	renderImage(image);

	///////////////////

	//Common::Image8U8 testImage = Common::Image8U8(10, 10, 0); // Errors
	Common::Image8U8 testImage = Common::Image8U8(10, 10, 1);

	Drawing::Image8RGBPixel8 rgbImageMEMBER = Drawing::ImageRender::renderImageAs3ChannelImage(testImage, &SomePixelConverter());
	Drawing::Image8RGBPixel8 rgbImageSTATIC = Drawing::ImageRender::renderImageAs3ChannelImage(testImage, &staticConvertPixel);
	Drawing::Image8RGBPixel8 rgbImageJET = Drawing::ImageRender::renderImageAs3ChannelImage(testImage, &Drawing::ImageRender::ApplyTriple8ColorMap32(&Drawing::ColorMapBuilders32::getRGBColorMapJet()));

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
