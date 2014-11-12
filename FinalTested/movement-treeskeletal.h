#ifndef MOVEMENTTREESKELETAL_H
#define MOVEMENTTREESKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bone.h"
#include "movement-jointlist.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct TreeSkeletal
	{
		Bone<TVALUE>** Bones;
		UInt8* BoneParent;
		UInt8 BoneCount;

		TreeSkeletal()
			: Bones(0),
			BoneCount(0)
		{
		}

		TreeSkeletal(const TreeSkeletal<TVALUE>& TreeSkeletal)
		{
			Bones = new Bone<TVALUE>*[TreeSkeletal.BoneCount];

			for (UInt8 i = 0; i < TreeSkeletal.BoneCount; i++)
				Bones[i] = TreeSkeletal.Bones[i];

			BoneCount = TreeSkeletal.BoneCount;
		}

		TreeSkeletal(Common::Matrix4<TVALUE>** jointList, UInt8 jointCount)
			: BoneCount(jointCount)
		{
			Bones = new Bone<TVALUE>*[jointCount];

			for (UInt8 i = 0; i < jointCount; i++)
				Bones[i] = new Bone<TVALUE>(i == 0 ? nullptr : Bones[i - 1], jointList[i]);
		}

		TreeSkeletal(const JointList<TVALUE>& jointList)
			: TreeSkeletal(jointList.Joints, jointList.JointCount)
		{
		}

		TreeSkeletal<TVALUE>& operator=(const TreeSkeletal<TVALUE>& TreeSkeletal)
		{
			Bone<TVALUE>** tmpBones = new Bone<TVALUE>*[TreeSkeletal.BoneCount + 1];

			for (UInt8 i = 0; i < TreeSkeletal.BoneCount; i++)
				tmpBones[i] = TreeSkeletal.Bones[i];

			delete[] Bones;

			Bones = tmpBones;

			BoneCount = TreeSkeletal.BoneCount;

			return *this;
		}

		Bone<TVALUE>& addBone(Common::Matrix4<TVALUE>* joint)
		{
			Bone<TVALUE>** tmpBones = new Bone<TVALUE>*[BoneCount + 1];

			for (UInt8 i = 0; i < BoneCount; i++)
				tmpBones[i] = Bones[i];

			tmpBones[BoneCount] = new Bone<TVALUE>(tmpBones[BoneCount - 1], joint);

			delete[] Bones;

			Bones = tmpBones;

			BoneCount++;

			return *Bones[BoneCount - 1];
		}

		~TreeSkeletal()
		{
			for (UInt8 i = 0; i < BoneCount; i++)
				delete Bones[i];

			delete[] Bones;
		}

	};
}

#endif // MOVEMENTTREESKELETAL_H
