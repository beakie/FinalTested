#ifndef COMMONQUATERNION_H
#define COMMONQUATERNION_H

#include "core.h"

namespace Common
{
	template <typename TVALUE>
	struct Quaternion
	{
		Vector3<TVALUE> Vector;
		TVALUE W;

		Quaternion<TVALUE>& operator*(const Quaternion &quaternion) const
		{
			//quanternion.W = ((W * quaternion.W) - (X * quaternion.X) - (Y * quaternion.Y) - (Z * quaternion.Z));
			//quanternion.X = ((W * quaternion.X) + (X * quaternion.W) + (Y * quaternion.Z) - (Z * quaternion.Y));
			//quanternion.Y = ((W * quaternion.Y) - (X * quaternion.Z) + (Y * quaternion.W) + (Z * quaternion.X));
			//quanternion.Z = ((W * quaternion.Z) + (X * quaternion.Y) - (Y * quaternion.X) + (Z * quaternion.W));

			return *this;
		}
	};
}

#endif // COMMONQUATERNION_H
