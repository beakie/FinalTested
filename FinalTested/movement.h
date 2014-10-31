#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "movement-bone.h"
#include "movement-actuatormanager.h"
#include "movement-cachedactuator.h"
#include "movement-iactuator.h"
#include "movement-linearactuator.h"
#include "movement-rotatingactuator.h"
#include "movement-skeletal.h"

namespace Movement
{
	typedef ActuatorManager<Float32, Common::UnitInterval32> ActuatorManager32;

	typedef ActuatorManager<Float64, Common::UnitInterval64> ActuatorManager64;

	typedef ActuatorManager<FloatMax, Common::UnitIntervalMax> ActuatorManagerF;

	typedef LinearActuator<Float32, Common::UnitInterval32> LinearActuator32;

	typedef LinearActuator<Float64, Common::UnitInterval64> LinearActuator64;

	typedef LinearActuator<FloatMax, Common::UnitIntervalMax> LinearActuatorF;

	typedef RotatingActuator<Float32, Common::UnitInterval32> RotatingActuator32;

	typedef RotatingActuator<Float64, Common::UnitInterval64> RotatingActuator64;

	typedef RotatingActuator<FloatMax, Common::UnitIntervalMax> RotatingActuatorF;

	typedef Skeletal<Float32> Skeletal32;

	typedef Skeletal<Float64> Skeletal64;

	typedef Skeletal<FloatMax> SkeletalF;

}

#endif // MOVEMENT_H
