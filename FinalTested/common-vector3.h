#ifndef COMMONVECTOR3_H
#define COMMONVECTOR3_H

namespace Common
{

template <typename TVALUE>
struct Vector3
{
    TVALUE Values[3];

    Vector3()
    {
    }

	Vector3(const Vector3<TVALUE>& vector)
	{
		Values[0] = vector.Values[0];
		Values[1] = vector.Values[1];
		Values[2] = vector.Values[2];
	}

	Vector3(TVALUE value)
	{
		Values[0] = value;
		Values[1] = value;
		Values[2] = value;
	}

	Vector3(TVALUE value1, TVALUE value2, TVALUE value3)
	{
		Values[0] = value1;
		Values[1] = value2;
		Values[2] = value3;
	}

	TVALUE dotProduct(const Vector3<TVALUE>& vector)
    {
		return (Values[0] * vector.Values[0] + Values[1] * vector.Values[1] + Values[2] * vector.Values[2]);
    }

	Vector3<TVALUE> crossProduct(const Vector3<TVALUE>& vector)
    {
		Vector3<TVALUE> v = Vector3<TVALUE>();
		v.Values[0] = (Values[1] * vector.Values[2] - Values[2] * vector.Values[1]);
		v.Values[1] = (Values[2] * vector.Values[0] - Values[0] * vector.Values[2]);
		v.Values[2] = (Values[0] * vector.Values[1] - Values[1] * vector.Values[0]);
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
		Values[0] += vector.Values[0];
		Values[1] += vector.Values[1];
		Values[2] += vector.Values[2];

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
		Values[0] -= vector.Values[0];
		Values[1] -= vector.Values[1];
		Values[2] -= vector.Values[2];

		return *this;
	}

	bool operator==(const Vector3<TVALUE>& vector)
	{
		return (vector.Values[0] == Values[0]) && (vector.Values[1] == Values[1]) && (vector.Values[2] == Values[2]);
	}

    virtual ~Vector3() { }
};

}

#endif // COMMONVECTOR3_H
