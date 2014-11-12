#ifndef MOVEMENTBONEMAP_H
#define MOVEMENTBONEMAP_H

#include "core.h"
#include "common.h"

#include "movement-jointlist.h"

// This IS NOT a skeletal. A skeletal should be a 3d representation of the bone structure. this is simply to show connections between joints.

namespace Movement
{
	struct BoneMap
	{
		UInt8* Bones;
		UInt8 BoneCount;

		BoneMap()
			: Bones(0),
			  BoneCount(0)
		{
		}

		BoneMap(const BoneMap& boneMap)
			: BoneCount(boneMap.BoneCount)
		{
			Bones = new UInt8[boneMap.BoneCount];

			for (UInt8 i = 0; i < boneMap.BoneCount; i++)
				Bones[i] = boneMap.Bones[i];
		}

		BoneMap(UInt8 size)
			: BoneCount(size)
		{
			Bones = new UInt8[size];

			for (UInt8 i = 0; i < size; i++)
				Bones[i] = (i == 0 ? 0 : i - 1);
		}

		template <typename TVALUE>
		BoneMap(const JointList<TVALUE>& jointList)
			: BoneMap(jointList.JointCount)
		{
		}

		BoneMap& operator=(const BoneMap& boneMap)
		{
			UInt8* tmpBones = new UInt8[boneMap.BoneCount + 1];

			for (UInt8 i = 0; i < boneMap.BoneCount; i++)
				tmpBones[i] = boneMap.Bones[i];

			delete[] Bones;

			Bones = tmpBones;

			BoneCount = boneMap.BoneCount;

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

		UInt8 addBone()
		{
			return addBone(BoneCount);
		}

		bool isParent(const UInt8 index) const
		{
			for (UInt8 i = 0; i < BoneCount; i++)
				if ((Bones[i] == index) && (i != index))
					return true;

			return false;
		}

		bool isChild(const UInt8 index) const
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

		~BoneMap()
		{
			delete[] Bones;
		}

	};
}

#endif // MOVEMENTBONEMAP_H
