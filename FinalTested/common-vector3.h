#ifndef COMMONVECTOR3_H
#define COMMONVECTOR3_H

namespace Common
{

template <typename TVALUE>
struct Vector3
{
    TVALUE values[3];

    Vector3()
    {
    }

	Vector3(const Vector3<TVALUE>& vector)
	{
		values[0] = vector.values[0];
		values[1] = vector.values[1];
		values[2] = vector.values[2];
	}

	Vector3(TVALUE value)
	{
		values[0] = value;
		values[1] = value;
		values[2] = value;
	}

	Vector3(TVALUE value1, TVALUE value2, TVALUE value3)
	{
		values[0] = value1;
		values[1] = value2;
		values[2] = value3;
	}

	TVALUE dotProduct(const Vector3<TVALUE>& vector)
    {
		return (values[0] * vector.values[0] + values[1] * vector.values[1] + values[2] * vector.values[2]);
    }

	Vector3<TVALUE> crossProduct(const Vector3<TVALUE>& vector)
    {
		Vector3<TVALUE> v = Vector3<TVALUE>();
		v.values[0] = (values[1] * vector.values[2] - values[2] * vector.values[1]);
		v.values[1] = (values[2] * vector.values[0] - values[0] * vector.values[2]);
		v.values[2] = (values[0] * vector.values[1] - values[1] * vector.values[0]);
        return vector;
    }

	Vector3<TVALUE> operator+(const Vector3<TVALUE>& vector) const
	{
		Vector3<TVALUE> v = *this;

		v += vector;

		return v;
	}

	Vector3<TVALUE>& operator+=(const Vector3<TVALUE>& vector)
	{
		values[0] += vector.values[0];
		values[1] += vector.values[1];
		values[2] += vector.values[2];

		return *this;
	}

	Vector3<TVALUE> operator-(const Vector3<TVALUE>& vector) const
	{
		Vector3<TVALUE> v = *this;

		v -= vector;

		return v;
	}

	Vector3<TVALUE> operator-=(const Vector3<TVALUE>& vector) const
	{
		values[0] -= vector.values[0];
		values[1] -= vector.values[1];
		values[2] -= vector.values[2];

		return *this;
	}

	bool operator==(const Vector3<TVALUE>& vector)
	{
		return (vector.values[0] == values[0]) && (vector.values[1] == values[1]) && (vector.values[2] == values[2]);
	}

    virtual ~Vector3() { }
};

}

#endif // COMMONVECTOR3_H
