#ifndef MOVEMENTROTATINGACTUATOR_H
#define MOVEMENTROTATINGACTUATOR_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE = FloatMax, typename TUNITINTERVAL = Common::UnitIntervalMax>
	class RotatingActuator : public IActuator<TVALUE, TUNITINTERVAL>
	{
	public:
		Common::Matrix4<TVALUE> PreTransformMatrix;
		Common::Matrix4<TVALUE> PostTransformMatrix;
		TVALUE Rotation;

		RotatingActuator(const Common::Vector3<TVALUE>& axisFrom, const Common::Vector3<TVALUE>& axisTo)
			: Rotation(0)
		{
			// Calc pre and post matrices

		}

		RotatingActuator(const RotatingActuator<TVALUE>& rotatingActuator)
			: PreTransformMatrix(rotatingActuator.PreTransformMatrix),
			  PostTransformMatrix(rotatingActuator.PostTransformMatrix),
			  Rotation(rotatingActuator.Rotation)
		{
		}

		RotatingActuator<TVALUE>& operator=(const RotatingActuator<TVALUE>& rotatingActuator)
		{
			PreTransformMatrix = rotatingActuator.PreTransformMatrix;
			PostTransformMatrix = rotatingActuator.PostTransformMatrix;
			Rotation = rotatingActuator.Rotation;

			return *this;
		}

		Common::Matrix4<TVALUE> getTransformMatrix() const
		{
			return PreTransformMatrix * Space3d::getRotationMatrixAxisX(Rotation) * PostTransformMatrix;
		}

		IActuator<TVALUE, TUNITINTERVAL>& setPosition(TUNITINTERVAL unitInterval)
		{
			Rotation = (TVALUE)unitInterval * 2;

			return *this;
		}

		void setRadians(const TVALUE radians)
		{
			Rotation = radians;
		}

		void setDegrees(const TVALUE degrees)
		{
			setRadians(Common::radian(degrees));
		}

		virtual ~RotatingActuator()
		{
		}
	};

}

#endif // MOVEMENTROTATINGACTUATOR_H
