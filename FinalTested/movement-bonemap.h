#ifndef MOVEMENTBONEMAP_H
#define MOVEMENTBONEMAP_H

#include "core.h"
#include "common.h"

#include "movement-jointlist.h"

// This IS NOT a skeletal. A skeletal should be a 3d representation of the bone structure. this is simply to show connections between joints.

namespace Movement
{
	template <typename TPOINT>
	struct BoneMap
	{
		UInt8* ParentBones;
		TPOINT** BoneEnds;
		UInt8 BoneCount;

		BoneMap()
			: ParentBones(0),
			  BoneEnds(0),
			  BoneCount(0)
		{
		}

		BoneMap(const BoneMap& boneMap)
			: BoneCount(boneMap.BoneCount)
		{
			ParentBones = new UInt8[boneMap.BoneCount];
			BoneEnds = new TPOINT*[boneMap.BoneCount];

			for (UInt8 i = 0; i < boneMap.BoneCount; i++)
			{
				ParentBones[i] = boneMap.ParentBones[i];
				BoneEnds[i] = new TPOINT(boneMap.BoneEnds[i]);
			}
		}

		BoneMap(UInt8 chainedBoneCount)
			: BoneCount(chainedBoneCount)
		{
			ParentBones = new UInt8[chainedBoneCount];
			BoneEnds = new TPOINT*[chainedBoneCount];

			for (UInt8 i = 0; i < chainedBoneCount; i++)
			{
				ParentBones[i] = (i == 0 ? 0 : i - 1);
				BoneEnds = new TPOINT(TPOINT::getZero());
			}
		}

		template <typename TVALUE>
		BoneMap(const JointList<TVALUE>& jointList)
			: BoneMap(jointList.JointCount)
		{
		}

		BoneMap& operator=(const BoneMap& boneMap)
		{
			UInt8* tmpParentBones = new UInt8[boneMap.BoneCount + 1];
			TPOINT** tmpBoneEnds = new TPOINT*[boneMap.BoneCount + 1];

			for (UInt8 i = 0; i < boneMap.BoneCount; i++)
			{
				tmpParentBones[i] = boneMap.ParentBones[i];
				tmpBoneEnds[i] = new TPOINT(*boneMap.BoneEnds[i]);
			}

			delete[] ParentBones;
			delete[] BoneEnds;

			ParentBones = tmpParentBones;
			BoneEnds = tmpBoneEnds;

			BoneCount = boneMap.BoneCount;

			return *this;
		}

		UInt8 addBone(UInt8 parent)
		{
			UInt8* tmpParentBones = new UInt8[BoneCount + 1];
			TPOINT** tmpBoneEnds = new TPOINT*[BoneCount + 1];

			for (UInt8 i = 0; i < BoneCount; i++)
			{
				tmpParentBones[i] = ParentBones[i];
				tmpBoneEnds[i] = new TPOINT(*BoneEnds[i]);
			}

			tmpParentBones[BoneCount] = parent;
			tmpBoneEnds[BoneCount] = new TPOINT(TPOINT::getZero());

			delete[] ParentBones;
			delete[] BoneEnds;

			ParentBones = tmpParentBones;
			BoneEnds = tmpBoneEnds;

			BoneCount++;

			return ParentBones[BoneCount - 1];
		}

		UInt8 addBone()
		{
			return addBone(BoneCount);
		}

		bool isParent(const UInt8 index) const
		{
			for (UInt8 i = 0; i < BoneCount; i++)
				if ((ParentBones[i] == index) && (i != index))
					return true;

			return false;
		}

		bool isChild(const UInt8 index) const
		{
			return ParentBones[index] == index;
		}

		Common::Nullable<UInt8> findChild(const UInt8 parentIndex, const Common::Nullable<UInt8> lastChildIndex = Common::Null) const
		{
			if (lastChildIndex == BoneCount)
				return Common::Null;

			UInt8 fromIndex = 0;
			if (lastChildIndex.HasValue)
				fromIndex = lastChildIndex.Value + 1;

			for (UInt8 i = fromIndex; i < BoneCount; i++)
				if ((ParentBones[i] == parentIndex) && (i != parentIndex))
					return i;

			return Common::Null;
		}

		void populateChildren(const UInt8 parentIndex) const
		{

		}

		~BoneMap()
		{
			delete[] ParentBones;

			for (UInt8 i = 0; i < BoneCount; i++)
				delete BoneEnds[i];

			delete[] BoneEnds;
		}

	};
}

#endif // MOVEMENTBONEMAP_H
