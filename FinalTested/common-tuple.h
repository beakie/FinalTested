#ifndef COMMONTUPLE_H
#define COMMONTUPLE_H

#include "core.h"

namespace Common
{
	template <typename T1 = FloatMax>
	struct Tuple1
	{
		T1 Item1;

		Tuple1(const T1 item1)
		{
			Item1 = item1;
		}
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax>
	struct Tuple2
	{
		T1 Item1;
		T2 Item2;

		Tuple2(const T1 item1, const T2 item2)
		{
			Item1 = item1;
			Item2 = item2;
		}
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax>
	struct Tuple3
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;

		Tuple3(const T1 item1, const T2 item2, const T3 item3)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
		}
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax>
	struct Tuple4
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;

		Tuple4(const T1 item1, const T2 item2, const T3 item3, const T4 item4)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
		}
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax, typename T5 = FloatMax>
	struct Tuple5
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;

		Tuple5(const T1 item1, const T2 item2, const T3 item3, const T4 item4, const T5 item5)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
			Item5 = item5;
		}
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax, typename T5 = FloatMax, typename T6 = FloatMax>
	struct Tuple6
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
		T6 Item6;

		Tuple6(const T1 item1, const T2 item2, const T3 item3, const T4 item4, const T5 item5, const T6 item6)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
			Item5 = item5;
			Item6 = item6;
		}
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax, typename T5 = FloatMax, typename T6 = FloatMax, typename T7 = FloatMax>
	struct Tuple7
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
		T6 Item6;
		T7 Item7;

		Tuple7(const T1 item1, const T2 item2, const T3 item3, const T4 item4, const T5 item5, const T6 item6, const T7 item7)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
			Item5 = item5;
			Item6 = item6;
			Item7 = item7;
		}
	};

	template <typename T1 = FloatMax, typename T2 = FloatMax, typename T3 = FloatMax, typename T4 = FloatMax, typename T5 = FloatMax, typename T6 = FloatMax, typename T7 = FloatMax, typename T8 = FloatMax>
	struct Tuple8
	{
		T1 Item1;
		T2 Item2;
		T3 Item3;
		T4 Item4;
		T5 Item5;
		T6 Item6;
		T7 Item7;
		T8 Item8;

		Tuple8(const T1 item1, const T2 item2, const T3 item3, const T4 item4, const T5 item5, const T6 item6, const T7 item7, const T8 item8)
		{
			Item1 = item1;
			Item2 = item2;
			Item3 = item3;
			Item4 = item4;
			Item5 = item5;
			Item6 = item6;
			Item7 = item7;
			Item8 = item8;
		}
	};
}

#endif // COMMONTUPLE_H
