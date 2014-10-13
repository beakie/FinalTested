#ifndef COMMONSCALECASTPIXELCONV_H
#define COMMONSCALECASTPIXELCONV_H

#include "core.h"

namespace Common
{
	template <typename TIN, typename TOUT>
	class ScaleCastPixelConv
	{
	private:
		Float32 offsetIn; // Common::FloatMax offsetIn;
		Float32 offsetOut; // Common::FloatMax offsetOut;
		Float32 scale; // Common::FloatMax scale;
	public:

		ScaleCastPixelConv()
		{
			offsetIn = Common::getLowerBound<TIN>();
			offsetOut = Common::getLowerBound<TOUT>();
			//scale = (((Common::FloatMax)Common::getUpperBound<TOUT>() - offsetOut) / (Common::getUpperBound<TIN>() - offsetIn));
			scale = (((Float32)Common::getUpperBound<TOUT>() - offsetOut) / (Common::getUpperBound<TIN>() - offsetIn));
		}

		TOUT convertPixel(const TIN& pixel)
		{
			//return (TOUT)((((Common::FloatMax)pixel - offsetIn) * scale) + offsetOut);
			return (TOUT)((((Float32)pixel - offsetIn) * scale) + offsetOut);
		}
	};
}

#endif // COMMONSCALECASTPIXELCONV_H
