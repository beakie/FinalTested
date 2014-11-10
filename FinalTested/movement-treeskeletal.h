#ifndef MOVEMENTTREESKELETAL_H
#define MOVEMENTTREESKELETAL_H

#include "core.h"
#include "common.h"
#include "space3d.h"

#include "movement-bone.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct TreeSkeletal
	{
		Bone<TVALUE>** Bones;
		UInt8 BoneCount; // should this be here or in skeletal? i could prob just have one bone type then...

		Bone<TVALUE>& addBone(UInt8 parentIndex, Common::Matrix4<TVALUE>* joint)
		{
			Bone<TVALUE>** tmpBones = new Bone<TVALUE>*[BoneCount + 1];

			for (UInt8 i = 0; i < BoneCount; i++)
				tmpBones[i] = Bones[i];

			tmpBones[BoneCount] = new Bone<TVALUE>(Bones[parentIndex], joint);

			delete[] Bones;

			Bones = tmpBones;

			BoneCount++;

			return *Bones[BoneCount - 1];
		}
	};
}

#endif // MOVEMENTTREESKELETAL_H
