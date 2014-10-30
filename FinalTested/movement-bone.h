#ifndef MOVEMENTBONE_H
#define MOVEMENTBONE_H

#include "core.h"
#include "common.h"
#include "space3d.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
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

		Bone<TVALUE>& addBone()
		{
			Bone<TVALUE>** tmpChildrenBones = new Bone<TVALUE>*[ChildrenBoneCount + 1];

			for (UInt8 i = 0; i < ChildrenBoneCount; i++)
				tmpChildrenBones[i] = ChildrenBones[i];

			tmpChildrenBones[ChildrenBoneCount] = new Bone<TVALUE>(*this);

			delete[] ChildrenBones;

			ChildrenBones = tmpChildrenBones;

			ChildrenBoneCount++;

			return *ChildrenBones[ChildrenBoneCount - 1];
		}

		~Bone()
		{
			for (UInt8 i = 0; i < ChildrenBoneCount; i++)
				delete ChildrenBones[i];

			delete[] ChildrenBones;
		}
	};
}

#endif // MOVEMENTBONE_H
