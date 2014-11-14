#ifndef MOVEMENTZEROPOSITIONLIST_H
#define MOVEMENTZEROPOSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct ZeroPositionList
	{
		TPOINT** FromPositions;
		TPOINT** ToPositions;
		UInt8 PositionCount;

		ZeroPositionList()
			: FromPositions(0),
			  ToPositions(0),
			  PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		ZeroPositionList(const ZeroPositionList<TPOINT>& jointList)
		{
			FromPositions = new TPOINT*[jointList.PositionCount];
			ToPositions = new TPOINT*[jointList.PositionCount];

			for (UInt8 i = 0; i < jointList.PositionCount; i++)
			{
				FromPositions[i] = jointList.FromPositions[i];
				ToPositions[i] = jointList.ToPositions[i];
			}

			PositionCount = jointList.PositionCount;
		}

		ZeroPositionList(UInt8 size)
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

		ZeroPositionList<TPOINT>& operator=(const ZeroPositionList<TPOINT>& jointList)
		{
			TPOINT** tmpFromPositions = new TPOINT*[jointList.PositionCount + 1];
			TPOINT** tmpToPositions = new TPOINT*[jointList.PositionCount + 1];

			for (UInt8 i = 0; i < jointList.PositionCount; i++)
			{
				tmpFromPositions[i] = jointList.FromPositions[i];
				tmpToPositions[i] = jointList.ToPositions[i];
			}

			delete[] FromPositions;
			delete[] ToPositions;

			FromPositions = tmpFromPositions;
			ToPositions = tmpToPositions;

			PositionCount = jointList.PositionCount;

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

		~ZeroPositionList()
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

#endif // MOVEMENTZEROPOSITIONLIST_H
