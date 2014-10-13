#ifndef PICTURERGBPIXELCONVBUILDERSCONV_H
#define PICTURERGBPIXELCONVBUILDERSCONV_H

#include "picture-trichanpixel.h"
#include "picture-spreadchantrichanpixelconv.h"
#include "picture-selectchantrichanpixelconv.h"
#include "picture-selectchanavgtrichanpixelconv.h"

namespace Picture
{

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadRedRGBPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadGreenRGBPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SpreadChanTriChanPixelConv<TVALUE> getGreySpreadBlueRGBPixelConv()
	{
		return SpreadChanTriChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectRedRGBPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(0);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectGreenRGBPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(1);
	}

	template <typename TVALUE>
	SelectChanTriChanPixelConv<TVALUE> getSelectBlueRGBPixelConv()
	{
		return SelectChanTriChanPixelConv<TVALUE>(2);
	}

	template <typename TVALUE>
	SelectChanAvgTriChanPixelConv<TVALUE> getRGBPixelIntensityConv()
	{
		return SelectChanAvgTriChanPixelConv<TVALUE>();
	}

}

#endif // PICTURERGBPIXELCONVBUILDERSCONV_H
