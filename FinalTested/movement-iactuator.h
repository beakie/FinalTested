#ifndef MOVEMENTIACTUATOR_H
#define MOVEMENTIACTUATOR_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE>
	class IActuator
	{
		Common::Matrix4<TVALUE> getTransformMatrix();

		virtual ~IActuator()
		{
		}
	};
}

#endif // MOVEMENTIACTUATOR_H
