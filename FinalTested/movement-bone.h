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
		Common::Matrix4<TVALUE>* Joint;

		Bone(Common::Matrix4<TVALUE>* joint)
			: ParentBone(nullptr),
			  Joint(joint)
		{
		}

		Bone(Bone<TVALUE>* parentBone, Common::Matrix4<TVALUE>* joint)
			: ParentBone(parentBone),
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

		~Bone()
		{
		}
	};
}

#endif // MOVEMENTBONE_H
