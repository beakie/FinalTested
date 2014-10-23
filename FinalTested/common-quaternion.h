#ifndef COMMONQUATERNION_H
#define COMMONQUATERNION_H

#include "core.h"
#include "common-vector3.h"

namespace Common
{
	template <typename TVALUE = FloatMax>
	struct Quaternion
	{
		Vector3<TVALUE> Vector;
		TVALUE W;

		Quaternion()
		{
		}

		Quaternion(const Quaternion<TVALUE>& quaternion)
		{
			operator=(quaternion);
		}

		Quaternion(const Vector3<TVALUE>& vector, const TVALUE w)
		{
			Vector = vector;
			W = w;
		}

		Quaternion(const TVALUE x, const TVALUE y, const TVALUE z, const TVALUE w)
		{
			Vector.Values[0] = x;
			Vector.Values[1] = y;
			Vector.Values[2] = z;
			W = w;
		}

		Quaternion<TVALUE>& operator=(const Quaternion<TVALUE>& quaternion)
		{
			Vector = quaternion.Vector;
			W = quaternion.W;

			return *this;
		}

		Quaternion<TVALUE> operator*(const Quaternion<TVALUE>& quaternion) const
		{
			Quaternion<TVALUE> m = *this;

			m *= quaternion;

			return m;
		}

		Quaternion<TVALUE>& operator*=(const Quaternion<TVALUE>& quaternion)
		{
			return operator=(((W * quaternion.W) - (X * quaternion.X) - (Y * quaternion.Y) - (Z * quaternion.Z)),
								((W * quaternion.X) + (X * quaternion.W) + (Y * quaternion.Z) - (Z * quaternion.Y)),
								((W * quaternion.Y) - (X * quaternion.Z) + (Y * quaternion.W) + (Z * quaternion.X)),
								((W * quaternion.Z) + (X * quaternion.Y) - (Y * quaternion.X) + (Z * quaternion.W)))
		}

		virtual ~Quaternion()
		{
		}
	};
}

#endif // COMMONQUATERNION_H
