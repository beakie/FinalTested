#ifndef DRAWINGIMAGERENDER_H
#define DRAWINGIMAGERENDER_H

#include "core.h"
#include "common.h"
#include "drawing-trichannelpixel.h"

namespace Drawing
{
	static class ImageRender
	{
	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX, typename TCONVERTER>
		static Common::Image<Drawing::TriChannelPixel<TVALUE>, TINDEX> renderImageAsTriChannelImage(const Common::Image<TVALUE, TINDEX>& image, TCONVERTER* converter)
		{
			Common::Image<Drawing::TriChannelPixel<TVALUE>, TINDEX> i = Common::Image<Drawing::TriChannelPixel<TVALUE>, TINDEX>(image.Width, image.Height);

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
			Drawing::TriChannelPixel<TVALUE>(*convertPixel)(const Common::UnitInterval32&);

			ImageRenderHelper(Drawing::TriChannelPixel<TVALUE>(pixelConverter)(const Common::UnitInterval32&))
			{
				convertPixel = &pixelConverter;
			}
		};

	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<Drawing::TriChannelPixel<TVALUE>, TINDEX> renderImageAsTriChannelImage(const Common::Image<TVALUE, TINDEX>& image, Drawing::TriChannelPixel<TVALUE>(pixelConverter)(const Common::UnitInterval32&))
		{
			return renderImageAsTriChannelImage(image, &ImageRenderHelper<TVALUE>(pixelConverter));
		}

		template <typename TPIXEL, typename TUNITINTERVAL>
		class ApplyTri8ColorMap
		{
		private:
			const Drawing::TriColorMap<TUNITINTERVAL>* _colorMap;

		public:
			ApplyTri8ColorMap(const Drawing::TriColorMap<TUNITINTERVAL>* colorMap)
			{
				_colorMap = colorMap;
			}

			Drawing::TriChannelPixel<TPIXEL> convertPixel(const TUNITINTERVAL& value)
			{
				return Drawing::TriChannelPixel<TPIXEL>(value, 14, 21);
			}
		};

		typedef ApplyTri8ColorMap<UInt8, Common::UnitInterval32> ApplyTri8ColorMap32;

	};

}

#endif // DRAWINGIMAGERENDER_H
