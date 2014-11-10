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
		Common::Matrix4<TVALUE> AxisAlignmentTransformMatrix;
		Common::Matrix4<TVALUE> InverseAxisAlignmentTransformMatrix;
		TVALUE Movement;

		LinearActuator(const Common::Vector3<TVALUE>& position, const Common::Vector3<TVALUE>& alignment)
			: Movement(0)
		{
			// Calc pre and post matrices

		}

		LinearActuator(const LinearActuator<TVALUE>& linearActuator)
			: AxisAlignmentTransformMatrix(linearActuator.AxisAlignmentTransformMatrix),
			  InverseAxisAlignmentTransformMatrix(linearActuator.InverseAxisAlignmentTransformMatrix),
			  Movement(linearActuator.Movement)
		{
		}

		LinearActuator<TVALUE>& operator=(const LinearActuator<TVALUE>& linearActuator)
		{
			AxisAlignmentTransformMatrix = linearActuator.AxisAlignmentTransformMatrix;
			InverseAxisAlignmentTransformMatrix = linearActuator.InverseAxisAlignmentTransformMatrix;
			Movement = linearActuator.Movement;

			return *this;
		}

		Common::Matrix4<TVALUE> getTransformMatrix() const
		{
			return AxisAlignmentTransformMatrix * Space3d::getTranslationMatrixAxisX(Movement) * InverseAxisAlignmentTransformMatrix;
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
