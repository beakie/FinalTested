#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"
#include "space3d.h"

#include "movement-bone.h"

//idea: if i add relative matrix to 0,0,0 to this code can I calculate the matrix required to go from one arm to the next/distance between to end effectors

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct Skeletal
	{
		Bone<TVALUE>** Arms;
		UInt8 ArmCount;
		Common::Matrix4<TVALUE>** JointMatrices;
		UInt8 JointCount;

		Skeletal()
			: Arms(0),
			  ArmCount(0),
			  JointMatrices(0),
			  JointCount(0)
		{
		}

		Skeletal(const Skeletal<TVALUE>& skeletal)
		{
			// todo
		}

		Common::Matrix4<TVALUE>& addJoint()
		{
			Common::Matrix4<TVALUE>** tmpJointMatrices = new Common::Matrix4<TVALUE>*[JointCount + 1];

			for (UInt8 i = 0; i < JointCount; i++)
				tmpJointMatrices[i] = JointMatrices[i];

			tmpJointMatrices[JointCount] = new Common::Matrix4<TVALUE>();

			delete[] JointMatrices;

			JointMatrices = tmpJointMatrices;

			JointCount++;

			return *JointMatrices[JointCount - 1];
		}

		Bone<TVALUE>& addArm(Common::Matrix4<TVALUE>* jointTransformMatrix)
		{
			Bone<TVALUE>** tmpArms = new Bone<TVALUE>*[ArmCount + 1];

			for (UInt8 i = 0; i < ArmCount; i++)
				tmpArms[i] = Arms[i];

			tmpArms[ArmCount] = new Bone<TVALUE>(jointTransformMatrix);

			delete[] Arms;

			Arms = tmpArms;

			ArmCount++;

			return *Arms[ArmCount - 1];
		}

		~Skeletal()
		{
			for (UInt8 i = 0; i < ArmCount; i++)
				delete Arms[i];

			delete[] Arms;

			for (UInt8 i = 0; i < JointCount; i++)
				delete JointMatrices[i];

			delete[] JointMatrices;
		}
	};
}

#endif // MOVEMENTSKELETAL_H
