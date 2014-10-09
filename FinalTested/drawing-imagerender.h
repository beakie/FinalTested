#ifndef DRAWINGIMAGERENDER_H
#define DRAWINGIMAGERENDER_H

#include "core.h"
#include "common.h"
#include "drawing-trichanpixel.h"

namespace Drawing
{
	static class ImageRender
	{
	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX, typename TCONVERTER>
		static Common::Image<Drawing::TriChanPixel<TVALUE>, TINDEX> renderImageAsTriChanImage(const Common::Image<TVALUE, TINDEX>& image, TCONVERTER* converter)
		{
			Common::Image<Drawing::TriChanPixel<TVALUE>, TINDEX> i = Common::Image<Drawing::TriChanPixel<TVALUE>, TINDEX>(image.Width, image.Height);

			Float32 lowerBound = Common::getLowerBound<TVALUE>();
			Float32 boundsDiff = Common::getUpperBound<TVALUE>() - lowerBound;

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
				{
					Common::UnitInterval32 f = ((Float32)image.Values[x][y] - lowerBound) / boundsDiff;

					i.Values[x][y] = converter->convertPixel(f);
				}

			return i;
		}

	private:
		template <typename TVALUE>
		class ImageRenderHelper
		{
		public:
			Drawing::TriChanPixel<TVALUE>(*convertPixel)(const Common::UnitInterval32&);

			ImageRenderHelper(Drawing::TriChanPixel<TVALUE>(pixelConverter)(const Common::UnitInterval32&))
			{
				convertPixel = &pixelConverter;
			}
		};

	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<Drawing::TriChanPixel<TVALUE>, TINDEX> renderImageAsTriChanImage(const Common::Image<TVALUE, TINDEX>& image, Drawing::TriChanPixel<TVALUE>(pixelConverter)(const Common::UnitInterval32&))
		{
			return renderImageAsTriChanImage(image, &ImageRenderHelper<TVALUE>(pixelConverter));
		}

	};

}

#endif // DRAWINGIMAGERENDER_H
