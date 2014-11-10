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

		JointList(const JointList<TVALUE>& jointList)
		{
			Joints = new Common::Matrix4<TVALUE>*[jointList.JointCount];

			for (UInt8 i = 0; i < jointList.JointCount; i++)
				Joints[i] = jointList.Joints[i];

			JointCount = jointList.JointCount;
		}

		JointList(UInt8 size)
			: JointCount(size)
		{
			Joints = new Common::Matrix4<TVALUE>*[size];

			for (UInt8 i = 0; i < size; i++)
			{
				Joints[i] = new Common::Matrix4<TVALUE>();
				Joints[i]->identity();
			}
		}

		JointList<TVALUE>& operator=(const JointList<TVALUE>& jointList)
		{
			Common::Matrix4<TVALUE>** tmpJoints = new Common::Matrix4<TVALUE>*[jointList.JointCount + 1];

			for (UInt8 i = 0; i < jointList.JointCount; i++)
				tmpJoints[i] = jointList.Joints[i];

			delete[] Joints;

			Joints = tmpJoints;

			JointCount = jointList.JointCount;

			return *this;
		}

		Common::Matrix4<TVALUE>& addJoint()
		{
			Common::Matrix4<TVALUE>** tmpJoints = new Common::Matrix4<TVALUE>*[JointCount + 1];

			for (UInt8 i = 0; i < JointCount; i++)
				tmpJoints[i] = Joints[i];

			tmpJoints[JointCount] = new Common::Matrix4<TVALUE>();
			tmpJoints[JointCount]->identity();

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
