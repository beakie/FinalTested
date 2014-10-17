#ifndef PICTURECOLORMODELCONVBUILDERS_H
#define PICTURECOLORMODELCONVBUILDERS_H

#include "common.h"
#include "picture-hsvtorgbpixelconv.h"
#include "picture-rgbtohsvpixelconv.h"
#include "picture-spreadchantrichanpixelconv.h"
#include "picture-selectchantrichanpixelconv.h"
#include "picture-selectchanavgtrichanpixelconv.h"

namespace Picture
{

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadRedRgbConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadGreenRgbConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadBlueRgbConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectRedRgbConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectGreenRgbConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectBlueRgbConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SelectChanAvgTriChanPixelConv<TVALUE> getRgbIntensityConv()
	{
		return SelectChanAvgTriChanPixelConv<TVALUE>();
	}

	template <typename TVALUE>
	RgbToHsvConv<TVALUE> getRgbToHsvConv()
	{
		return RgbToHsvConv<TVALUE>();
	}

	template <typename TVALUE>
	HsvToRgbConv<TVALUE> getHsvToRgbConv()
	{
		return HsvToRgbConv<TVALUE>();
	}

}

#endif // PICTURECOLORMODELCONVBUILDERS_H
