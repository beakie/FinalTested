#include "common-math_.h"
#include "common-vector2.h"

template <typename TVALUE>
static Common::Vector2<TVALUE> abs(const Common::Vector2<TVALUE>& vector)
{
	return vector.getAbs();
}
