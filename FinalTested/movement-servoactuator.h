#ifndef MOVEMENTSERVOACTUATOR_H
#define MOVEMENTSERVOACTUATOR_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE>
	class ServoActuator : IActuator<TVALUE>
	{
	public:
		Common::Vector3<TVALUE> Position;
		Common::Vector3<TVALUE> AxisAlignment;
		TVALUE Rotation;

		ServoActuator(const Common::Vector3<TVALUE>& position, const Common::Vector3<TVALUE>& axisAlignment, const TVALUE rotation)
		{
			Position = position;
			AxisAlignment = axisAlignment;
			Rotation = rotation;
		}

		Common::Matrix4<TVALUE> getTransformMatrix() const
		{
			return Common::Matrix4<TVALUE>();
		}

		~ServoActuator()
		{
		}
	};

}

#endif // MOVEMENTSERVOACTUATOR_H
