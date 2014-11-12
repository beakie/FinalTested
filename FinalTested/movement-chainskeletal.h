#ifndef MOVEMENTCHAINSKELETAL_H
#define MOVEMENTCHAINSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bone.h"

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

		ChainSkeletal(UInt8 size)
			: BoneCount(size)
		{
			Bones = new Bone<TVALUE>*[size];

			for (UInt8 i = 0; i < size; i++)
			{
				Bones[i] = new Bone<TVALUE>();
				Bones[i]->identity();
			}
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

		Bone<TVALUE>& addBone()
		{
			Bone<TVALUE>** tmpBones = new Bone<TVALUE>*[BoneCount + 1];

			for (UInt8 i = 0; i < BoneCount; i++)
				tmpBones[i] = Bones[i];

			tmpBones[BoneCount] = new Bone<TVALUE>();
			tmpBones[BoneCount]->identity();

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
