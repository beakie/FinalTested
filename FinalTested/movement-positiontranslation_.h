#ifndef MOVEMENTPOSITIONTRANSLATION_H
#define MOVEMENTPOSITIONTRANSLATION_H

#include "space2d.h"
#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-doublepositionlist.h"
#include "movement-jointlist.h"
#include "movement-singlepositionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	template <typename TPOINT>
	DoublePositionList<TPOINT> getTranslatedJoints()
	{
		return DoublePositionList<TPOINT>();
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedJoints2d()
	{
		return getTranslatedJoints<Common::Vector2<TVALUE>>();
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedJoints3d()
	{
		return getTranslatedJoints<Common::Vector3<TVALUE>>();
	}

}

#endif // MOVEMENTPOSITIONTRANSLATION_H
