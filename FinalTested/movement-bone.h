#ifndef MOVEMENTTREEBONE_H
#define MOVEMENTTREEBONE_H

#include "core.h"
#include "common.h"
#include "space3d.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct TreeBone
	{
		TreeBone<TVALUE>* ParentTreeBone;
		TreeBone<TVALUE>** ChildrenTreeBones;
		UInt8 ChildrenTreeBoneCount;
		Common::Matrix4<TVALUE>* Joint;

		TreeBone(Common::Matrix4<TVALUE>* joint)
			: ParentTreeBone(nullptr),
			  ChildrenTreeBoneCount(0),
			  ChildrenTreeBones(0),
			  Joint(joint)
		{
		}

		TreeBone(TreeBone<TVALUE>* parentTreeBone, Common::Matrix4<TVALUE>* joint)
			: ParentTreeBone(parentTreeBone),
			  ChildrenTreeBoneCount(0),
			  ChildrenTreeBones(0),
			  Joint(joint)
		{
		}

		TreeBone(const TreeBone<TVALUE>& bone)
		{
			// todo
		}

		Common::Matrix4<TVALUE> getArmTransformMatrix()
		{
			if (ParentTreeBone == nullptr)
				return *Joint;
			else
				return ParentTreeBone->getArmTransformMatrix() * *Joint;
		}

		TreeBone<TVALUE>& addTreeBone(Common::Matrix4<TVALUE>* joint)
		{
			TreeBone<TVALUE>** tmpChildrenTreeBones = new TreeBone<TVALUE>*[ChildrenTreeBoneCount + 1];

			for (UInt8 i = 0; i < ChildrenTreeBoneCount; i++)
				tmpChildrenTreeBones[i] = ChildrenTreeBones[i];

			tmpChildrenTreeBones[ChildrenTreeBoneCount] = new TreeBone<TVALUE>(this, joint);

			delete[] ChildrenTreeBones;

			ChildrenTreeBones = tmpChildrenTreeBones;

			ChildrenTreeBoneCount++;

			return *ChildrenTreeBones[ChildrenTreeBoneCount - 1];
		}

		~TreeBone()
		{
			for (UInt8 i = 0; i < ChildrenTreeBoneCount; i++)
				delete ChildrenTreeBones[i];

			delete[] ChildrenTreeBones;
		}
	};
}

#endif // MOVEMENTTREEBONE_H
