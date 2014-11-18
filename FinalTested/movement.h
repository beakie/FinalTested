#ifndef MOVEMENT_H
#define MOVEMENT_H

#include "space2d.h"
#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-doublepositionlist.h"
#include "movement-jointlist.h"
#include "movement-positiontranslation_.h"
#include "movement-positionlist.h"
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

	typedef PositionList<Space2d::PlotF32> PositionList2d32;
	typedef PositionList<Space2d::PlotF64> PositionList2d64;
	typedef PositionList<Space2d::PlotF> PositionList2d;

	typedef PositionList<Space3d::CoordinateF32> PositionList3d32;
	typedef PositionList<Space3d::CoordinateF64> PositionList3d64;
	typedef PositionList<Space3d::CoordinateF> PositionList3d;

	typedef PositionList<Space2d::PlotF32> JointPositionList2d32;
	typedef PositionList<Space2d::PlotF64> JointPositionList2d64;
	typedef PositionList<Space2d::PlotF> JointPositionList2d;

	typedef PositionList<Space3d::CoordinateF32> JointPositionList3d32;
	typedef PositionList<Space3d::CoordinateF64> JointPositionList3d64;
	typedef PositionList<Space3d::CoordinateF> JointPositionList3d;

	typedef DoublePositionList<Space2d::PlotF32> BonePositionList2d32;
	typedef DoublePositionList<Space2d::PlotF64> BonePositionList2d64;
	typedef DoublePositionList<Space2d::PlotF> BonePositionList2d;

	typedef DoublePositionList<Space3d::CoordinateF32> BonePositionList3d32;
	typedef DoublePositionList<Space3d::CoordinateF64> BonePositionList3d64;
	typedef DoublePositionList<Space3d::CoordinateF> BonePositionList3d;

	typedef Skeletal<Space2d::PlotF32, Common::Matrix3F32, PositionList<Space2d::PlotF32>> SkeletalJ2d32;
	typedef Skeletal<Space2d::PlotF64, Common::Matrix3F64, PositionList<Space2d::PlotF64>> SkeletalJ2d64;
	typedef Skeletal<Space2d::PlotF, Common::Matrix3F, PositionList<Space2d::PlotF>> SkeletalJ2d;

	typedef Skeletal<Space3d::CoordinateF32, Common::Matrix4F32, PositionList<Space3d::CoordinateF32>> SkeletalJ3d32;
	typedef Skeletal<Space3d::CoordinateF64, Common::Matrix4F64, PositionList<Space3d::CoordinateF64>> SkeletalJ3d64;
	typedef Skeletal<Space3d::CoordinateF, Common::Matrix4F, PositionList<Space3d::CoordinateF>> SkeletalJ3d;

	typedef Skeletal<Space2d::PlotF32, Common::Matrix3F32, DoublePositionList<Space2d::PlotF32>> SkeletalB2d32;
	typedef Skeletal<Space2d::PlotF64, Common::Matrix3F64, DoublePositionList<Space2d::PlotF64>> SkeletalB2d64;
	typedef Skeletal<Space2d::PlotF, Common::Matrix3F, DoublePositionList<Space2d::PlotF>> SkeletalB2d;

	typedef Skeletal<Space3d::CoordinateF32, Common::Matrix4F32, DoublePositionList<Space3d::CoordinateF32>> SkeletalB3d32;
	typedef Skeletal<Space3d::CoordinateF64, Common::Matrix4F64, DoublePositionList<Space3d::CoordinateF64>> SkeletalB3d64;
	typedef Skeletal<Space3d::CoordinateF, Common::Matrix4F, DoublePositionList<Space3d::CoordinateF>> SkeletalB3d;

	typedef SkeletalB2d32 Skeletal2d32;
	typedef SkeletalB2d64 Skeletal2d64;
	typedef SkeletalB2d Skeletal2d;

	typedef SkeletalB3d32 Skeletal3d32;
	typedef SkeletalB3d64 Skeletal3d64;
	typedef SkeletalB3d Skeletal3d;

}

#endif // MOVEMENT_H
