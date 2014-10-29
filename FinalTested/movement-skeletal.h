#ifndef MOVEMENTSKELETAL_H
#define MOVEMENTSKELETAL_H

#include "core.h"
#include "common.h"
#include "space3d.h"

#include "movement-bone.h"

namespace Movement
{
	template <typename TVALUE>
	struct Skeletal
	{
		Common::List<Bone<TVALUE>*> Arms;
	};
}

#endif // MOVEMENTSKELETAL_H
