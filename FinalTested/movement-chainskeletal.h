#ifndef MOVEMENTCHAINSKELETAL_H
#define MOVEMENTCHAINSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bone.h"
#include "movement-jointlist.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct ChainSkeletal
	{
		Bone<TVALUE>** Bones;
		UInt8 BoneCount;

		ChainSkeletal()
			: Bones(0),
			  BoneCount(0)
		{
		}

		ChainSkeletal(const ChainSkeletal<TVALUE>& chainSkeletal)
		{
			Bones = new Bone<TVALUE>*[chainSkeletal.BoneCount];

			for (UInt8 i = 0; i < chainSkeletal.BoneCount; i++)
				Bones[i] = chainSkeletal.Bones[i];

			BoneCount = chainSkeletal.BoneCount;
		}

		ChainSkeletal(const Common::Matrix4<TVALUE>* jointList, UInt8 count)
		{
		}

		ChainSkeletal(const JointList<TVALUE>& jointList)
			: BoneCount(jointList.JointCount)
		{
			Bones = new Bone<TVALUE>*[jointList.JointCount];

			for (UInt8 i = 0; i < jointList.JointCount; i++)
				Bones[i] = new Bone<TVALUE>(i == 0 ? nullptr : Bones[i - 1], jointList.Joints[i]);
		}

		ChainSkeletal<TVALUE>& operator=(const ChainSkeletal<TVALUE>& chainSkeletal)
		{
			Bone<TVALUE>** tmpBones = new Bone<TVALUE>*[chainSkeletal.BoneCount + 1];

			for (UInt8 i = 0; i < chainSkeletal.BoneCount; i++)
				tmpBones[i] = chainSkeletal.Bones[i];

			delete[] Bones;

			Bones = tmpBones;

			BoneCount = chainSkeletal.BoneCount;

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

		~ChainSkeletal()
		{
			for (UInt8 i = 0; i < BoneCount; i++)
				delete Bones[i];

			delete[] Bones;
		}

	};
}

#endif // MOVEMENTCHAINSKELETAL_H
