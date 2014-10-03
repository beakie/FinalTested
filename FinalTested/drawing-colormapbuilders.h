#ifndef DRAWINGCOLORMAPBUILDER_H
#define DRAWINGCOLORMAPBUILDER_H

#include "core.h"
#include "common.h"

#include "drawing-triplechannelcolormap.h"

namespace Drawing
{
	static class ColorMapBuilders
	{

	public:
		template <typename TPIXELVALUE, typename TUNITINTERVAL>
		static TripleChannelColorMap<TPIXELVALUE, TUNITINTERVAL> getJetRGBColorMap()
		{
			return TripleChannelColorMap<TPIXELVALUE, TUNITINTERVAL>(10);
		}

	};
}

#endif // DRAWINGCOLORMAPBUILDER_H
