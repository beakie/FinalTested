#ifndef MOVEMENTLINEARACTUATOR_H
#define MOVEMENTLINEARACTUATOR_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE>
	class LinearActuator : IActuator<TVALUE>
	{
	public:
		Common::Matrix4<TVALUE> PreTransformMatrix;
		Common::Matrix4<TVALUE> PostTransformMatrix;
		TVALUE Movement;

		LinearActuator(const Common::Vector3<TVALUE>& position, const Common::Vector3<TVALUE>& axisAlignment)
			: Movement(0)
		{
			// Calc pre and post matrices

		}

		Common::Matrix4<TVALUE> getTransformMatrix() const
		{
			return PreTransformMatrix * Space3d::getTranslationMatrix() * PostTransformMatrix;
		}

		void setRadians(const TVALUE radians)
		{
			Rotation = radians;
		}

		void setDegrees(const TVALUE degrees)
		{
			setRadians(Common::radian(degrees));
		}

		~LinearActuator()
		{
		}
	};

}

#endif // MOVEMENTLINEARACTUATOR_H
