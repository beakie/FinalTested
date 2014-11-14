#ifndef MOVEMENTJOINTZEROLIST_H
#define MOVEMENTJOINTZEROLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct JointZeroList
	{
		TPOINT** Positions;
		UInt8 PositionCount;

		JointZeroList()
			: Positions(0),
			  PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		JointZeroList(const JointZeroList<TPOINT>& jointList)
		{
			Positions = new TPOINT*[jointList.PositionCount];

			for (UInt8 i = 0; i < jointList.PositionCount; i++)
				Positions[i] = jointList.Positions[i];

			PositionCount = jointList.PositionCount;
		}

		JointZeroList(UInt8 size)
			: PositionCount(size)
		{
			Positions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Positions[i] = new TPOINT(TPOINT::getZero());
		}

		JointZeroList<TPOINT>& operator=(const JointZeroList<TPOINT>& jointList)
		{
			TPOINT** tmpPositions = new TPOINT*[jointList.PositionCount + 1];

			for (UInt8 i = 0; i < jointList.PositionCount; i++)
				tmpPositions[i] = jointList.Positions[i];

			delete[] Positions;
			delete[] ToPositions;

			Positions = tmpPositions;

			PositionCount = jointList.PositionCount;

			return *this;
		}

		UInt8 addJoint()
		{
			TPOINT** tmpPositions = new TPOINT*[PositionCount + 1];

			for (UInt8 i = 0; i < PositionCount; i++)
			{
				tmpPositions[i] = Positions[i];
			}

			tmpPositions[PositionCount] = new TPOINT(TPOINT::getZero());

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount++;

			return PositionCount - 1;
		}

		~JointZeroList()
		{
			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENTJOINTZEROLIST_H
