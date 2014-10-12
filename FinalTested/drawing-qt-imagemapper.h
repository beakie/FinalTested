#ifndef DRAWINGQTIMAGEMAPPER_H
#define DRAWINGQTIMAGEMAPPER_H

#include "common-image.h"
#include "drawing.h"
#include <QImage>
#include <QPixmap>
#include <QRgb>

namespace Drawing
{
	namespace Qt
	{
		template <typename TINDEX>
		class ImageMapper
		{

		public:

			static Common::Image<Drawing::RGBPixel8, TINDEX> getRGBImage(QImage qimage)
			{
				int width = qimage.width();
				TINDEX height = qimage.height();

				Common::Image<Drawing::RGBPixel8, TINDEX> image = Common::Image<Drawing::RGBPixel8, TINDEX>(width, height);

				for (TINDEX x = 0; x < width; x++)
					for (TINDEX y = 0; y < height; y++)
					{
						QRgb pixel = qimage.pixel(x, y);
						image.Values[x][y] = Drawing::RGBPixel8(qRed(pixel), qGreen(pixel), qBlue(pixel));
					}

				return image;
			}

			static QImage getQImage(Common::Image<Drawing::RGBPixel8, TINDEX> image)
			{
				QImage qimage = QImage(image.Width, image.Height, QImage::Format_RGB888);

				for (TINDEX x = 0; x < image.Width; x++)
					for (TINDEX y = 0; y < image.Height; y++)
					{
						QRgb pixel = qRgb(image.Values[x][y].Channels[0], image.Values[x][y].Channels[1], image.Values[x][y].Channels[2]);
						qimage.setPixel(x, y, pixel);
					}

				return qimage;
			}

			static QPixmap getQPixmap(Common::Image<Drawing::RGBPixel8, TINDEX> image)
			{
				return QPixmap::fromImage(getQImage(image));
			}

		};
	}
}

#endif // DRAWINGQTIMAGEMAPPER_H
