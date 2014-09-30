#ifndef RENDERPICTURE_H
#define RENDERPICTURE_H

#include "core.h"
#include "common.h"

namespace Render
{
	static class Picture
	{
		/// <summary>
		/// ...
		/// </summary>
		template <typename TVALUE, typename TINDEX>
		static Common::TripleChannelPixel<TVALUE> mapImageTo3ChannelFalse(const TVALUE& value)
		{
			for (TINDEX x = 0; x < image.Width; x++)
				for (TINDEX y = 0; y < image.Height; y++)
					i.Values[x][y] = Common::TripleChannelPixel<TVALUE>(1, 1, 1);

			return i;
		}
	};
}

#endif // RENDERPICTURE_H
