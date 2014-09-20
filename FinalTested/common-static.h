#ifndef COMMONSTATIC_H
#define COMMONSTATIC_H

namespace Common
{
	template <typename T>
	static T getUpperBound();

	template <typename T>
	static T getLowerBound();

	template <>
	static bool getLowerBound<bool>()
	{
		return 0;
	}

	template <>
	static bool getUpperBound<bool>()
	{
		return 1;
	}

	template <>
	static char getLowerBound<char>()
	{
		return 127;
	}

	template <>
	static char getUpperBound<char>()
	{
		return 127;
	}

	template <>
	static unsigned char getLowerBound<unsigned char>()
	{
		return 255;
	}

	template <>
	static unsigned char getUpperBound<unsigned char>()
	{
		return 255;
	}

	template <>
	static int getLowerBound<int>()
	{
		return 65535;
	}

	template <>
	static int getUpperBound<int>()
	{
		return 65535;
	}

	template <>
	static unsigned int getLowerBound<unsigned int>()
	{
		return 65535;
	}

	template <>
	static unsigned int getUpperBound<unsigned int>()
	{
		return 65535;
	}
}

#endif // COMMONSTATIC_H
