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
		Common::Matrix4<TVALUE> PreTransformMatrix;
		Common::Matrix4<TVALUE> PostTransformMatrix;
		TVALUE Rotation;

		RotatingActuator(const Common::Vector3<TVALUE>& position, const Common::Vector3<TVALUE>& axisAlignment)
			: Rotation(0)
		{
			// Calc pre and post matrices

		}

		Common::Matrix4<TVALUE> getTransformMatrix() const
		{
			return PreTransformMatrix * Space3d::getRotationMatrix(rotation) * PostTransformMatrix;
		}

		void setRadians(const TVALUE radians)
		{
			Rotation = radians;
		}

		void setDegrees(const TVALUE degrees)
		{
			setRadians(Common::radian(degrees));
		}

		~RotatingActuator()
		{
		}
	};

}

#endif // MOVEMENTROTATINGACTUATOR_H