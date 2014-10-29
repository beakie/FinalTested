#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"
#include "space3d.h"

#include "movement-bone.h"

namespace Movement
{
	template <typename TVALUE>
	struct Skeletal
	{
		UInt8 ArmCount;
		Bone<TVALUE>** Arms;

		Skeletal()
			: ArmCount(0),
			  Arms(0)
		{
		}

		Skeletal(const Skeletal<TVALUE>& skeletal)
		{
			// todo
		}

		void addArm()
		{
			Bone<TVALUE>** tmpArms = new Bone<TVALUE>[ArmCount + 1];

			for (UInt8 i = 0; i < ArmCount; i++)
				tmpArms[i] = Arms[i];

			tmpArms[ArmCount] = new Bone<TVALUE>(*this);

			delete[] Arms;

			Arms = tmpArms;

			ArmCount++;
		}

		~Bone()
		{
			for (UInt8 i = 0; i < ArmCount; i++)
				delete Arms[i];
		}
	};
}

#endif // MOVEMENTSKELETAL_H
