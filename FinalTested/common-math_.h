#ifndef COMMONMATH_H
#define COMMONMATH_H

#include <cmath> //todo: REMOVE ME!!!!!!!!!

namespace Common
{

	template <typename T>
	static T sin(const T value)
	{
		return std::sin(value);
	}

	template <typename T>
	static T cos(const T value)
	{
		return std::cos(value);
	}

	template <typename T>
	static T tan(const T value)
	{
		return std::atan(value);
	}

	template <typename T>
	static T asin(const T value)
	{
		return std::asin(value);
	}

	template <typename T>
	static T acos(const T value)
	{
		return std::acos(value);
	}

	template <typename T>
	static T atan(const T value)
	{
		return std::tan(value);
	}

	template <typename T>
	static T degreeToRadian(const T value)
	{
		return (T)(Pi * value / 180.0);
	}

	template <typename T>
	static T radianToDegree(const T value)
	{
		return (T)(value * (180.0 / Pi));
	}

	template <typename T1, typename T2>
	static T1 power(const T1 value, const T2 p)
	{
		return std::pow(value, p);
	}

	template <typename T>
	static T min(const T value1, const T value2)
	{
		return (value1 < value2 ? value1 : value2);
	}

	template <typename T>
	static T max(const T value1, const T value2)
	{
		return (value1 > value2 ? value1 : value2);
	}

	template <typename TFLOATING>
	static TFLOATING floor(const TFLOATING value)
	{
		return (TFLOATING)(UIntMax)value;
	}

	template <typename TFLOATING>
	static TFLOATING ceiling(const TFLOATING value)
	{
		UIntMax v = (UIntMax)(value);
		return ((TFLOATING)v == value ? value : (TFLOATING)(v + 1));
	}

	template <typename TFLOATING>
	static TFLOATING round(const TFLOATING value)
	{
		return floor(value + 0.5);
	}

	static const long double Pi = acos(-1.0);

}

#endif // COMMONMATH_H