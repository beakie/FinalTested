#ifndef COMMONIMAGES_H
#define COMMONIMAGES_H

#include "common-image.h"
#include "common-triplechannelpixel.h"
#include "common-quadchannelpixel.h"

namespace Common
{
	static class Images
	{
	private:
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
		static TVALUE** getChannelPixels(const TIMAGE& image, const TINDEX channelIndex)
		{
			Image<TVALUE, TINDEX> i = Image<TVALUE, TINDEX>(image.Width, image.Height);

			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					i.Values[x][y] = image.Values[x][y].Channels[channelIndex];

			return i.Values;
		}

		template <typename TIMAGE, typename TVALUE, typename TINDEX>
		static void setChannelPixels(const TIMAGE& image, const TINDEX channelIndex, TVALUE** channelPixels)
		{
			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					image.Values[x][y].Channels[channelIndex] = channelPixels[x][y];
		}

		template <typename TIMAGE, typename TVALUE, typename TINDEX>
		static void setChannelImage(const TIMAGE& image, const TINDEX channelIndex, Image<TVALUE, TINDEX> channelImage)
		{
			setChannelPixels<TIMAGE, TVALUE, TINDEX>(image, channelIndex, channelImage.Values);
		}

	public:
		/// <summary>
		/// Returns the first channel from a triple channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel1Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0);
		}

		/// <summary>
		/// Returns the second channel from a triple channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel2Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1);
		}

		/// <summary>
		/// Returns the third channel from a triple channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel3Image(const Image<TripleChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<TripleChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2);
		}

		/// <summary>
		/// Returns the first channel from a quadruple channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel1Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 0);
		}

		/// <summary>
		/// Returns the second channel from a quadruple channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel2Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 1);
		}

		/// <summary>
		/// Returns the third channel from a quadruple channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel3Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 2);
		}

		/// <summary>
		/// Returns the fourth channel from a quadruple channel image
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Image<TVALUE, TINDEX> getChannel4Image(const Image<QuadChannelPixel<TVALUE>, TINDEX>& image)
		{
			return getChannelImage<Image<QuadChannelPixel<TVALUE>, TINDEX>, TVALUE, TINDEX>(image, 3);
		}

	};
}

#endif // COMMONIMAGES_H
