#ifndef COMMONTYPES_H
#define COMMONTYPES_H

#include "common-math_.h"

namespace Common
{

	template <typename T>
	struct Nullable
	{
		bool HasValue;
		T Value;
	};

}

#endif // COMMONTYPES_H
