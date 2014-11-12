#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "space2d.h"
#include "space3d.h"

#include "movement-body.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	typedef JointList<Common::Matrix4F32> JointList3d32;
	typedef JointList<Common::Matrix4F64> JointList3d64;
	typedef JointList<Common::Matrix4F> JointList3d;

	typedef JointList<Common::Matrix3F32> JointList2d32;
	typedef JointList<Common::Matrix3F64> JointList2d64;
	typedef JointList<Common::Matrix3F> JointList2d;

	typedef Skeletal<Space2d::PlotF32> Skeletal2d32;
	typedef Skeletal<Space2d::PlotF64> Skeletal2d64;
	typedef Skeletal<Space2d::PlotF> Skeletal2d;

	typedef Skeletal<Space3d::CoordinateF32> Skeletal3d32;
	typedef Skeletal<Space3d::CoordinateF64> Skeletal3d64;
	typedef Skeletal<Space3d::CoordinateF> Skeletal3d;

	typedef Body<Space3d::CoordinateF32, Common::Matrix3F32> Body3d32;
	typedef Body<Space3d::CoordinateF64, Common::Matrix3F64> Body3d64;
	typedef Body<Space3d::CoordinateF, Common::Matrix3F> Body3d;

}

#endif // MOVEMENT_H
