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

		for (UInt8 i = 0; i < boneMap.BoneCount; i++)
			if (boneMap.ParentBones[i] == i)
				boneList.add({ *positionList.Positions[i], Common::Vector2<TVALUE>::getZero() });
			else
				boneList.add({ *positionList.Positions[i], *positionList.Positions[boneMap.ParentBones[i]] });

		return boneList;
	}

	template <typename TVALUE>
	Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> getJointToJointBones(Movement::PositionList<Common::Vector3<TVALUE>> positionList, Movement::BoneMap boneMap)
	{
		Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8> boneList = Common::ManagedList<Space3d::LineSegment3d<TVALUE>, UInt8>();

		for (UInt8 i = 0; i < boneMap.BoneCount; i++)
			if (boneMap.ParentBones[i] == i)
				boneList.add({ *positionList.Positions[i], Common::Vector3<TVALUE>::getZero() });
			else
				boneList.add({ *positionList.Positions[i], *positionList.Positions[boneMap.ParentBones[i]] });

		return boneList;
	}
}

#endif // BODYRENDERRENDERBONES_H
