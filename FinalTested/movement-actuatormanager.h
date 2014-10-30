#ifndef MOVEMENTACTUATORMANAGER_H
#define MOVEMENTACTUATORMANAGER_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"

namespace Movement
{
	template <typename TVALUE = FloatMax>
	class ActuatorManager
	{
	public:
		IActuator<TVALUE>** Actuators;
		UInt8 ActuatorCount;

		ActuatorManager()
			: Actuators(0),
			  ActuatorCount(0)
		{
		}

		template <typename TACTUATOR>
		void addActuator(const TACTUATOR& actuator)
		{
			IActuator<TVALUE>** tmpActuators = new IActuator<TVALUE>*[ActuatorCount + 1];

			for (UInt8 i = 0; i < ActuatorCount; i++)
				tmpActuators[i] = Actuators[i];

			tmpActuators[ActuatorCount] = new TACTUATOR(actuator);

			delete[] Actuators;

			Actuators = tmpActuators;

			ActuatorCount++;
		}

		~ActuatorManager()
		{
			for (UInt8 i = 0; i < ActuatorCount; i++)
				delete Actuators[i];

			delete[] Actuators;
		}
	};

}

#endif // MOVEMENTACTUATORMANAGER_H
