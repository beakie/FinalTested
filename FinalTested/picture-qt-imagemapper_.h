#ifndef PICTUREQTIMAGEMAPPER_H
#define PICTUREQTIMAGEMAPPER_H

#include "common-image.h"
#include "picture.h"
#include <QImage>
#include <QPixmap>
#include <QRgb>

namespace Picture
{
	namespace Qt
	{
		template <typename TINDEX>
		Common::Image<Picture::RgbPixel8, TINDEX> getRgbPixel8Image(QImage qimage)
		{
			int width = qimage.width();
			TINDEX height = qimage.height();

			Common::Image<Picture::RgbPixel8, TINDEX> image = Common::Image<Picture::RgbPixel8, TINDEX>(width, height);

			for (TINDEX x = 0; x < width; x++)
				for (TINDEX y = 0; y < height; y++)
				{
					QRgb pixel = qimage.pixel(x, y);
					image.Values[x][y] = Picture::RgbPixel8(qRed(pixel), qGreen(pixel), qBlue(pixel));
				}

			return image;
		}

		template <typename TINDEX>
		QImage getQImage(Common::Image<Picture::RgbPixel8, TINDEX> image)
		{
			QImage qimage = QImage(image.Width, image.Height, QImage::Format_RGB888);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
				{
					QRgb pixel = qRgb(image.Values[x][y].values[0], image.Values[x][y].values[1], image.Values[x][y].values[2]);
					qimage.setPixel(x, y, pixel);
				}

			return qimage;
		}

		template <typename TINDEX>
		QPixmap getQPixmap(Common::Image<Picture::RgbPixel8, TINDEX> image)
		{
			return QPixmap::fromImage(getQImage(image));
		}

	}
}

#endif // PICTUREQTIMAGEMAPPER_H
