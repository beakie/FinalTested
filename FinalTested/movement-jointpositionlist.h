#ifndef MOVEMENTJOINTPOSITIONLIST_H
#define MOVEMENTJOINTPOSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct JointPositionList
	{
		TPOINT** Positions;
		UInt8 PositionCount;

		JointPositionList()
			: Positions(0),
			  PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		JointPositionList(const JointPositionList<TPOINT>& jointList)
		{
			Positions = new TPOINT*[jointList.PositionCount];

			for (UInt8 i = 0; i < jointList.PositionCount; i++)
				Positions[i] = jointList.Positions[i];

			PositionCount = jointList.PositionCount;
		}

		JointPositionList(UInt8 size)
			: PositionCount(size)
		{
			Positions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Positions[i] = new TPOINT(TPOINT::getPosition());
		}

		JointPositionList<TPOINT>& operator=(const JointPositionList<TPOINT>& jointList)
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

			tmpPositions[PositionCount] = new TPOINT(TPOINT::getPosition());

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount++;

			return PositionCount - 1;
		}

		~JointPositionList()
		{
			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENTJOINTPOSITIONLIST_H
