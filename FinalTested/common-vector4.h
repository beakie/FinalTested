#ifndef COMMONVECTOR4_H
#define COMMONVECTOR4_H

#include "common-matrix4.h"

namespace Common
{

template <typename TVALUE>
struct Vector4
{
    TVALUE values[4];

    Vector4()
    {
    }

	Vector4(const Vector4<TVALUE>& vector)
	{
		values[0] = vector.values[0];
		values[1] = vector.values[1];
		values[2] = vector.values[2];
		values[3] = vector.values[3];
	}

	Vector4(TVALUE value)
	{
		values[0] = value;
		values[1] = value;
		values[2] = value;
		values[3] = value;
	}

	Vector4(TVALUE value1, TVALUE value2, TVALUE value3, TVALUE value4)
    {
		values[0] = value1;
		values[1] = value2;
		values[2] = value3;
		values[3] = value4;
    }

	TVALUE dotProduct(const Vector4<TVALUE> &vector)
    {
		return (values[0] * vector.values[0] + values[1] * vector.values[1] + values[2] * vector.values[2] + values[3] * vector.values[3]);
    }

	Vector4<TVALUE> crossProduct(const Vector4<TVALUE> &vector)
    {
        // todo
        Vector4<TVALUE> vector;
        return vector;
    }

	Vector4<TVALUE> operator+(const Vector4<TVALUE>& vector) const
	{
		Vector4<TVALUE> v = *this;

		v += vector;

		return v;
	}

	Vector4<TVALUE>& operator+=(const Vector4<TVALUE>& vector)
	{
		values[0] += vector.values[0];
		values[1] += vector.values[1];
		values[2] += vector.values[2];
		values[3] += vector.values[3];

		return *this;
	}

	Vector4<TVALUE> operator-(const Vector4<TVALUE>& vector) const
	{
		Vector4<TVALUE> v = *this;

		v -= vector;

		return v;
	}

	Vector4<TVALUE> operator-=(const Vector4<TVALUE>& vector) const
	{
		values[0] -= vector.values[0];
		values[1] -= vector.values[1];
		values[2] -= vector.values[2];
		values[3] -= vector.values[3];

		return *this;
	}

	bool operator==(const Vector4<TVALUE>& vector)
	{
		return (vector.values[0] == values[0]) && (vector.values[1] == values[1]) && (vector.values[2] == values[2]) && (vector.values[3] == values[3]);
	}

    virtual ~Vector4() { }
};

}

#endif // COMMONVECTOR4_H
