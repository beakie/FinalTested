
#include <QtCore/QCoreApplication>
#include <iostream>

#include "core.h"
#include "common.h"

void renderImage(const Common::Image8_1& image);

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

	image.flipHorizontally().flipVertically().cropImage(1, 1, 8, 8);

	renderImage(image);

	return a.exec();
}

void renderImage(const Common::Image8_1& image)
{
	for (int y = 0; y < image.Height; y++)
	{
		for (int x = 0; x < image.Width; x++)
			std::cout << (image.Values[x][y] ? 1 : 0);

		std::cout << "\n";
	}
	std::cout << "\n";
}
