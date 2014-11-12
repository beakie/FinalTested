#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bonemap.h"

namespace Movement
{
	template <typename TPOINT>
	struct Skeletal
	{
		BoneMap Map;
		TPOINT** Positions;

		Skeletal()
			: Map()
		{
		}

		Skeletal(const Skeletal<TPOINT>& skeletal)
			: Map(skeletal.BoneMap)
		{
		}

		Skeletal(UInt8 chainedBoneCount)
			: Map(chainedBoneCount)
		{
		}

		Skeletal(const BoneMap& boneMap)
			: Map(boneMap)
		{
		}

		Skeletal<TPOINT>& operator=(const Skeletal<TPOINT>& skeletal)
		{
			Map = skeletal.BoneMap;
		}

		UInt8 addBone(UInt8 parent)
		{
			Map.addBone(parent);
		}

		~Skeletal()
		{
		}

	};
}

#endif // MOVEMENTSKELETAL_H
