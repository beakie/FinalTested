#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"
#include "space3d.h"

#include "movement-bone.h"

//idea: if i add relative matrix to 0,0,0 to this code can I calculate the matrix required to go from one arm to the next/distance between to end effectors

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct Skeletal
	{
		Bone<TVALUE>** Arms;
		UInt8 ArmCount;

		Skeletal()
			: Arms(0),
			  ArmCount(0)
		{
		}

		Bone<TVALUE>& addArm(Joint<TVALUE>* joint)
		{
			Bone<TVALUE>** tmpArms = new Bone<TVALUE>*[ArmCount + 1];

			for (UInt8 i = 0; i < ArmCount; i++)
				tmpArms[i] = Arms[i];

			tmpArms[ArmCount] = new Bone<TVALUE>(joint);

			delete[] Arms;

			Arms = tmpArms;

			ArmCount++;

			return *Arms[ArmCount - 1];
		}

		~Skeletal()
		{
			for (UInt8 i = 0; i < ArmCount; i++)
				delete Arms[i];

			delete[] Arms;
		}
	};
}

#endif // MOVEMENTSKELETAL_H
