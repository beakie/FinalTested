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

	Vector4(TVALUE w, TVALUE x, TVALUE y, TVALUE z)
    {
        values[0] = w;
        values[1] = x;
        values[2] = y;
        values[3] = z;
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

    Vector4<TVALUE> operator+(const Vector4<TVALUE> &vector) const
    {
		Vector4<TVALUE> v;
		
		v.values[0] = values[0] + vector.values[0];
		v.values[1] = values[1] + vector.values[1];
		v.values[2] = values[2] + vector.values[2];
		v.values[3] = values[3] + vector.values[3];

         return v;
    }

    Vector4<TVALUE> operator-(const Vector4<TVALUE> &vector) const
    {
		Vector4<TVALUE> v;

        v.values[0] = values[0] - vector.values[0];
		v.values[1] = values[1] - vector.values[1];
		v.values[2] = values[2] - vector.values[2];
		v.values[3] = values[3] - vector.values[3];

         return v;
    }

    Vector4<TVALUE> & operator=(const Vector4<TVALUE> &vector)
    {
        values[0] = vector.values[0];
        values[1] = vector.values[1];
        values[2] = vector.values[2];
        values[3] = vector.values[3];

        return *this;
    }

    bool operator==(const Vector4<TVALUE> &vector)
    {
        return (vector.values[0] == values[0]) && (vector.values[1] == values[1]) && (vector.values[2] == values[2]) && (vector.values[3] == values[3]);
    }

    virtual ~Vector4() { }

    Vector4<TVALUE> operator*(const Matrix4<TVALUE> &matrix) const
    {
        // todo

		return Vector4<TVALUE>();
    }
};

}

#endif // COMMONVECTOR4_H
