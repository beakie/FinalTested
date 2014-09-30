#ifndef DRAWINGIMAGERENDER_H
#define DRAWINGIMAGERENDER_H

#include "core.h"
#include "common.h"

namespace Drawing
{
	static class ImageRender
	{
	public:
		typedef Common::TripleChannelPixel<UInt_8>(*PixelConverterDelegate)(const UInt_8&);

		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<Common::TripleChannelPixel<TVALUE>, TINDEX> renderImageAs3ChannelFalseImage(const Common::Image<TVALUE, TINDEX>& image, Common::TripleChannelPixel<TVALUE>(pixelConverter)(const TVALUE&))
		{
			Common::Image<Common::TripleChannelPixel<TVALUE>, TINDEX> i = Common::Image<Common::TripleChannelPixel<TVALUE>, TINDEX>(image.Width, image.Height);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					i.Values[x][y] = pixelConverter(image.Values[x][y]);

			return i;
		}

		static Common::TripleChannelPixel<UInt_8> convertPixelToTripleJet(const UInt_8& value)
		{
			return Common::TripleChannelPixel<UInt_8>(1, 1, 1);
		}

		static Common::QuadChannelPixel<UInt_8> convertPixelToQuadJet(const UInt_8& value)
		{
			return Common::QuadChannelPixel<UInt_8>(1, 1, 1, 1);
		}
	};
}

#endif // DRAWINGIMAGERENDER_H
