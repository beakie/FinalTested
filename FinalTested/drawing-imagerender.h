#ifndef DRAWINGIMAGERENDER_H
#define DRAWINGIMAGERENDER_H

#include "core.h"
#include "common.h"
#include "drawing-triplechannelpixel.h"

namespace Drawing
{
	static class ImageRender
	{
	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX, typename TCONVERTER>
		static Common::Image<Drawing::TripleChannelPixel<TVALUE>, TINDEX> renderImageAs3ChannelImage(const Common::Image<TVALUE, TINDEX>& image, TCONVERTER* converter)
		{
			Common::Image<Drawing::TripleChannelPixel<TVALUE>, TINDEX> i = Common::Image<Drawing::TripleChannelPixel<TVALUE>, TINDEX>(image.Width, image.Height);

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
			Drawing::TripleChannelPixel<TVALUE>(*convertPixel)(const Common::UnitInterval32&);

			ImageRenderHelper(Drawing::TripleChannelPixel<TVALUE>(pixelConverter)(const Common::UnitInterval32&))
			{
				convertPixel = &pixelConverter;
			}
		};

	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<Drawing::TripleChannelPixel<TVALUE>, TINDEX> renderImageAs3ChannelImage(const Common::Image<TVALUE, TINDEX>& image, Drawing::TripleChannelPixel<TVALUE>(pixelConverter)(const Common::UnitInterval32&))
		{
			return renderImageAs3ChannelImage(image, &ImageRenderHelper<TVALUE>(pixelConverter));
		}

		template <typename TPIXEL, typename TUNITINTERVAL>
		class ApplyTriple8ColorMap
		{
		private:
			const Drawing::TripleColorMap<TUNITINTERVAL>* _colorMap;

		public:
			ApplyTriple8ColorMap(const Drawing::TripleColorMap<TUNITINTERVAL>* colorMap)
			{
				_colorMap = colorMap;
			}

			Drawing::TripleChannelPixel<TPIXEL> convertPixel(const TUNITINTERVAL& value)
			{
				return Drawing::TripleChannelPixel<TPIXEL>(7, 14, 21);
			}
		};

		typedef ApplyTriple8ColorMap<UInt8, Common::UnitInterval32> ApplyTriple8ColorMap32;

	};

}

#endif // DRAWINGIMAGERENDER_H
