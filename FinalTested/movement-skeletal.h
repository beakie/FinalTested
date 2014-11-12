#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"

#include "movement-bonemap.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	struct Skeletal
	{
		BoneMap Map;

		Skeletal()
			: Map()
		{
		}

		Skeletal(const Skeletal<TVALUE>& skeletal)
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

		Skeletal<TVALUE>& operator=(const Skeletal<TVALUE>& skeletal)
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
