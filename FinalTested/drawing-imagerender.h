#ifndef DRAWINGIMAGERENDER_H
#define DRAWINGIMAGERENDER_H

#include "core.h"
#include "common.h"
#include "drawing-trichanpixel.h"

namespace Drawing
{
	template <typename typename TINDEX>
	class ImageRender
	{
	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUEIN, typename TVALUEOUT, typename TCONVERTER>
		static Common::Image<TVALUEOUT, TINDEX> convImageToTriChanImage(const Common::Image<TVALUEIN, TINDEX>& image, TCONVERTER* converter)
		{
			Common::Image<TVALUEOUT, TINDEX> i = Common::Image<TVALUEOUT, TINDEX>(image.Width, image.Height);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
				{
					Common::UnitInterval32 f = (Float32)image.Values[x][y];

					i.Values[x][y] = converter->convertPixel(f);
				}

			return i;
		}

	private:
		template <typename TVALUE>
		class ImageRenderHelper
		{
		public:
			Drawing::TVALUE(*convertPixel)(const Common::UnitInterval32&);

			ImageRenderHelper(TVALUE(pixelConverter)(const Common::UnitInterval32&))
			{
				convertPixel = &pixelConverter;
			}
		};

	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUEIN, typename TVALUEOUT>
		static Common::Image<TVALUEOUT, TINDEX> convImageToTriChanImage(const Common::Image<TVALUEIN, TINDEX>& image, TVALUEOUT(pixelConverter)(const Common::UnitInterval32&))
		{
			return renderImageAsTriChanImage<TVALUEIN, TVALUEOUT>(image, &ImageRenderHelper<TVALUEOUT>(pixelConverter));
		}

	};

}

#endif // DRAWINGIMAGERENDER_H
