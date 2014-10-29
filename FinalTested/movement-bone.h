#ifndef MOVEMENTBONE_H
#define MOVEMENTBONE_H

#include "core.h"
#include "common.h"
#include "space3d.h"

// THINK LOTS ABOUT GRIPPERS. GREAT EXAMPLE TO GET DESIGN RIGHT. HAS ONE ACTUATOR AND MULTIPLE JOINTS.
// http://www.robotforstudents.com/images_gripper/grip_hand6.png
// Made up or a simple rotational joint with a more complication joint which is the result of geom of a fixed point and the moving point

namespace Movement
{
	template <typename TVALUE>
	struct Bone
	{
		Bone<TVALUE>* ParentBone;
		UInt8 ChildrenBoneCount;
		Bone<TVALUE>** ChildrenBones;
		Common::Matrix4<TVALUE> JointTransformMatrix;
		Common::Matrix4<TVALUE> BoneTransformMatrix; //should this be here??? think long and hard. is this a job of the actuator? makes sense for some servos, but for grippers etc?

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
				return JointTransformMatrix * BoneTransformMatrix;
			else
				return ParentBone->getArmTransformMatrix() * JointTransformMatrix * BoneTransformMatrix;
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
		}
	};
}

#endif // MOVEMENTBONE_H
