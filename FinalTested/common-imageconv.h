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
		static Common::Image<TVALUEOUT, TINDEX> convImageToImage(const Common::Image<TVALUEIN, TINDEX>& image, TCONVERTER* converter)
		{
			Common::Image<TVALUEOUT, TINDEX> i = Common::Image<TVALUEOUT, TINDEX>(image.Width, image.Height);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
				{
					i.Values[x][y] = converter->convertPixel(image.Values[x][y]);
				}

			return i;
		}

	private:
		template <typename TVALUE>
		class ImageRenderHelper
		{
		public:
			TVALUE(*convertPixel)(const Float32&);

			ImageRenderHelper(TVALUE(pixelConverter)(const Float32&))
			{
				convertPixel = &pixelConverter;
			}
		};

	public:
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUEIN, typename TVALUEOUT>
		static Common::Image<TVALUEOUT, TINDEX> convImageToImage(const Common::Image<TVALUEIN, TINDEX>& image, TVALUEOUT(pixelConverter)(const Float32&))
		{
			return convImageToImage<TVALUEIN, TVALUEOUT>(image, &ImageRenderHelper<TVALUEOUT>(pixelConverter));
		}

	};

}

#endif // DRAWINGIMAGERENDER_H
