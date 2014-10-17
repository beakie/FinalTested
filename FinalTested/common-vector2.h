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

    Vector2(TVALUE a, TVALUE b)
    {
        values[0] = a;
        values[1] = b;
    }

    TVALUE dotProduct(const Vector2<TVALUE> &v)
    {
        return (values[0] * v.values[0] + values[1] * v.values[1]);
    }

    TVALUE crossProduct(const Vector2<TVALUE> &v)
    {
        return (values[0] * v.values[1]) - (values[1] * v.values[0]);
    }

    Vector2<TVALUE> operator+(const Vector2<TVALUE> &vector) const
    {
		Vector2<TVALUE> v;
        
		v.values[0] = vector.values[0] + values[0];
		v.values[1] = vector.values[1] + values[1];

         return v;
    }

    Vector2<TVALUE> operator-(const Vector2<TVALUE> &vector) const
    {
		Vector2<TVALUE> v;

		v.values[0] = vector.values[0] - values[0];
		v.values[1] = vector.values[1] - values[1];

         return v;
    }

    Vector2<TVALUE> & operator=(const Vector2<TVALUE> &vector)
    {
        values[0] = vector.values[0];
        values[1] = vector.values[1];

        return *this;
    }

    bool operator==(const Vector2<TVALUE> &vector)
    {
        return (vector.values[0] == values[0]) && (vector.values[1] == values[1]);
    }

    virtual ~Vector2() { }
};

}

#endif // COMMONVECTOR2_H
