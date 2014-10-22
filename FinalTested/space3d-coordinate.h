#ifndef SPACE3DCOORDINATE_H
#define SPACE3DCOORDINATE_H

#include "common.h"

namespace Space3d
{

	/// <summary>
	/// 1 byte precision signed coordinate
	/// </summary>
	typedef Common::Vector3<Int8> CoordinateI8;

	/// <summary>
	/// 2 byte precision signed coordinate
	/// </summary>
	typedef Common::Vector3<Int16> CoordinateI16;

	/// <summary>
	/// 4 byte precision signed coordinate
	/// </summary>
	typedef Common::Vector3<Int32> CoordinateI32;

	/// <summary>
	/// max byte precision signed coordinate
	/// </summary>
	typedef Common::Vector3<IntMax> CoordinateI;

	/// <summary>
	/// 1 byte precision unsigned coordinate
	/// </summary>
	typedef Common::Vector3<UInt8> CoordinateU8;

	/// <summary>
	/// 2 byte precision unsigned coordinate
	/// </summary>
	typedef Common::Vector3<UInt16> CoordinateU16;

	/// <summary>
	/// 4 byte precision unsigned coordinate
	/// </summary>
	typedef Common::Vector3<UInt32> CoordinateU32;

	/// <summary>
	/// max byte precision unsigned coordinate
	/// </summary>
	typedef Common::Vector3<UIntMax> CoordinateU;

	/// <summary>
	/// 4 byte precision floating number coordinate
	/// </summary>
	typedef Common::Vector3<Float32> CoordinateF32;

	/// <summary>
	/// 8 byte precision floating number coordinate
	/// </summary>
	typedef Common::Vector3<Float64> CoordinateF64;

	/// <summary>
	/// max byte precision floating number coordinate
	/// </summary>
	typedef Common::Vector3<FloatMax> CoordinateF;

	float distanceBetweenCoordinates(const Common::Vector3<FloatMax> &coordinate1, const Common::Vector3<FloatMax> &coordinate2)
	{
		return power(power(coordinate1.Values[0] - coordinate2.Values[0], 2) + power(coordinate1.Values[1] - coordinate2.Values[1], 2) + power(coordinate1.Values[2] - coordinate2.Values[2], 2), 0.5);
	}
}

#endif // SPACE3DCOORDINATE_H
