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
	SinglePositionList<TPOINT> getTranslatedJoints(const JointList<TMATRIX>& jointList, const BoneMap& boneMap, const SinglePositionList<TPOINT>& jointPositions)
	{
		SinglePositionList<TPOINT> translatedJoints = SinglePositionList<TPOINT>(jointPositions.PositionCount);

		for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
			translatedJoints.Positions[i] = jointPositions.Positions[i] * boneMap.getBoneTransformMatrix(jointList, i);

		return translatedJoints;
	}

	template <typename TPOINT, typename TMATRIX>
	DoublePositionList<TPOINT> getTranslatedBones(const JointList<TMATRIX>& jointList, const BoneMap& boneMap, const SinglePositionList<TPOINT>& jointPositions)
	{
		DoublePositionList<TPOINT> translatedBones = DoublePositionList<TPOINT>(jointPositions.PositionCount);

		for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
		{
			translatedBones.FromPositions[i] = jointPositions.Positions[i] * boneMap.getBoneTransformMatrix(jointList, i);

			if (i == 0)
				translatedBones.ToPositions[i] = TPOINT::getZero();
			else
				translatedBones.ToPositions[i] = translatedBones.FromPositions[i - 1];

		}

		return translatedBones;
	}

	template <typename TPOINT, typename TMATRIX>
	DoublePositionList<TPOINT> getTranslatedBones(const JointList<TMATRIX>& jointList, const BoneMap& boneMap, const DoublePositionList<TPOINT>& bonePositions)
	{
		DoublePositionList<TPOINT> translatedBones = DoublePositionList<TPOINT>(bonePositions.PositionCount);

		for (UInt8 i = 0; i < bonePositions.PositionCount; i++)
		{
			TMATRIX matrix = boneMap.getBoneTransformMatrix(jointList, i);

			translatedBones.FromPositions[i] = bonePositions.FromPositions[i] * matrix;
			translatedBones.ToPositions[i] = bonePositions.ToPositions[i] * matrix;

			// this needs to deal with matrix4. use Space3d::multiplyCoordinateByMatrix() or Space2d::multiplyPlotByMatrix()
			// this (and above) will probably need splitting into 2 sets of 3 seperate functions.
		}

		return translatedBones;
	}

	template <typename TVALUE>
	SinglePositionList<Common::Vector2<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const SinglePositionList<Common::Vector2<TVALUE>>& jointPositions)
	{
		return getTranslatedJoints<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, jointPositions);
	}

	template <typename TVALUE>
	SinglePositionList<Common::Vector3<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const SinglePositionList<Common::Vector3<TVALUE>>& jointPositions)
	{
		return getTranslatedJoints<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, jointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const SinglePositionList<Common::Vector2<TVALUE>>& jointPositions)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, jointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const SinglePositionList<Common::Vector3<TVALUE>>& jointPositions)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, jointPositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector2<TVALUE>> getTranslatedBones(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const DoublePositionList<Common::Vector2<TVALUE>>& bonePositions)
	{
		return getTranslatedBones<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, bonePositions);
	}

	template <typename TVALUE>
	DoublePositionList<Common::Vector3<TVALUE>> getTranslatedBones(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const DoublePositionList<Common::Vector3<TVALUE>>& bonePositions)
	{
		return getTranslatedBones<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, bonePositions);
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
