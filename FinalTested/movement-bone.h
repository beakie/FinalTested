#ifndef MOVEMENTCHAINBONE_H
#define MOVEMENTCHAINBONE_H

#include "core.h"
#include "common.h"
#include "space3d.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct ChainBone
	{
		ChainBone<TVALUE>* ParentChainBone;
		Common::Matrix4<TVALUE>* Joint;

		ChainBone(Common::Matrix4<TVALUE>* joint)
			: ParentChainBone(nullptr),
			  Joint(joint)
		{
		}

		ChainBone(ChainBone<TVALUE>* parentChainBone, Common::Matrix4<TVALUE>* joint)
			: ParentChainBone(parentChainBone),
			  Joint(joint)
		{
		}

		ChainBone(const ChainBone<TVALUE>& bone)
		{
			// todo
		}

		Common::Matrix4<TVALUE> getArmTransformMatrix()
		{
			if (ParentChainBone == nullptr)
				return *Joint;
			else
				return ParentChainBone->getArmTransformMatrix() * *Joint;
		}

		~ChainBone()
		{
		}
	};
}

#endif // MOVEMENTCHAINBONE_H
