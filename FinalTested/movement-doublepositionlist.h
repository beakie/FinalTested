#ifndef MOVEMENTDOUBLEPOSITIONLIST_H
#define MOVEMENTDOUBLEPOSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct DoublePositionList
	{
		TPOINT** FromPositions;
		TPOINT** ToPositions;
		UInt8 PositionCount;

		DoublePositionList()
			: FromPositions(0),
			  ToPositions(0),
			  PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		DoublePositionList(const DoublePositionList<TPOINT>& positionList)
		{
			FromPositions = new TPOINT*[positionList.PositionCount];
			ToPositions = new TPOINT*[positionList.PositionCount];

			for (UInt8 i = 0; i < positionList.PositionCount; i++)
			{
				FromPositions[i] = new TPOINT(*positionList.FromPositions[i]);
				ToPositions[i] = new TPOINT(*positionList.ToPositions[i]);
			}

			PositionCount = positionList.PositionCount;
		}

		DoublePositionList(UInt8 size)
			: PositionCount(size)
		{
			FromPositions = new TPOINT*[size];
			ToPositions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
			{
				FromPositions[i] = new TPOINT(TPOINT::getZero());
				ToPositions[i] = new TPOINT(TPOINT::getZero());
			}
		}

		DoublePositionList<TPOINT>& operator=(const DoublePositionList<TPOINT>& positionList)
		{
			TPOINT** tmpFromPositions = new TPOINT*[positionList.PositionCount + 1];
			TPOINT** tmpToPositions = new TPOINT*[positionList.PositionCount + 1];

			for (UInt8 i = 0; i < positionList.PositionCount; i++)
			{
				tmpFromPositions[i] = new TPOINT(*positionList.FromPositions[i]);
				tmpToPositions[i] = new TPOINT(*positionList.ToPositions[i]);
			}

			delete[] FromPositions;
			delete[] ToPositions;

			FromPositions = tmpFromPositions;
			ToPositions = tmpToPositions;

			PositionCount = positionList.PositionCount;

			return *this;
		}

		UInt8 addJoint()
		{
			TPOINT** tmpFromPositions = new TPOINT*[PositionCount + 1];
			TPOINT** tmpToPositions = new TPOINT*[PositionCount + 1];

			for (UInt8 i = 0; i < PositionCount; i++)
			{
				tmpFromPositions[i] = FromPositions[i];
				tmpToPositions[i] = ToPositions[i];
			}

			tmpFromPositions[PositionCount] = new TPOINT(TPOINT::getZero());
			tmpToPositions[PositionCount] = new TPOINT(TPOINT::getZero());

			delete[] FromPositions;
			delete[] ToPositions;

			FromPositions = tmpFromPositions;
			ToPositions = tmpToPositions;

			PositionCount++;

			return PositionCount - 1;
		}

		~DoublePositionList()
		{
			for (UInt8 i = 0; i < PositionCount; i++)
			{
				delete FromPositions[i];
				delete ToPositions[i];
			}

			delete[] FromPositions;
			delete[] ToPositions;
		}

	};
}

#endif // MOVEMENTDOUBLEPOSITIONLIST_H
