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

		UInt8 currentIndex = index;

		while (boneMap.ParentBones[currentIndex] != currentIndex)
		{
			currentIndex = boneMap.ParentBones[currentIndex];
			matrix *= jointList[currentIndex]; // !!! this should be in ascending order not descending !!!
		}

		return matrix;
	}

}

#endif // MOVEMENTSKELETALMATRICES_H
