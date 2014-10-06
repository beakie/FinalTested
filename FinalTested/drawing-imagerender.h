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
		static Common::Image<Drawing::TripleChannelPixel<TVALUE>, TINDEX> renderImageAs3ChannelImage(const Common::Image<TVALUE, TINDEX>& image, TCONVERTER converter)
		{
			Common::Image<Drawing::TripleChannelPixel<TVALUE>, TINDEX> i = Common::Image<Drawing::TripleChannelPixel<TVALUE>, TINDEX>(image.Width, image.Height);

			Float_32 lowerBound = Common::getLowerBound<TVALUE>();
			Float_32 boundsDiff = Common::getUpperBound<TVALUE>() - lowerBound;

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
				{
					//make this a class. have static and member functions to make job efficient. also custom upper and lower bounds would be nice.
					Common::UnitInterval_32 f = ((Float_32)image.Values[x][y] - lowerBound) / boundsDiff;

					i.Values[x][y] = converter->convertPixel(f);
				}

			return i;
		}

	};
}

#endif // DRAWINGIMAGERENDER_H
