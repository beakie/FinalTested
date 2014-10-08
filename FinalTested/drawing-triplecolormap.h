#ifndef DRAWINGTRIPLECHANNELCOLORMAP_H
#define DRAWINGTRIPLECHANNELCOLORMAP_H

#include "core.h"
#include "common.h"

#include "drawing-triplechannelpixel.h"

namespace Drawing
{
	template <typename TUNITINTERVAL>
	struct TripleColorMap
	{
		TUNITINTERVAL** Values;
		UInt8 Size;

		TripleColorMap(UInt8 size) : Size(size)
		{
			createValues(size);
		}

		TripleColorMap(const TripleColorMap<TUNITINTERVAL>& TripleColorMap) : Size(TripleColorMap.Size)
		{
			createValues(TripleColorMap.Size);
			copyValues(TripleColorMap);
		}

		TripleColorMap<TUNITINTERVAL>& operator=(const TripleColorMap<TUNITINTERVAL>& TripleColorMap)
		{
			if (this != &TripleColorMap)
			{
				deleteValues();
				createValues(TripleColorMap.Size);
				copyValues(TripleColorMap);

				Size = TripleColorMap.Size;
			}

			return *this;
		}
		
	private:
		void createValues(UInt8 size)
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

		void copyValues(const TripleColorMap<TUNITINTERVAL>& TripleColorMap)
		{
			for (UInt8 i = 0; i < TripleColorMap.Size; i++)
			{
				Values[0][i] = TripleColorMap.Values[0][i];
				Values[1][i] = TripleColorMap.Values[1][i];
				Values[2][i] = TripleColorMap.Values[2][i];
			}
		}

	public:
		~TripleColorMap()
		{
			deleteValues();
		}
	};
}

#endif // DRAWINGTRIPLECHANNELCOLORMAP_H
