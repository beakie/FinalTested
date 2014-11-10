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
		// If I am caching, it would be more efficient to offer some code that overrides getArmTransformMatrix and caches each bit along each arm. Do a version that only caches the item explicitly specified
		// If I store Joints as list of 3d matrices... do i need 2d actuators and bones? should movement be movement3d? i could just ignore an axis but calculations will be slower.

		bool* Cached;
		Common::Matrix4<TVALUE>** TransformMatrix;
	};
}

#endif // MOVEMENTBONECACHE_H
