#ifndef MOVEMENTBONECACHE_H
#define MOVEMENTBONECACHE_H

#include "core.h"
#include "common.h"

#include "movement-bone.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	class BoneCache
		: Bone<TVALUE>
	{
	};
}

#endif // MOVEMENTBONECACHE_H
