#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "space2d.h"
#include "space3d.h"

#include "movement-body.h"
#include "movement-bonemap.h"
#include "movement-jointlist.h"

namespace Movement
{

	typedef JointList<Common::Matrix3F32> JointList2d32;
	typedef JointList<Common::Matrix3F64> JointList2d64;
	typedef JointList<Common::Matrix3F> JointList2d;

	typedef JointList<Common::Matrix4F32> JointList3d32;
	typedef JointList<Common::Matrix4F64> JointList3d64;
	typedef JointList<Common::Matrix4F> JointList3d;

	typedef BoneMap<Space2d::PlotF32> BoneMap2d32;
	typedef BoneMap<Space2d::PlotF64> BoneMap2d64;
	typedef BoneMap<Space2d::PlotF> BoneMap2d;

	typedef BoneMap<Space3d::CoordinateF32> BoneMap3d32;
	typedef BoneMap<Space3d::CoordinateF64> BoneMap3d64;
	typedef BoneMap<Space3d::CoordinateF> BoneMap3d;

	typedef Body<Space2d::PlotF32, Common::Matrix3F32> Body2d32;
	typedef Body<Space2d::PlotF64, Common::Matrix3F64> Body2d64;
	typedef Body<Space2d::PlotF, Common::Matrix3F> Body2d;

	typedef Body<Space3d::CoordinateF32, Common::Matrix4F32> Body3d32;
	typedef Body<Space3d::CoordinateF64, Common::Matrix4F64> Body3d64;
	typedef Body<Space3d::CoordinateF, Common::Matrix4F> Body3d;

}

#endif // MOVEMENT_H
