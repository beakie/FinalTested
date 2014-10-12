// ***********************************
// TriChanPixelConvBuilders
// ***********************************
//
//getSelect0TriChanPixelConv
//getSelect1TriChanPixelConv
//getSelect2TriChanPixelConv

#ifndef PICTURETRICHANPIXELCONVBUILDERSCONV_H
#define PICTURETRICHANPIXELCONVBUILDERSCONV_H

#include "picture-trichanpixel.h"
#include "picture-spreadchantrichanpixelconv.h"

namespace Picture
{
	template <typename TVALUE, typename TINDEX>
	SpreadChanTriChanPixelConv<TVALUE, TINDEX> getSpread0TriChanPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE, TINDEX>(0);
	}

	template <typename TVALUE, typename TINDEX>
	SpreadChanTriChanPixelConv<TVALUE, TINDEX> getSpread1TriChanPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE, TINDEX>(1);
	}

	template <typename TVALUE, typename TINDEX>
	SpreadChanTriChanPixelConv<TVALUE, TINDEX> getSpread2TriChanPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE, TINDEX>(2);
	}
}

#endif // PICTURETRICHANPIXELCONVBUILDERSCONV_H
