#ifndef MOVEMENTSINGLEPOSITIONLIST_H
#define MOVEMENTSINGLEPOSITIONLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TPOINT>
	struct SinglePositionList
	{
		TPOINT** Positions;
		UInt8 PositionCount;

		SinglePositionList()
			: Positions(0),
			  PositionCount(0)
		{
		}

		template <typename TVALUE = FloatMax>
		SinglePositionList(const SinglePositionList<TPOINT>& positionList)
		{
			Positions = new TPOINT*[positionList.PositionCount];

			for (UInt8 i = 0; i < positionList.PositionCount; i++)
				Positions[i] = new TPOINT(positionList.Positions[i]);

			PositionCount = positionList.PositionCount;
		}

		SinglePositionList(UInt8 size)
			: PositionCount(size)
		{
			Positions = new TPOINT*[size];

			for (UInt8 i = 0; i < size; i++)
				Positions[i] = new TPOINT(TPOINT::getZero());
		}

		SinglePositionList<TPOINT>& operator=(const SinglePositionList<TPOINT>& positionList)
		{
			TPOINT** tmpPositions = new TPOINT*[positionList.PositionCount + 1];

			for (UInt8 i = 0; i < positionList.PositionCount; i++)
				tmpPositions[i] = new TPOINT(positionList.Positions[i]);

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount = positionList.PositionCount;

			return *this;
		}

		UInt8 addSingle()
		{
			TPOINT** tmpPositions = new TPOINT*[PositionCount + 1];

			for (UInt8 i = 0; i < PositionCount; i++)
				tmpPositions[i] = Positions[i];

			tmpPositions[PositionCount] = new TPOINT(TPOINT::getZero());

			delete[] Positions;

			Positions = tmpPositions;

			PositionCount++;

			return PositionCount - 1;
		}

		~SinglePositionList()
		{
			for (UInt8 i = 0; i < PositionCount; i++)
				delete Positions[i];

			delete[] Positions;
		}

	};
}

#endif // MOVEMENTSINGLEPOSITIONLIST_H
