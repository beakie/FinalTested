#ifndef DRAWINGIMAGES_H
#define DRAWINGIMAGES_H

#include "common-image.h"
#include "drawing-triplechannelpixel.h"
#include "drawing-quadchannelpixel.h"

namespace Drawing
{
	static class Images
	{
	public:
		template <typename TIMAGE, typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChannel(const TIMAGE& image, const UInt8 channelIndex)
		{
			Common::Image<TVALUE, TINDEX> i = Common::Image<TVALUE, TINDEX>(image.Width, image.Height);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					i.Values[x][y] = image.Values[x][y].Channels[channelIndex];

			return i;
		}

		template <typename TIMAGE, typename TVALUE, typename TINDEX>
		static void setImageChannel(const TIMAGE& image, const TINDEX channelIndex, const Common::Image<TVALUE, TINDEX>& channelImage)
		{
			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					image.Values[x][y].Channels[channelIndex] = channelImage.Values[x][y];
		}

		/// <summary>
		/// Returns the first channel from a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChannel1(const Common::Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChannel<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0);
		}

		/// <summary>
		/// Returns the second channel from a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChannel2(const Common::Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChannel<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1);
		}

		/// <summary>
		/// Returns the third channel from a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChannel3(const Common::Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChannel<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2);
		}

		/// <summary>
		/// Returns the first channel from a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChannel1(const Common::Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChannel<Common::Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0);
		}

		/// <summary>
		/// Returns the second channel from a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChannel2(const Common::Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChannel<Common::Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1);
		}

		/// <summary>
		/// Returns the third channel from a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChannel3(const Common::Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChannel<Common::Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2);
		}

		/// <summary>
		/// Returns the fourth channel from a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::Image<TVALUE, TINDEX> getImageChannel4(const Common::Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getImageChannel<Common::Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 3);
		}

		/// <summary>
		/// Sets the first channel of a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChannel1(const Common::Image<TripleChannelPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> channelImage)
		{
			setImageChannel<Common::Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0, channelImage);
		}

		/// <summary>
		/// Sets the second channel of a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChannel2(const Common::Image<TripleChannelPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> channelImage)
		{
			setImageChannel<Common::Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1, channelImage);
		}

		/// <summary>
		/// Sets the third channel of a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChannel3(const Common::Image<TripleChannelPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> channelImage)
		{
			setImageChannel<Common::Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2, channelImage);
		}

		/// <summary>
		/// Sets the first channel of a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChannel1(const Common::Image<QuadChannelPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> channelImage)
		{
			setImageChannel<Common::Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0, channelImage);
		}

		/// <summary>
		/// Sets the second channel of a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChannel2(const Common::Image<QuadChannelPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> channelImage)
		{
			setImageChannel<Common::Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1, channelImage);
		}

		/// <summary>
		/// Sets the third channel of a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChannel3(const Common::Image<QuadChannelPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> channelImage)
		{
			setImageChannel<Common::Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2, channelImage);
		}

		/// <summary>
		/// Sets the fourth channel of a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setImageChannel4(const Common::Image<QuadChannelPixel<TVALUE>, TINDEX>& image, const Common::Image<TVALUE, TINDEX> channelImage)
		{
			setImageChannel<Common::Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 3, channelImage);
		}

	};
}

#endif // DRAWINGIMAGES_H
