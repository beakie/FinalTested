#ifndef MOVEMENTBODY_H
#define MOVEMENTBODY_H

#include "core.h"
#include "common.h"

#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-skeletal.h"

namespace Movement
{
	template <typename TPOINT, typename TMATRIX>
	struct Body
	{
		JointList<TMATRIX> Joints;
		BoneMap<TPOINT> BoneMap;

		Body()
		{
		}

		Body(UInt8 chainedBoneCount)
			: Joints(chainedBoneCount)
		{
		}
	};
}

#endif // MOVEMENTBODY_H
