#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "movement-body.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	typedef JointList<Common::Matrix4<Float32>> JointList3d32;
	typedef JointList<Common::Matrix4<Float64>> JointList3d64;
	typedef JointList<Common::Matrix4<FloatMax>> JointList3d;

	typedef JointList<Common::Matrix3<Float32>> JointList2d32;
	typedef JointList<Common::Matrix3<Float64>> JointList2d64;
	typedef JointList<Common::Matrix3<FloatMax>> JointList2d;

	typedef Body<FloatMax, Common::Matrix3<FloatMax>> Body3d;

}

#endif // MOVEMENT_H
