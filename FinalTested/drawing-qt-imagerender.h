#ifndef DRAWINGQTIMAGERENDER_H
#define DRAWINGQTIMAGERENDER_H

#include "common-image.h"
#include "drawing.h"
#include <QImage>
#include <QPixmap>
#include <QRgb>

namespace Drawing
{
	namespace Qt
	{
		class ImageRender
		{

			QImage _qimage;

		public:

			ImageRender(const char* path)
			{
				_qimage = QImage(path);
			}

			ImageRender(Common::Image<Drawing::RGBPixel8, UInt8>& image)
			{
				_qimage = QImage(image.Width, image.Height, QImage::Format_RGB888);

				for (UInt8 x = 0; x < image.Width; x++)
					for (UInt8 y = 0; y < image.Height; y++)
					{
						QRgb pixel = qRgb(image.Values[x][y].Channels[0], image.Values[x][y].Channels[1], image.Values[x][y].Channels[2]);
						_qimage.setPixel(x, y, pixel);
					}
			}

			Common::Image<Drawing::RGBPixel8, UInt8> getImage()
			{
				Common::Image<Drawing::RGBPixel8, UInt8> image;

				for (UInt8 x = 0; x < _qimage.width(); x++)
					for (UInt8 y = 0; y < _qimage.height(); y++)
					{
						QRgb pixel = _qimage.pixel(x, y);
						image.Values[x][y] = Drawing::RGBPixel8(qRed(pixel), qGreen(pixel), qBlue(pixel));
					}

				return image;
			}

			QPixmap getQPixmap()
			{
				return QPixmap::fromImage(_qimage);
			}

		};
	}
}

#endif // DRAWINGQTIMAGERENDER_H
