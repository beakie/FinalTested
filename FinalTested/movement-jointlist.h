#ifndef MOVEMENTJOINTLIST_H
#define MOVEMENTJOINTLIST_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct JointList
	{
		Common::Matrix4<TVALUE>** JointMatrices;
		UInt8 JointCount;

		Common::Matrix4<TVALUE>& addJoint()
		{
			Common::Matrix4<TVALUE>** tmpJointMatrices = new Common::Matrix4<TVALUE>*[JointCount + 1];

			for (UInt8 i = 0; i < JointCount; i++)
				tmpJointMatrices[i] = JointMatrices[i];

			tmpJointMatrices[JointCount] = new Common::Matrix4<TVALUE>(Common::Matrix4<TVALUE>().identity());

			delete[] JointMatrices;

			JointMatrices = tmpJointMatrices;

			JointCount++;

			return *JointMatrices[JointCount - 1];
		}

		~JointList()
		{
			for (UInt8 i = 0; i < JointCount; i++)
				delete JointMatrices[i];

			delete[] JointMatrices;
		}

	};
}

#endif // MOVEMENTJOINTLIST_H
