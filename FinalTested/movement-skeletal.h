#ifndef MOVEMENTBONELIST_H
#define MOVEMENTBONELIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct BoneList
	{
		Common::Tuple2<UInt8, UInt8>** Bones;
		UInt8 BoneCount;

		BoneList()
			: Bones(0),
			BoneCount(0)
		{
		}

		BoneList(const BoneList<TVALUE>& boneList)
		{
			Bones = new Common::Tuple2<UInt8, UInt8>*[boneList.BoneCount];

			for (UInt8 i = 0; i < boneList.BoneCount; i++)
				Bones[i] = boneList.Bones[i];

			BoneCount = boneList.BoneCount;
		}

		BoneList(UInt8 size)
			: BoneCount(size)
		{
			Bones = new Common::Tuple2<UInt8, UInt8>*[size];

			for (UInt8 i = 0; i < size; i++)
				Bones[i] = new Common::Tuple2<UInt8, UInt8>(Common::Tuple2<UInt8, UInt8>::getIdentity());
		}

		BoneList<TVALUE>& operator=(const BoneList<TVALUE>& boneList)
		{
			Common::Tuple2<UInt8, UInt8>** tmpBones = new Common::Tuple2<UInt8, UInt8>*[boneList.BoneCount + 1];

			for (UInt8 i = 0; i < boneList.BoneCount; i++)
				tmpBones[i] = boneList.Bones[i];

			delete[] Bones;

			Bones = tmpBones;

			BoneCount = boneList.BoneCount;

			return *this;
		}

		Common::Tuple2<UInt8, UInt8>& addBone()
		{
			Common::Tuple2<UInt8, UInt8>** tmpBones = new Common::Tuple2<UInt8, UInt8>*[BoneCount + 1];

			for (UInt8 i = 0; i < BoneCount; i++)
				tmpBones[i] = Bones[i];

			tmpBones[BoneCount] = new Common::Tuple2<UInt8, UInt8>(Common::Tuple2<UInt8, UInt8>::getIdentity());

			delete[] Bones;

			Bones = tmpBones;

			BoneCount++;

			return *Bones[BoneCount - 1];
		}

		~BoneList()
		{
			for (UInt8 i = 0; i < BoneCount; i++)
				delete Bones[i];

			delete[] Bones;
		}

	};
}

#endif // MOVEMENTBONELIST_H
