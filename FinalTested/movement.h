#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "space2d.h"
#include "space3d.h"

#include "movement-skeletal.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-bonezerolist.h"

namespace Movement
{

	typedef JointList<Common::Matrix3F32> JointList2d32;
	typedef JointList<Common::Matrix3F64> JointList2d64;
	typedef JointList<Common::Matrix3F> JointList2d;

	typedef JointList<Common::Matrix4F32> JointList3d32;
	typedef JointList<Common::Matrix4F64> JointList3d64;
	typedef JointList<Common::Matrix4F> JointList3d;

	typedef BoneZeroList<Space2d::PlotF32> BoneZeroList2d32;
	typedef BoneZeroList<Space2d::PlotF64> BoneZeroList2d64;
	typedef BoneZeroList<Space2d::PlotF> BoneZeroList2d;

	typedef BoneZeroList<Space3d::CoordinateF32> BoneZeroList3d32;
	typedef BoneZeroList<Space3d::CoordinateF64> BoneZeroList3d64;
	typedef BoneZeroList<Space3d::CoordinateF> BoneZeroList3d;

	typedef Skeletal<Space2d::PlotF32, Common::Matrix3F32> Skeletal2d32;
	typedef Skeletal<Space2d::PlotF64, Common::Matrix3F64> Skeletal2d64;
	typedef Skeletal<Space2d::PlotF, Common::Matrix3F> Skeletal2d;

	typedef Skeletal<Space3d::CoordinateF32, Common::Matrix4F32> Skeletal3d32;
	typedef Skeletal<Space3d::CoordinateF64, Common::Matrix4F64> Skeletal3d64;
	typedef Skeletal<Space3d::CoordinateF, Common::Matrix4F> Skeletal3d;

}

#endif // MOVEMENT_H
