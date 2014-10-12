#ifndef DRAWINGCHANIMAGES_H
#define DRAWINGCHANIMAGES_H

#include "common-image.h"
#include "drawing-trichanpixel.h"
#include "drawing-quadchanpixel.h"

namespace Drawing
{
	//THESE SHOULD ALL BE REPLACED WITH CONVERTPIXEL FUNCTION CLASSES.
	static class ChanImages
	{
	public:
		template <typename TCHANPIXEL, typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChan(const Common::Image<TCHANPIXEL, TINDEX>& image, const UInt8 chanIndex)
		{
			Common::Image<TVALUE, TINDEX> i = Common::Image<TVALUE, TINDEX>(image.Width, image.Height);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					i.Values[x][y] = image.Values[x][y].Channels[chanIndex];

			return i;
		}

		template <typename TCHANPIXEL, typename TVALUE, typename TINDEX>
		static void setImageChan(const Common::Image<TCHANPIXEL, TINDEX>& image, const TINDEX chanIndex, const Common::Image<TVALUE, TINDEX>& chanImage)
		{
			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					image.Values[x][y].Channels[chanIndex] = chanImage.Values[x][y];
		}

		template <typename TCHANPIXEL, typename TVALUE, typename TINDEX>
		static void setImageChanAll(const Common::Image<TCHANPIXEL, TINDEX>& image, const Common::Image<TVALUE, TINDEX>& chanImage)
		{
			TVALUE value;
			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
				{
				value = chanImage.Values[x][y];
				image.Values[x][y].Channels[0] = value;
				image.Values[x][y].Channels[1] = value;
				image.Values[x][y].Channels[2] = value;
				}
		}

		template <typename TVALUE, typename TINDEX>
		static Common::Image<Drawing::TriChanPixel<TVALUE>, TINDEX> getTriImageChanExpanded(const Common::Image<TVALUE, TINDEX>& chanImage)
		{
			Common::Image<Drawing::TriChanPixel<TVALUE>, TINDEX> image = Common::Image<Drawing::TriChanPixel<TVALUE>, TINDEX>(chanImage.Width, chanImage.Height);

			TVALUE value;
			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					image.Values[x][y] = chanImage.Values[x][y];

			return image;
		}

		template <typename TVALUE, typename TINDEX>
		static Common::Image<Drawing::QuadChanPixel<TVALUE>, TINDEX> getQuadImageChanExpanded(const Common::Image<TVALUE, TINDEX>& chanImage)
		{
			Common::Image<Drawing::QuadChanPixel<TVALUE>, TINDEX> image = Common::Image<Drawing::QuadChanPixel<TVALUE>, TINDEX>(chanImage.Width, chanImage.Height);

			TVALUE value;
			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					image.Values[x][y] = chanImage.Values[x][y];

			return image;
		}

		/// <summary>
		/// Returns the first chan from a 3 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChan1(const Common::Image<TriChanPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChan<TriChanPixel<TVALUE>, TVALUE, TINDEX>(image, 0);
		}

		/// <summary>
		/// Returns the second chan from a 3 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChan2(const Common::Image<TriChanPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChan<TriChanPixel<TVALUE>, TVALUE, TINDEX>(image, 1);
		}

		/// <summary>
		/// Returns the third chan from a 3 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChan3(const Common::Image<TriChanPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChan<TriChanPixel<TVALUE>, TVALUE, TINDEX>(image, 2);
		}

		/// <summary>
		/// Returns the first chan from a 4 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChan1(const Common::Image<QuadChanPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChan<QuadChanPixel<TVALUE>, TVALUE, TINDEX>(image, 0);
		}

		/// <summary>
		/// Returns the second chan from a 4 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChan2(const Common::Image<QuadChanPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChan<QuadChanPixel<TVALUE>, TVALUE, TINDEX>(image, 1);
		}

		/// <summary>
		/// Returns the third chan from a 4 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChan3(const Common::Image<QuadChanPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChan<QuadChanPixel<TVALUE>, TVALUE, TINDEX>(image, 2);
		}

		/// <summary>
		/// Returns the fourth chan from a 4 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChan4(const Common::Image<QuadChanPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChan<QuadChanPixel<TVALUE> TINDEX>, TVALUE, TINDEX>(image, 3);
		}

		/// <summary>
		/// Sets the first chan of a 3 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChan1(const Common::Image<TriChanPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> chanImage)
		{
			setImageChan<TriChanPixel<TVALUE>, TVALUE, TINDEX>(image, 0, chanImage);
		}

		/// <summary>
		/// Sets the second chan of a 3 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChan2(const Common::Image<TriChanPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> chanImage)
		{
			setImageChan<TriChanPixel<TVALUE>, TVALUE, TINDEX>(image, 1, chanImage);
		}

		/// <summary>
		/// Sets the third chan of a 3 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChan3(const Common::Image<TriChanPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> chanImage)
		{
			setImageChan<TriChanPixel<TVALUE>, TVALUE, TINDEX>(image, 2, chanImage);
		}

		/// <summary>
		/// Sets the first chan of a 4 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChan1(const Common::Image<QuadChanPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> chanImage)
		{
			setImageChan<QuadChanPixel<TVALUE>, TVALUE, TINDEX>(image, 0, chanImage);
		}

		/// <summary>
		/// Sets the second chan of a 4 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChan2(const Common::Image<QuadChanPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> chanImage)
		{
			setImageChan<QuadChanPixel<TVALUE>, TVALUE, TINDEX>(image, 1, chanImage);
		}

		/// <summary>
		/// Sets the third chan of a 4 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChan3(const Common::Image<QuadChanPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> chanImage)
		{
			setImageChan<QuadChanPixel<TVALUE>, TVALUE, TINDEX>(image, 2, chanImage);
		}

		/// <summary>
		/// Sets the fourth chan of a 4 chan image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChan4(const Common::Image<QuadChanPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> chanImage)
		{
			setImageChan<QuadChanPixel<TVALUE>, TVALUE, TINDEX>(image, 3, chanImage);
		}

	};
}

#endif // DRAWINGCHANIMAGES_H
