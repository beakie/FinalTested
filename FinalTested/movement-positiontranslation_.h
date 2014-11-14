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
	SinglePositionList<TPOINT> getTranslatedJoints(const JointList<TMATRIX>& jointList, const BoneMap& boneMap, const SinglePositionList<TPOINT>& zeroJointPositions)
	{
		SinglePositionList<TPOINT> translatedJoints = SinglePositionList<TPOINT>(zeroJointPositions.PositionCount);

		return translatedJoints;
	}

	template <typename TPOINT, typename TMATRIX>
	DoublePositionList<TPOINT> getTranslatedBones(const JointList<TMATRIX>& jointList, const BoneMap& boneMap, const SinglePositionList<TPOINT>& zeroJointPositions)
	{
		DoublePositionList<TPOINT> translatedBones = DoublePositionList<TPOINT>(zeroJointPositions.PositionCount);

		return translatedBones;
	}

	template <typename TPOINT, typename TMATRIX>
	DoublePositionList<TPOINT> getTranslatedBones(const JointList<TMATRIX>& jointList, const BoneMap& boneMap, const DoublePositionList<TPOINT>& zeroBonePositions)
	{
		DoublePositionList<TPOINT> translatedBones = DoublePositionList<TPOINT>(zeroBonePositions.PositionCount);

		return translatedBones;
	}

	template <typename TVALUE>
	SinglePositionList<Common::Vector2<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const SinglePositionList<Common::Vector2<TVALUE>>& zeroJointPositions)
	{
		return getTranslatedJoints<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, zeroJointPositions);
	}

	template <typename TVALUE>
	SinglePositionList<Common::Vector3<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const SinglePositionList<Common::Vector3<TVALUE>>& zeroJointPositions)
	{
		return getTranslatedJoints<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, zeroJointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const SinglePositionList<Common::Vector2<TVALUE>>& zeroJointPositions)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, zeroJointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const SinglePositionList<Common::Vector3<TVALUE>>& zeroJointPositions)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, zeroJointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const DoublePositionList<Common::Vector2<TVALUE>>& zeroBonePositions)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, zeroBonePositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const DoublePositionList<Common::Vector3<TVALUE>>& zeroBonePositions)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, zeroBonePositions);
	}
	
	template <typename TVALUE>
	SinglePositionList<Common::Vector2<TVALUE>> getTranslatedJoints(const Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>, SinglePositionList<Common::Vector2<TVALUE>>>& skeletal)
	{
		return getTranslatedJoints<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(const Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>, SinglePositionList<Common::Vector2<TVALUE>>>& skeletal)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(const Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>, DoublePositionList<Common::Vector2<TVALUE>>>& skeletal)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	SinglePositionList<Common::Vector3<TVALUE>> getTranslatedJoints(const Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>, SinglePositionList<Common::Vector3<TVALUE>>>& skeletal)
	{
		return getTranslatedJoints<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(const Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>, SinglePositionList<Common::Vector3<TVALUE>>>& skeletal)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(const Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>, DoublePositionList<Common::Vector3<TVALUE>>>& skeletal)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

}

#endif // MOVEMENTPOSITIONTRANSLATION_H
