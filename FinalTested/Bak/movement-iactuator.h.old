#ifndef MOVEMENTIACTUATOR_H
#define MOVEMENTIACTUATOR_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE = FloatMax, typename TUNITINTERVAL = Common::UnitIntervalMax>
	class IActuator
	{
	public:
		virtual Common::Matrix4<TVALUE> getTransformMatrix() const = 0;

		virtual IActuator<TVALUE, TUNITINTERVAL>& setPosition(TUNITINTERVAL unitInterval) = 0;

		// add set(TVALUE) function? would be good to have a single point where a float can be passed to an actuator. will this work for all?

		virtual ~IActuator()
		{
		}
	};
}

#endif // MOVEMENTIACTUATOR_H
