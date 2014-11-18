#ifndef BODYRENDERRENDERBONES_H
#define BODYRENDERRENDERBONES_H

#include "movement.h"

namespace BodyRender
{
	template <typename TVALUE>
	Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8> getJointToJointBones(Movement::Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>> skeletal)
	{
		return getJointToJointBones(Movement::getTranslatedJoints(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions), skeletal.BoneMap);
	}

	template <typename TVALUE>
	Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> getJointToJointBones(Movement::Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>> skeletal)
	{
		return getJointToJointBones(Movement::getTranslatedJoints(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions), skeletal.BoneMap);
	}

	template <typename TVALUE>
	Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8> getJointToJointBones(Movement::PositionList<Common::Vector2<TVALUE>> positionList, Movement::BoneMap boneMap)
	{
		Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8> boneList = Common::ManagedList<Space2d::LineSegment2d<TVALUE>, UInt8>();

		return boneList;
	}

	template <typename TVALUE>
	Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> getJointToJointBones(Movement::PositionList<Common::Vector3<TVALUE>> positionList, Movement::BoneMap boneMap)
	{
		Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> boneList = Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8>();

		return boneList;
	}
}

#endif // BODYRENDERRENDERBONES_H
