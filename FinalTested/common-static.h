#ifndef COMMONSTATIC_H
#define COMMONSTATIC_H

#include "core-types.h"

namespace Common
{
	template <typename T>
	static T getUpperBound();

	template <typename T>
	static T getLowerBound();

	template <>
	static UInt_2 getLowerBound<UInt_2>()
	{
		return 0;
	}

	template <>
	static UInt_2 getUpperBound<UInt_2>()
	{
		return 1;
	}

	template <>
	static Int_8 getLowerBound<Int_8>()
	{
		return -127;
	}

	template <>
	static Int_8 getUpperBound<Int_8>()
	{
		return 127;
	}

	template <>
	static UInt_8 getLowerBound<UInt_8>()
	{
		return 0;
	}

	template <>
	static UInt_8 getUpperBound<UInt_8>()
	{
		return 255;
	}

	template <>
	static Int_16 getLowerBound<Int_16>()
	{
		return -65535;
	}

	template <>
	static Int_16 getUpperBound<Int_16>()
	{
		return 65535;
	}

	template <>
	static UInt_16 getLowerBound<UInt_16>()
	{
		return 65535;
	}

	template <>
	static UInt_16 getUpperBound<UInt_16>()
	{
		return 65535;
	}

	template <>
	static Int_32 getLowerBound<Int_32>()
	{
		return 65535;
	}

	template <>
	static Int_32 getUpperBound<Int_32>()
	{
		return 65535;
	}

	template <>
	static UInt_32 getLowerBound<UInt_32>()
	{
		return 65535;
	}

	template <>
	static UInt_32 getUpperBound<UInt_32>()
	{
		return 65535;
	}
}

#endif // COMMONSTATIC_H
