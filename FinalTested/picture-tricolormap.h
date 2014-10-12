#ifndef PICTURETRICOLORMAP_H
#define PICTURETRICOLORMAP_H

#include "core.h"
#include "common.h"

#include "picture-trichanpixel.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	struct TriColorMap
	{
		TUNITINTERVAL** Values;
		UInt8 Size;
		TUNITINTERVAL SpacingSize;

		TriColorMap(UInt8 size)
		{
			createValues(size);
		}

		TriColorMap(const TriColorMap<TUNITINTERVAL>& triColorMap)
		{
			createValues(triColorMap.Size);
			copyValues(triColorMap);
		}

		TriColorMap<TUNITINTERVAL>& operator=(const TriColorMap<TUNITINTERVAL>& triColorMap)
		{
			if (this != &triColorMap)
			{
				deleteValues();
				createValues(triColorMap.Size);
				copyValues(triColorMap);
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
			Size = size;
			SpacingSize = (float)1 / (size - 1);
		}

		void deleteValues()
		{
			delete[] Values[0];
			delete[] Values[1];
			delete[] Values[2];
			delete[] Values;
		}

		void copyValues(const TriColorMap<TUNITINTERVAL>& triColorMap)
		{
			for (UInt8 i = 0; i < triColorMap.Size; i++)
			{
				Values[0][i] = triColorMap.Values[0][i];
				Values[1][i] = triColorMap.Values[1][i];
				Values[2][i] = triColorMap.Values[2][i];
			}
		}

	public:
		~TriColorMap()
		{
			deleteValues();
		}
	};
}

#endif // PICTURETRICOLORMAP_H
