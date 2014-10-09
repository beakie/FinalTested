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
		static Common::Image<Drawing::TriChanPixel<TVALUEOUT>, TINDEX> renderImageAsTriChanImage(const Common::Image<TVALUEIN, TINDEX>& image, TVALUEIN lowerBound, TVALUEIN upperBound, TCONVERTER* converter)
		{
			Common::Image<Drawing::TriChanPixel<TVALUEOUT>, TINDEX> i = Common::Image<Drawing::TriChanPixel<TVALUEOUT>, TINDEX>(image.Width, image.Height);

			Float32 boundsDiff = upperBound - lowerBound;

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
		template <typename TVALUEIN, typename TVALUEOUT>
		static Common::Image<Drawing::TriChanPixel<TVALUEOUT>, TINDEX> renderImageAsTriChanImage(const Common::Image<TVALUEIN, TINDEX>& image, TVALUEIN lowerBound, TVALUEIN upperBound, Drawing::TriChanPixel<TVALUEOUT>(pixelConverter)(const Common::UnitInterval32&))
		{
			return renderImageAsTriChanImage<TVALUEIN, TVALUEOUT>(image, lowerBound, upperBound, &ImageRenderHelper<TVALUEOUT>(pixelConverter));
		}

	};

}

#endif // DRAWINGIMAGERENDER_H
