#ifndef DRAWINGTRICOLORMAP_H
#define DRAWINGTRICOLORMAP_H

#include "core.h"
#include "common.h"

#include "drawing-trichannelpixel.h"

namespace Drawing
{
	template <typename TUNITINTERVAL>
	struct TriColorMap
	{
		TUNITINTERVAL** Values;
		UInt8 Size;

		TriColorMap(UInt8 size) : Size(size)
		{
			createValues(size);
		}

		TriColorMap(const TriColorMap<TUNITINTERVAL>& TriColorMap) : Size(TriColorMap.Size)
		{
			createValues(TriColorMap.Size);
			copyValues(TriColorMap);
		}

		TriColorMap<TUNITINTERVAL>& operator=(const TriColorMap<TUNITINTERVAL>& TriColorMap)
		{
			if (this != &TriColorMap)
			{
				deleteValues();
				createValues(TriColorMap.Size);
				copyValues(TriColorMap);

				Size = TriColorMap.Size;
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

		void copyValues(const TriColorMap<TUNITINTERVAL>& TriColorMap)
		{
			for (UInt8 i = 0; i < TriColorMap.Size; i++)
			{
				Values[0][i] = TriColorMap.Values[0][i];
				Values[1][i] = TriColorMap.Values[1][i];
				Values[2][i] = TriColorMap.Values[2][i];
			}
		}

	public:
		~TriColorMap()
		{
			deleteValues();
		}
	};
}

#endif // DRAWINGTRICOLORMAP_H
