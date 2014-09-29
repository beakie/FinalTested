#ifndef COMMONIMAGES_H
#define COMMONIMAGES_H

#include "common-image.h"
#include "common-triplechannelpixel.h"
#include "common-quadchannelpixel.h"

namespace Common
{
	static class Images
	{
	public:
		template <typename TIMAGE, typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannelImage(const TIMAGE& image, const TINDEX channelIndex)
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(image.Width, image.Height);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					i.Values[x][y] = image.Values[x][y].Channels[channelIndex];

			return i;
		}

		template <typename TIMAGE, typename TVALUE, typename TINDEX>
		static void setChannelImage(const TIMAGE& image, const TINDEX channelIndex, const Image<TVALUE, TINDEX> channelImage)
		{
			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					image.Values[x][y].Channels[channelIndex] = channelImage.Values[x][y];
		}

		/// <summary>
		/// Returns the first channel from a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel1Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0);
		}

		/// <summary>
		/// Returns the second channel from a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel2Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1);
		}

		/// <summary>
		/// Returns the third channel from a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel3Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2);
		}

		/// <summary>
		/// Returns the first channel from a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel1Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0);
		}

		/// <summary>
		/// Returns the second channel from a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel2Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1);
		}

		/// <summary>
		/// Returns the third channel from a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel3Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2);
		}

		/// <summary>
		/// Returns the fourth channel from a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel4Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 3);
		}

		/// <summary>
		/// Sets the first channel of a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setChannel1Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image, const Image<TVALUE, TINDEX> channelImage)
		{
			setChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0, channelImage);
		}

		/// <summary>
		/// Sets the second channel of a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setChannel2Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image, const Image<TVALUE, TINDEX> channelImage)
		{
			setChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1, channelImage);
		}

		/// <summary>
		/// Sets the third channel of a 3 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setChannel3Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image, const Image<TVALUE, TINDEX> channelImage)
		{
			setChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2, channelImage);
		}

		/// <summary>
		/// Sets the first channel of a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setChannel1Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image, const Image<TVALUE, TINDEX> channelImage)
		{
			setChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0, channelImage);
		}

		/// <summary>
		/// Sets the second channel of a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setChannel2Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image, const Image<TVALUE, TINDEX> channelImage)
		{
			setChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1, channelImage);
		}

		/// <summary>
		/// Sets the third channel of a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setChannel3Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image, const Image<TVALUE, TINDEX> channelImage)
		{
			setChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2, channelImage);
		}

		/// <summary>
		/// Sets the fourth channel of a 4 channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static void setChannel4Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image, const Image<TVALUE, TINDEX> channelImage)
		{
			setChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 3, channelImage);
		}

	};
}

#endif // COMMONIMAGES_H
