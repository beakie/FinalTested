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

	template <typename TMATRIX>
	TMATRIX get2d(const JointList<TMATRIX>& jointList, const BoneMap& boneMap, const UInt8 index)
	{
		if (boneMap.ParentBones[index] != index)
			return get2d(jointList, boneMap, boneMap.ParentBones[index]) * *jointList.Joints[index];
		else
			return *jointList.Joints[index];
	}

}

#endif // MOVEMENTSKELETALMATRICES_H
