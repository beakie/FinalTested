#include "common-imatrix.h"

namespace Common
{

	template <typename TMATRIX, typename TVALUE, typename TINDEX>
	struct Matrix : TMATRIX, IMatrix<TVALUE, TINDEX, TMATRIX>
	{

	};

}
