#ifndef COMMONIPIXELCONVERTER_H
#define COMMONIPIXELCONVERTER_H

#include "core.h"

namespace Common
{
	template <typename TVALUEIN, typename TVALUEOUT>
	class IPixelConverter
	{
		TVALUEOUT convertPixel(const TVALUEIN& pixel);

		virtual ~IPixelConverter()
		{
		}
	};
}

#endif // COMMONIPIXELCONVERTER_H
