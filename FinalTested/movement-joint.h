#ifndef MOVEMENTJOINT_H
#define MOVEMENTJOINT_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct Joint
	{
		Common::Matrix4<TVALUE> TransformMatrix;
	};
}

#endif // MOVEMENTJOINT_H
