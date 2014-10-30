#ifndef MOVEMENTROTATINGACTUATOR_H
#define MOVEMENTROTATINGACTUATOR_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE>
	class RotatingActuator : IActuator<TVALUE>
	{
	public:
		Common::Vector3<TVALUE> Position;
		Common::Vector3<TVALUE> AxisAlignment;
		TVALUE Rotation;

		RotatingActuator(const Common::Vector3<TVALUE>& position, const Common::Vector3<TVALUE>& axisAlignment, const TVALUE rotation)
		{
			Position = position;
			AxisAlignment = axisAlignment;
			Rotation = rotation;
		}

		Common::Matrix4<TVALUE> getTransformMatrix() const
		{
			return Common::Matrix4<TVALUE>();
		}

		~RotatingActuator()
		{
		}
	};

}

#endif // MOVEMENTROTATINGACTUATOR_H
