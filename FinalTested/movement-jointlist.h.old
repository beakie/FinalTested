#ifndef MOVEMENTJOINTLIST_H
#define MOVEMENTJOINTLIST_H

#include "core.h"
#include "common.h"

#include "movement-joint.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct JointList
	{
		Joint<TVALUE>** Joints;
		UInt8 JointCount;

		JointList()
			: Joints(0),
			  JointCount(0)
		{
		}

		Joint<TVALUE>& addJoint()
		{
			Joint<TVALUE>** tmpJoints = new Joint<TVALUE>*[JointCount + 1];

			for (UInt8 i = 0; i < JointCount; i++)
				tmpJoints[i] = Joints[i];

			tmpJoints[JointCount] = new Joint<TVALUE>();

			delete[] Joints;

			Joints = tmpJoints;

			JointCount++;

			return *Joints[JointCount - 1];
		}

		~JointList()
		{
			for (UInt8 i = 0; i < JointCount; i++)
				delete Joints[i];

			delete[] Joints;
		}

	};
}

#endif // MOVEMENTJOINTLIST_H
