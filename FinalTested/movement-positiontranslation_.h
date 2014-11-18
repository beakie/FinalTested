#ifndef MOVEMENTPOSITIONTRANSLATION_H
#define MOVEMENTPOSITIONTRANSLATION_H

#include "space2d.h"
#include "space3d.h"

#include "movement-bonemap.h"
#include "movement-jointlist.h"
#include "movement-positionlist.h"
#include "movement-skeletal.h"

namespace Movement
{

	template <typename TPOINT, typename TMATRIX>
	PositionList<TPOINT> getTranslatedJoints(const JointList<TMATRIX>& jointList, const BoneMap& boneMap, const PositionList<TPOINT>& jointPositions)
	{
		PositionList<TPOINT> translatedJoints = PositionList<TPOINT>(jointPositions.PositionCount);

		//for (UInt8 i = 0; i < jointPositions.PositionCount; i++)
		//	translatedJoints.Positions[i] = jointPositions.Positions[i] * boneMap.getBoneTransformMatrix(jointList, i);

		return translatedJoints;
	}

	template <typename TVALUE>
	PositionList<Common::Vector2<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix3<TVALUE>>& jointList, const BoneMap& boneMap, const PositionList<Common::Vector2<TVALUE>>& jointPositions)
	{
		return getTranslatedJoints<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(jointList, boneMap, jointPositions);
	}

	template <typename TVALUE>
	PositionList<Common::Vector3<TVALUE>> getTranslatedJoints(const JointList<Common::Matrix4<TVALUE>>& jointList, const BoneMap& boneMap, const PositionList<Common::Vector3<TVALUE>>& jointPositions)
	{
		return getTranslatedJoints<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(jointList, boneMap, jointPositions);
	}
	
	template <typename TVALUE>
	PositionList<Common::Vector2<TVALUE>> getTranslatedJoints(const Skeletal<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>& skeletal)
	{
		return getTranslatedJoints<Common::Vector2<TVALUE>, Common::Matrix3<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

	template <typename TVALUE>
	PositionList<Common::Vector3<TVALUE>> getTranslatedJoints(const Skeletal<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>& skeletal)
	{
		return getTranslatedJoints<Common::Vector3<TVALUE>, Common::Matrix4<TVALUE>>(skeletal.Joints, skeletal.BoneMap, skeletal.ZeroPositions);
	}

}

#endif // MOVEMENTPOSITIONTRANSLATION_H
