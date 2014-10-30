#ifndef MOVEMENTIACTUATOR_H
#define MOVEMENTIACTUATOR_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	class IActuator
	{
		Common::Matrix4<TVALUE> getTransformMatrix();

		// add set(TVALUE) function? would be good to have a single point where a float can be passed to an actuator. will this work for all?

		virtual ~IActuator()
		{
		}
	};
}

#endif // MOVEMENTIACTUATOR_H
