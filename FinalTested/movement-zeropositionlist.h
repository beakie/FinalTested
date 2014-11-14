#ifndef MOVEMENTZEROPOSITIONLIST_H
#define MOVEMENTZEROPOSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct ZeroPositionList
	{
		TPOINT** Positions;
		UInt8 PositionCount;

		ZeroPositionList()
			: Positions(0),
			  PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		ZeroPositionList(const ZeroPositionList<TPOINT>& jointList)
		{
			Positions = new TPOINT*[jointList.PositionCount];

			for (UInt8 i = 0; i < jointList.PositionCount; i++)
				Positions[i] = jointList.Positions[i];

			PositionCount = jointList.PositionCount;
		}

		ZeroPositionList(UInt8 size)
			: PositionCount(size)
		{
			Positions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Positions[i] = new TPOINT(TPOINT::getZero());
		}

		ZeroPositionList<TPOINT>& operator=(const ZeroPositionList<TPOINT>& jointList)
		{
			TPOINT** tmpPositions = new TPOINT*[jointList.PositionCount + 1];

			for (UInt8 i = 0; i < jointList.PositionCount; i++)
				tmpPositions[i] = jointList.Positions[i];

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount = jointList.PositionCount;

			return *this;
		}

		TPOINT& addJoint()
		{
			TPOINT** tmpPositions = new TPOINT*[PositionCount + 1];

			for (UInt8 i = 0; i < PositionCount; i++)
				tmpPositions[i] = Positions[i];

			tmpPositions[PositionCount] = new TPOINT(TPOINT::getZero());

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount++;

			return *Positions[PositionCount - 1];
		}

		~ZeroPositionList()
		{
			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENTZEROPOSITIONLIST_H
