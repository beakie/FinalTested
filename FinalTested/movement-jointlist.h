#ifndef MOVEMENTJOINTLIST_H
#define MOVEMENTJOINTLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct JointList
	{
		Common::Matrix4<TVALUE>** Joints;
		UInt8 JointCount;

		JointList()
			: Joints(0),
			  JointCount(0)
		{
		}

		Common::Matrix4<TVALUE>& addJoint()
		{
			Common::Matrix4<TVALUE>** tmpJoints = new Common::Matrix4<TVALUE>*[JointCount + 1];

			for (UInt8 i = 0; i < JointCount; i++)
				tmpJoints[i] = Joints[i];

			tmpJoints[JointCount] = new Common::Matrix4<TVALUE>();

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
