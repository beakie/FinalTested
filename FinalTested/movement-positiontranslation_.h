#ifndef MOVEMENTPOSITIONTRANSLATION_H
#define MOVEMENTPOSITIONTRANSLATION_H

#include "space2d.h"
#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-doublepositionlist.h"
#include "movement-jointlist.h"
#include "movement-singlepositionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	template <typename TPOINT, typename TMATRIX>
	SinglePositionList<TPOINT> getTranslatedJoints(JointList<TMATRIX> jointList, BoneMap boneMap, SinglePositionList<TPOINT> zeroJointPositions)
	{
		return SinglePositionList<TPOINT>();
	}

	template <typename TPOINT, typename TMATRIX>
	DoublePositionList<TPOINT> getTranslatedBones(JointList<TMATRIX> jointList, BoneMap boneMap, SinglePositionList<TPOINT> zeroJointPositions)
	{
		return DoublePositionList<TPOINT>();
	}

	template <typename TPOINT, typename TMATRIX>
	DoublePositionList<TPOINT> getTranslatedBones(JointList<TMATRIX> jointList, BoneMap boneMap, DoublePositionList<TPOINT> zeroBonePositions)
	{
		return DoublePositionList<TPOINT>();
	}

	template <typename TVALUE>
	SinglePositionList<Common::Vector2<TVALUE>> getTranslatedJoints(JointList<Common::Matrix3<TVALUE>> jointList, BoneMap boneMap, SinglePositionList<Common::Vector2<TVALUE>> zeroJointPositions)
	{
		return getTranslatedJoints<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, zeroJointPositions);
	}

	template <typename TVALUE>
	SinglePositionList<Common::Vector3<TVALUE>> getTranslatedJoints(JointList<Common::Matrix4<TVALUE>> jointList, BoneMap boneMap, SinglePositionList<Common::Vector3<TVALUE>> zeroJointPositions)
	{
		return getTranslatedJoints<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, zeroJointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(JointList<Common::Matrix3<TVALUE>> jointList, BoneMap boneMap, SinglePositionList<Common::Vector2<TVALUE>> zeroJointPositions)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, zeroJointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(JointList<Common::Matrix4<TVALUE>> jointList, BoneMap boneMap, SinglePositionList<Common::Vector3<TVALUE>> zeroJointPositions)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, zeroJointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(JointList<Common::Matrix3<TVALUE>> jointList, BoneMap boneMap, DoublePositionList<Common::Vector2<TVALUE>> zeroBonePositions)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, zeroBonePositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(JointList<Common::Matrix4<TVALUE>> jointList, BoneMap boneMap, DoublePositionList<Common::Vector3<TVALUE>> zeroBonePositions)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, zeroBonePositions);
	}
	
	template <typename TVALUE>
	SinglePositionList<Common::Vector2<TVALUE>> getTranslatedJoints(Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>, SinglePositionList<Common::Vector2<TVALUE>>> skeletal)
	{
		return getTranslatedJoints<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>, SinglePositionList<Common::Vector2<TVALUE>>> skeletal)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>, DoublePositionList<Common::Vector2<TVALUE>>> skeletal)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	SinglePositionList<Common::Vector3<TVALUE>> getTranslatedJoints(Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>, SinglePositionList<Common::Vector3<TVALUE>>> skeletal)
	{
		return getTranslatedJoints<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>, SinglePositionList<Common::Vector3<TVALUE>>> skeletal)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>, DoublePositionList<Common::Vector3<TVALUE>>> skeletal)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

}

#endif // MOVEMENTPOSITIONTRANSLATION_H
