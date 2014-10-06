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

			Float_32 lowerBound = Common::getLowerBound<TVALUE>();
			Float_32 boundsDiff = Common::getUpperBound<TVALUE>() - lowerBound;

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
				{
					Common::UnitInterval_32 f = ((Float_32)image.Values[x][y] - lowerBound) / boundsDiff;

					i.Values[x][y] = converter->convertPixel(f);
				}

			return i;
		}

	private:
		template <typename TVALUE>
		class ImageRenderHelper
		{
		public:
			Drawing::TripleChannelPixel<TVALUE>(*convertPixel)(const Common::UnitInterval_32&);

			ImageRenderHelper(Drawing::TripleChannelPixel<TVALUE>(pixelConverter)(const Common::UnitInterval_32&))
			{
				convertPixel = &pixelConverter;
			}
		};

	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<Drawing::TripleChannelPixel<TVALUE>, TINDEX> renderImageAs3ChannelImage(const Common::Image<TVALUE, TINDEX>& image, Drawing::TripleChannelPixel<TVALUE>(pixelConverter)(const Common::UnitInterval_32&))
		{
			return renderImageAs3ChannelImage(image, &ImageRenderHelper<TVALUE>(pixelConverter));
		}

		class ApplyColorMap
		{
		private:
			const Drawing::TripleChannelColorMap<UInt_8, Float_32>* _colorMap;

		public:
			ApplyColorMap(const Drawing::TripleChannelColorMap<UInt_8, Float_32>* colorMap)
			{
				_colorMap = colorMap;
			}

			Drawing::TripleChannelPixel<UInt_8> convertPixel(const Common::UnitInterval_32& value)
			{
				return Drawing::TripleChannelPixel<UInt_8>(7, 14, 21);
			}
		};

	};

}

#endif // DRAWINGIMAGERENDER_H
