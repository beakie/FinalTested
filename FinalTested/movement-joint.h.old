// this will hold the matrix for the joint so that chain matrix can be calculated
// ... but it will also contain the joint offset/placement matrix

#ifndef MOVEMENTJOINT_H
#define MOVEMENTJOINT_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct Joint
	{
		Common::Matrix4<TVALUE> ActuatorMatrix;
		Common::Matrix4<TVALUE> JointPlacementMatrix;
		Common::Matrix4<TVALUE> InverseJointPlacementMatrix;

		Common::Matrix4<TVALUE> getMatrix() const
		{
			return JointPlacementMatrix * ActuatorMatrix * InverseJointPlacementMatrix;
		}
	};
}

#endif // MOVEMENTJOINT_H
