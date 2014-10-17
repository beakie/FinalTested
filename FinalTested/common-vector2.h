#ifndef COMMONVECTOR2_H
#define COMMONVECTOR2_H

namespace Common
{

template <typename TVALUE>
struct Vector2
{
    TVALUE values[2];

	Vector2()
	{
	}

	Vector2(const Vector2<TVALUE>& vector)
	{
		values[0] = vector.values[0];
		values[1] = vector.values[1];
	}

	Vector2(TVALUE value)
	{
		values[0] = value;
		values[1] = value;
	}

    Vector2(TVALUE value1, TVALUE value2)
    {
		values[0] = value1;
		values[1] = value2;
    }

    TVALUE dotProduct(const Vector2<TVALUE>& vector)
    {
		return (values[0] * vector.values[0] + values[1] * vector.values[1]);
    }

	TVALUE crossProduct(const Vector2<TVALUE>& vector)
    {
		return (values[0] * vector.values[1]) - (values[1] * vector.values[0]);
    }

	Vector2<TVALUE>& operator=(const Vector2<TVALUE>& vector)
	{
		values[0] = vector.values[0];
		values[1] = vector.values[1];

		return *this;
	}

	Vector2<TVALUE> operator+(const Vector2<TVALUE>& vector) const
	{
		Vector2<TVALUE> v = *this;

		v += vector;

		return v;
	}

	Vector2<TVALUE>& operator+=(const Vector2<TVALUE>& vector)
	{
		values[0] += vector.values[0];
		values[1] += vector.values[1];

		return *this;
	}

	Vector2<TVALUE> operator-(const Vector2<TVALUE>& vector) const
	{
		Vector2<TVALUE> v = *this;

		v -= vector;

		return v;
	}

    Vector2<TVALUE> operator-=(const Vector2<TVALUE>& vector) const
    {
		values[0] -= vector.values[0];
		values[1] -= vector.values[1];

		return *this;
	}

    bool operator==(const Vector2<TVALUE>& vector)
    {
        return (vector.values[0] == values[0]) && (vector.values[1] == values[1]);
    }

    virtual ~Vector2() { }
};

}

#endif // COMMONVECTOR2_H
