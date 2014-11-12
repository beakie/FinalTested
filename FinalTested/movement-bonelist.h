#ifndef MOVEMENTBONELIST_H
#define MOVEMENTBONELIST_H

#include "core.h"
#include "common.h"

#include "movement-jointlist.h"

// This IS NOT a skeletal. A skeletal should be a 3d representation of the bone structure. this is simply to show connections between joints.

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct BoneList
	{
		UInt8* Bones;
		UInt8 BoneCount;

		BoneList()
			: Bones(0),
			  BoneCount(0)
		{
		}

		BoneList(const BoneList<TVALUE>& boneList)
			: BoneCount(boneList.BoneCount)
		{
			Bones = new UInt8[boneList.BoneCount];

			for (UInt8 i = 0; i < boneList.BoneCount; i++)
				Bones[i] = boneList.Bones[i];
		}

		BoneList(UInt8 size)
			: BoneCount(size)
		{
			Bones = new UInt8[size];

			for (UInt8 i = 0; i < size; i++)
				Bones[i] = (i == 0 ? 0 : i - 1);
		}

		BoneList(const JointList<TVALUE>& jointList)
			: BoneList(jointList.JointCount)
		{
		}

		BoneList<TVALUE>& operator=(const BoneList<TVALUE>& boneList)
		{
			UInt8* tmpBones = new UInt8[boneList.BoneCount + 1];

			for (UInt8 i = 0; i < boneList.BoneCount; i++)
				tmpBones[i] = boneList.Bones[i];

			delete[] Bones;

			Bones = tmpBones;

			BoneCount = boneList.BoneCount;

			return *this;
		}

		UInt8 addBone(UInt8 parent)
		{
			UInt8* tmpBones = new UInt8[BoneCount + 1];

			for (UInt8 i = 0; i < BoneCount; i++)
				tmpBones[i] = Bones[i];

			tmpBones[BoneCount] = parent;

			delete[] Bones;

			Bones = tmpBones;

			BoneCount++;

			return Bones[BoneCount - 1];
		}

		bool isRootBone(const UInt8 index) const
		{
			return Bones[index] == index;
		}

		Common::Nullable<UInt8> findChild(const UInt8 parentIndex, const Common::Nullable<UInt8> lastChildIndex = Common::Null) const
		{
			if (lastChildIndex == BoneCount)
				return Common::Null;

			UInt8 fromIndex = 0;
			if (lastChildIndex.HasValue)
				fromIndex = lastChildIndex.Value + 1;

			for (UInt8 i = fromIndex; i < BoneCount; i++)
				if ((Bones[i] == parentIndex) && (i != parentIndex))
					return i;

			return Common::Null;
		}

		void populateChildren(const UInt8 parentIndex) const
		{

		}

		~BoneList()
		{
			delete[] Bones;
		}

	};
}

#endif // MOVEMENTBONELIST_H
