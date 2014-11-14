#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "space2d.h"
#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-doublepositionlist.h"
#include "movement-jointlist.h"
#include "movement-singlepositionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	typedef JointList<Common::Matrix3F32> JointList2d32;
	typedef JointList<Common::Matrix3F64> JointList2d64;
	typedef JointList<Common::Matrix3F> JointList2d;

	typedef JointList<Common::Matrix4F32> JointList3d32;
	typedef JointList<Common::Matrix4F64> JointList3d64;
	typedef JointList<Common::Matrix4F> JointList3d;

	typedef DoublePositionList<Space2d::PlotF32> DoublePositionList2d32;
	typedef DoublePositionList<Space2d::PlotF64> DoublePositionList2d64;
	typedef DoublePositionList<Space2d::PlotF> DoublePositionList2d;

	typedef DoublePositionList<Space3d::CoordinateF32> DoublePositionList3d32;
	typedef DoublePositionList<Space3d::CoordinateF64> DoublePositionList3d64;
	typedef DoublePositionList<Space3d::CoordinateF> DoublePositionList3d;

	typedef SinglePositionList<Space2d::PlotF32> SinglePositionList2d32;
	typedef SinglePositionList<Space2d::PlotF64> SinglePositionList2d64;
	typedef SinglePositionList<Space2d::PlotF> SinglePositionList2d;

	typedef SinglePositionList<Space3d::CoordinateF32> SinglePositionList3d32;
	typedef SinglePositionList<Space3d::CoordinateF64> SinglePositionList3d64;
	typedef SinglePositionList<Space3d::CoordinateF> SinglePositionList3d;

	typedef Skeletal<Space2d::PlotF32, Common::Matrix3F32> Skeletal2d32;
	typedef Skeletal<Space2d::PlotF64, Common::Matrix3F64> Skeletal2d64;
	typedef Skeletal<Space2d::PlotF, Common::Matrix3F> Skeletal2d;

	typedef Skeletal<Space3d::CoordinateF32, Common::Matrix4F32> Skeletal3d32;
	typedef Skeletal<Space3d::CoordinateF64, Common::Matrix4F64> Skeletal3d64;
	typedef Skeletal<Space3d::CoordinateF, Common::Matrix4F> Skeletal3d;

}

#endif // MOVEMENT_H
