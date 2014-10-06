#ifndef DRAWINGTRIPLECHANNELCOLORMAP_H
#define DRAWINGTRIPLECHANNELCOLORMAP_H

#include "core.h"
#include "common.h"

#include "drawing-triplechannelpixel.h"

namespace Drawing
{
	template <typename TPIXELVALUE, typename TUNITINTERVAL>
	struct TripleChannelColorMap
	{
		TUNITINTERVAL** Values;
		UInt_8 Size;

		TripleChannelColorMap(UInt_8 size) : Size(size)
		{
			createValues(size);
		}

		TripleChannelColorMap(const TripleChannelColorMap<TPIXELVALUE, TUNITINTERVAL>& tripleChannelColorMap) : Size(tripleChannelColorMap.Size)
		{
			createValues(tripleChannelColorMap.Size);
			copyValues(tripleChannelColorMap);
		}

		TripleChannelColorMap<TPIXELVALUE, TUNITINTERVAL>& operator=(const TripleChannelColorMap<TPIXELVALUE, TUNITINTERVAL>& tripleChannelColorMap)
		{
			if (this != &tripleChannelColorMap)
			{
				deleteValues();
				createValues(tripleChannelColorMap.Size);
				copyValues(tripleChannelColorMap);

				Size = TripleChannelColorMap.Size;
			}

			return *this;
		}
		
	private:
		void createValues(UInt_8 size)
		{
			Values = new TUNITINTERVAL*[3];
			Values[0] = new TUNITINTERVAL[size];
			Values[1] = new TUNITINTERVAL[size];
			Values[2] = new TUNITINTERVAL[size];
		}

		void deleteValues()
		{
			delete[] Values[0];
			delete[] Values[1];
			delete[] Values[2];
			delete[] Values;
		}

		void copyValues(const TripleChannelColorMap<TPIXELVALUE, TUNITINTERVAL>& tripleChannelColorMap)
		{
			for (UInt_8 i = 0; i < tripleChannelColorMap.Size; i++)
			{
				Values[0][i] = tripleChannelColorMap.Values[0][i];
				Values[1][i] = tripleChannelColorMap.Values[1][i];
				Values[2][i] = tripleChannelColorMap.Values[2][i];
			}
		}

	public:
		Drawing::TripleChannelPixel<UInt_8> convertPixelToRGBJet(const Common::UnitInterval_32& value) const
		{
			return Drawing::TripleChannelPixel<UInt_8>(1, 2, 3);
		}

		~TripleChannelColorMap()
		{
			deleteValues();
		}
	};
}

#endif // DRAWINGTRIPLECHANNELCOLORMAP_H