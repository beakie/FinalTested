#ifndef MOVEMENTLINEARACTUATOR_H
#define MOVEMENTLINEARACTUATOR_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE = FloatMax, typename TUNITINTERVAL = Common::UnitIntervalMax>
	class LinearActuator : public IActuator<TVALUE, TUNITINTERVAL>
	{
	public:
		Common::Matrix4<TVALUE> PreTransformMatrix;
		Common::Matrix4<TVALUE> PostTransformMatrix;
		TVALUE Movement;

		LinearActuator(const Common::Vector3<TVALUE>& position, const Common::Vector3<TVALUE>& alignment)
			: Movement(0)
		{
			// Calc pre and post matrices

		}

		LinearActuator(const LinearActuator<TVALUE>& linearActuator)
			: PreTransformMatrix(linearActuator.PreTransformMatrix),
			  PostTransformMatrix(linearActuator.PostTransformMatrix),
			  Movement(linearActuator.Movement)
		{
		}

		LinearActuator<TVALUE>& operator=(const LinearActuator<TVALUE>& linearActuator)
		{
			PreTransformMatrix = linearActuator.PreTransformMatrix;
			PostTransformMatrix = linearActuator.PostTransformMatrix;
			Movement = linearActuator.Movement;

			return *this;
		}

		Common::Matrix4<TVALUE> getTransformMatrix() const
		{
			return PreTransformMatrix * Space3d::getTranslationMatrixAxisX(Movement) * PostTransformMatrix;
		}

		IActuator<TVALUE, TUNITINTERVAL>& setPosition(TUNITINTERVAL unitInterval)
		{
			//Movement = ??; // This should be the maximum amount of distance the linear actuator can extend

			return *this;
		}

		virtual ~LinearActuator()
		{
		}
	};

}

#endif // MOVEMENTLINEARACTUATOR_H
