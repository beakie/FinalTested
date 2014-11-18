#ifndef BODYRENDERRENDERBONES_H
#define BODYRENDERRENDERBONES_H

#include "movement.h"

namespace BodyRender
{
	template <typename TPOINT, typename TMATRIX>
	void render(Movement::Skeletal<TPOINT, TMATRIX> skeletal)
	{
		return render(Movement::getTranslatedJoints(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions));
	}

	template <typename TPOINT>
	void render(Movement::PositionList<TPOINT> positionList)
	{

	}
}

#endif // BODYRENDERRENDERBONES_H
