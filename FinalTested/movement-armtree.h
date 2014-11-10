#ifndef MOVEMENTBONE_H
#define MOVEMENTBONE_H

#include "core.h"
#include "common.h"
#include "space3d.h"

#include "movement-joint.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct Bone
	{
		Bone<TVALUE>* ParentBone;
		Bone<TVALUE>** ChildrenBones;
		UInt8 ChildrenBoneCount;
		Common::Matrix4<TVALUE>* Joint;

		Bone(Joint<TVALUE>* joint)
			: ParentBone(nullptr),
			ChildrenBoneCount(0),
			ChildrenBones(0),
			Joint(joint)
		{
		}

		Bone(Bone<TVALUE>* parentBone, Common::Matrix4<TVALUE>* joint)
			: ParentBone(parentBone),
			ChildrenBoneCount(0),
			ChildrenBones(0),
			Joint(joint)
		{
		}

		Bone(const Bone<TVALUE>& bone)
		{
			// todo
		}

		Common::Matrix4<TVALUE> getArmTransformMatrix()
		{
			if (ParentBone == nullptr)
				return *Joint;
			else
				return ParentBone->getArmTransformMatrix() * *Joint;
		}

		Bone<TVALUE>& addBone(Common::Matrix4<TVALUE>* joint)
		{
			Bone<TVALUE>** tmpChildrenBones = new Bone<TVALUE>*[ChildrenBoneCount + 1];

			for (UInt8 i = 0; i < ChildrenBoneCount; i++)
				tmpChildrenBones[i] = ChildrenBones[i];

			tmpChildrenBones[ChildrenBoneCount] = new Bone<TVALUE>(this, joint);

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
