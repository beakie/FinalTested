#ifndef MOVEMENTBONE_H
#define MOVEMENTBONE_H

#include "core.h"
#include "common.h"
#include "space3d.h"

namespace Movement
{
	template <typename TVALUE>
	struct Bone
	{
		Bone<TVALUE>* ParentBone;
		UInt8 ChildrenBoneCount;
		Bone<TVALUE>** ChildrenBones;
		Common::Matrix4<TVALUE> JointTransformMatrix;

		Bone()
			: ParentBone(nullptr),
			  ChildrenBoneCount(0),
			  ChildrenBones(0)
		{
		}

		Bone(const Bone<TVALUE>* parentBone)
			: ParentBone(parentBone),
			  ChildrenBoneCount(0),
			  ChildrenBones(0)
		{
		}

		Bone(const Bone<TVALUE>& bone)
		{
			// todo
		}

		Common::Matrix4<TVALUE> getArmTransformMatrix()
		{
			if (ParentBone == nullptr)
				return JointTransformMatrix;
			else
				return ParentBone->getArmTransformMatrix() * JointTransformMatrix;
		}

		void addBone()
		{
			Bone<TVALUE>** tmpChildrenBones = new Bone<TVALUE>[ChildBoneCount + 1];

			for (UInt8 i = 0; i < ChildBoneCount; i++)
				tmpChildBones[i] = ChildrenBones[i];

			tmpChildBones[ChildBoneCount] = new Bone<TVALUE>(*this);

			delete[] ChildrenBones;

			ChildrenBones = tmpChildBones;

			ChildBoneCount++;
		}

		~Bone()
		{
			for (UInt8 i = 0; i < ChildBoneCount; i++)
				delete ChildrenBones[i];
		}
	};
}

#endif // MOVEMENTBONE_H
