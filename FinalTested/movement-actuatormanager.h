#ifndef MOVEMENTACTUATORMANAGER_H
#define MOVEMENTACTUATORMANAGER_H

#include "core.h"
#include "common.h"

#include "movement-iactuator.h"
#include "movement-bone.h"

namespace Movement
{
	template <typename TVALUE = FloatMax, typename TUNITINTERVAL = Common::UnitIntervalMax>
	class ActuatorManager
	{
	public:
		IActuator<TVALUE, TUNITINTERVAL>** Actuators;
		UInt8 ActuatorCount;
		Common::Tuple2<IActuator<TVALUE, TUNITINTERVAL>*, Bone<TVALUE>*>** BoneLinks;
		UInt8 BoneLinkCount;

		ActuatorManager()
			: Actuators(0),
			  ActuatorCount(0),
			  BoneLinks(0),
			  BoneLinkCount(0)
		{
		}

		template <typename TACTUATOR>
		void addActuator(const TACTUATOR& actuator)
		{
			IActuator<TVALUE, TUNITINTERVAL>** tmpActuators = new IActuator<TVALUE, TUNITINTERVAL>*[ActuatorCount + 1];

			for (UInt8 i = 0; i < ActuatorCount; i++)
				tmpActuators[i] = Actuators[i];

			tmpActuators[ActuatorCount] = new TACTUATOR(actuator);

			delete[] Actuators;

			Actuators = tmpActuators;

			ActuatorCount++;
		}

		void addBoneLink(const Common::Tuple2<IActuator<TVALUE, TUNITINTERVAL>*, Bone<TVALUE>*>& boneLink)
		{
			Common::Tuple2<IActuator<TVALUE, TUNITINTERVAL>*, Bone<TVALUE>*>** tmpBoneLinks = new Common::Tuple2<IActuator<TVALUE, TUNITINTERVAL>*, Bone<TVALUE>*>*[BoneLinkCount + 1];

			for (UInt8 i = 0; i < BoneLinkCount; i++)
				tmpBoneLinks[i] = BoneLinks[i];

			tmpBoneLinks[BoneLinkCount] = new Common::Tuple2<IActuator<TVALUE, TUNITINTERVAL>*, Bone<TVALUE>*>(boneLink);

			delete[] BoneLinks;

			BoneLinks = tmpBoneLinks;

			BoneLinkCount++;
		}

		void addBoneLink(IActuator<TVALUE, TUNITINTERVAL>* actuator, Bone<TVALUE>* bone)
		{
			addBoneLink(Common::Tuple2<IActuator<TVALUE, TUNITINTERVAL>*, Bone<TVALUE>*>(actuator, bone));
		}

		template <typename TUNITINTERVAL>
		IActuator<TVALUE, TUNITINTERVAL>& setPosition(UInt8 actuatorIndex, TUNITINTERVAL unitInterval)
		{
			return Actuators[actuatorIndex]->setPosition(unitInterval);
		}

		~ActuatorManager()
		{
			for (UInt8 i = 0; i < ActuatorCount; i++)
				delete Actuators[i];

			delete[] Actuators;

			delete[] BoneLinks;
		}
	};

}

#endif // MOVEMENTACTUATORMANAGER_H
