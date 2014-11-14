#ifndef MOVEMENTSKELETALMATRICES_H
#define MOVEMENTSKELETALMATRICES_H

#include "space2d.h"
#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-doublepositionlist.h"
#include "movement-jointlist.h"
#include "movement-singlepositionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	template <typename TVALUE>
	Common::Matrix3<TVALUE> get2d(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const UInt8 index)
	{
		Common::Matrix3<TVALUE> matrix = jointList.Joints[index];

		if (boneMap.ParentBones[index] != index)
			return get2d(jointList, boneMap, boneMap.ParentBones[index]) * matrix;
		else
			return matrix;
	}

}

#endif // MOVEMENTSKELETALMATRICES_H
