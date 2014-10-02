#ifndef DRAWINGIMAGERENDER_H
#define DRAWINGIMAGERENDER_H

#include "core.h"
#include "common.h"

namespace Drawing
{
	static class ImageRender
	{
	public:
		//typedef Common::TripleChannelPixel<UInt_8>(*PixelConverterDelegate)(const UInt_8&);

		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<Common::TripleChannelPixel<TVALUE>, TINDEX> renderImageAs3ChannelImage(const Common::Image<TVALUE, TINDEX>& image, Common::TripleChannelPixel<TVALUE>(pixelConverter)(const Common::UnitInterval_32&))
		{
			Common::Image<Common::TripleChannelPixel<TVALUE>, TINDEX> i = Common::Image<Common::TripleChannelPixel<TVALUE>, TINDEX>(image.Width, image.Height);

			Float_32 lowerBound = Common::getLowerBound<TVALUE>();
			Float_32 boundsDiff = Common::getUpperBound<TVALUE>() - lowerBound;

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
				{
					//make this a class. have static and member functions to make job efficient. also custom upper and lower bounds would be nice.
					Common::UnitInterval_32 f = (Common::UnitInterval_32)((Float_32)(image.Values[x][y] - lowerBound)) / boundsDiff;

					i.Values[x][y] = pixelConverter(f);
				}

			return i;
		}

		/// <summary>
		/// ...
		/// </summary>
		static Common::TripleChannelPixel<UInt_8> convertPixelToRGBJet(const Common::UnitInterval_32& value)
		{
			//make this a class. it might need local variables to be efficent... or prepopulated with colourmap
			return Common::TripleChannelPixel<UInt_8>(1, 2, 3);
		}
	};
}

#endif // DRAWINGIMAGERENDER_H
