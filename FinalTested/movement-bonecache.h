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
		// Bones are not linear
		// If I am caching, it would be more efficient to offer some code that overrides getArmTransformMatrix and caches each bit along each arm. Do a version that only caches the item explicitly specified

		bool* Cached;
		Common::Matrix4<TVALUE>** TransformMatrix;
	};
}

#endif // MOVEMENTBONECACHE_H
