#ifndef MOVEMENTSERVOACTUATOR_H
#define MOVEMENTSERVOACTUATOR_H

#include "core.h"
#include "common.h"

namespace Movement
{
	template <typename TVALUE>
	class ServoActuator
	{
	public:
		Common::Matrix4<TVALUE> getTransformMatrix() const
		{
			return Common::Matrix4<TVALUE>();
		}
	};

}

#endif // MOVEMENTSERVOACTUATOR_H
