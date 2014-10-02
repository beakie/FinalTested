
#include <QtCore/QCoreApplication>
#include <iostream>

#include "core.h"
#include "common.h"
#include "drawing.h"

template <typename TIMAGE>
void renderImage(const TIMAGE& image);

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Image8_1 image = Common::Image8_1(10, 10, false);

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

	//Common::Image8_8 testImage = Common::Image8_8(10, 10, 0); // Errors
	Common::Image8_8 testImage = Common::Image8_8(10, 10, 1);

	Drawing::Image8RGBPixel_8 rgbImage = Drawing::Image8RGBPixel_8(0, 0);
	rgbImage = Drawing::ImageRender::renderImageAs3ChannelImage(testImage, &Drawing::ImageRender::convertPixelToRGBJet);

	///////////////////


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
