#ifndef COMMONVECTOR2_H
#define COMMONVECTOR2_H

namespace Common
{

template <typename TVALUE>
struct Vector2
{
    TVALUE Values[2];

	Vector2()
	{
	}

	Vector2(const Vector2<TVALUE>& vector)
	{
		Values[0] = vector.Values[0];
		Values[1] = vector.Values[1];
	}

	Vector2(TVALUE value)
	{
		Values[0] = value;
		Values[1] = value;
	}

    Vector2(TVALUE value1, TVALUE value2)
    {
		Values[0] = value1;
		Values[1] = value2;
    }

    TVALUE dotProduct(const Vector2<TVALUE>& vector)
    {
		return (Values[0] * vector.Values[0] + Values[1] * vector.Values[1]);
    }

	TVALUE crossProduct(const Vector2<TVALUE>& vector)
    {
		return (Values[0] * vector.Values[1]) - (Values[1] * vector.Values[0]);
    }

	Vector2<TVALUE>& operator=(const Vector2<TVALUE>& vector)
	{
		Values[0] = vector.Values[0];
		Values[1] = vector.Values[1];

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
		Values[0] += vector.Values[0];
		Values[1] += vector.Values[1];

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
		Values[0] -= vector.Values[0];
		Values[1] -= vector.Values[1];

		return *this;
	}

    bool operator==(const Vector2<TVALUE>& vector)
    {
        return (vector.Values[0] == Values[0]) && (vector.Values[1] == Values[1]);
    }

    virtual ~Vector2() { }
};

}

#endif // COMMONVECTOR2_H
