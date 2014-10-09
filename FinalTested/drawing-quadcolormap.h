#ifndef DRAWINGQUADCOLORMAP_H
#define DRAWINGQUADCOLORMAP_H

#include "core.h"
#include "common.h"

#include "drawing-quadchanpixel.h"

namespace Drawing
{
	template <typename TUNITINTERVAL>
	struct QuadColorMap
	{
		TUNITINTERVAL** Values;
		UInt8 Size;

		QuadColorMap(UInt8 size) : Size(size)
		{
			createValues(size);
		}

		QuadColorMap(const QuadColorMap<TUNITINTERVAL>& QuadColorMap) : Size(QuadColorMap.Size)
		{
			createValues(QuadColorMap.Size);
			copyValues(QuadColorMap);
		}

		QuadColorMap<TUNITINTERVAL>& operator=(const QuadColorMap<TUNITINTERVAL>& QuadColorMap)
		{
			if (this != &QuadColorMap)
			{
				deleteValues();
				createValues(QuadColorMap.Size);
				copyValues(QuadColorMap);

				Size = QuadColorMap.Size;
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
		}

		void deleteValues()
		{
			delete[] Values[0];
			delete[] Values[1];
			delete[] Values[2];
			delete[] Values[3];
			delete[] Values;
		}

		void copyValues(const QuadColorMap<TUNITINTERVAL>& QuadColorMap)
		{
			for (UInt8 i = 0; i < QuadColorMap.Size; i++)
			{
				Values[0][i] = QuadColorMap.Values[0][i];
				Values[1][i] = QuadColorMap.Values[1][i];
				Values[2][i] = QuadColorMap.Values[2][i];
				Values[3][i] = QuadColorMap.Values[3][i];
			}
		}

	public:
		~QuadColorMap()
		{
			deleteValues();
		}
	};
}

#endif // DRAWINGQUADCOLORMAP_H
