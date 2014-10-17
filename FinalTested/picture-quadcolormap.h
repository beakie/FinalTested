#ifndef PICTUREQUADCOLORMAP_H
#define PICTUREQUADCOLORMAP_H

#include "core.h"
#include "common.h"

namespace Picture
{
	template <typename TUNITINTERVAL>
	struct QuadColorMap
	{
		TUNITINTERVAL** Values;
		UInt8 Size;
		TUNITINTERVAL SpacingSize;

		QuadColorMap(UInt8 size)
		{
			createValues(size);
		}

		QuadColorMap(const QuadColorMap<TUNITINTERVAL>& quadColorMap)
		{
			createValues(quadColorMap.Size);
			copyValues(quadColorMap);
		}

		QuadColorMap<TUNITINTERVAL>& operator=(const QuadColorMap<TUNITINTERVAL>& quadColorMap)
		{
			if (this != &quadColorMap)
			{
				deleteValues();
				createValues(quadColorMap.Size);
				copyValues(quadColorMap);
			}

			return *this;
		}

	private:
		void createValues(UInt8 size)
		{
			Values = new TUNITINTERVAL*[4];
			Values[0] = new TUNITINTERVAL[size];
			Values[1] = new TUNITINTERVAL[size];
			Values[2] = new TUNITINTERVAL[size];
			Values[3] = new TUNITINTERVAL[size];
			Size = size;
			SpacingSize = (float)1 / (size - 1);
		}

		void deleteValues()
		{
			delete[] Values[0];
			delete[] Values[1];
			delete[] Values[2];
			delete[] Values[3];
			delete[] Values;
		}

		void copyValues(const QuadColorMap<TUNITINTERVAL>& quadColorMap)
		{
			for (UInt8 i = 0; i < quadColorMap.Size; i++)
			{
				Values[0][i] = quadColorMap.Values[0][i];
				Values[1][i] = quadColorMap.Values[1][i];
				Values[2][i] = quadColorMap.Values[2][i];
				Values[3][i] = quadColorMap.Values[3][i];
			}
		}

	public:
		~QuadColorMap()
		{
			deleteValues();
		}
	};
}

#endif // PICTUREQUADCOLORMAP_H
