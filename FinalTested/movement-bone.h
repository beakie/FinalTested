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
		Bone<TVALUE>** ChildrenBones; //should this be list? if so, probably should be private to stop direct add/remove
		Common::Matrix4<TVALUE> JointTransformMatrix;

		Bone()
		{
			//todo
			//do i need to set nullptr?
		}

		Bone(const Bone<TVALUE>& bone)
		{
			//todo
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

			ChildrenBones = new Bone<TVALUE>();
		}

		UInt8 getChildBoneCount()
		{
			if (ParentBone == nullptr)
				return JointTransformMatrix;
			else
				return ParentBone->getArmTransformMatrix() * JointTransformMatrix;
		}

		~Bone()
		{
			if (ParentBone != nullptr)
				delete ParentBone;
		}
	};
}

#endif // MOVEMENTBONE_H
