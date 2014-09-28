#ifndef COMMONIMATRIXADAPTER_H
#define COMMONIMATRIXADAPTER_H

#include "core.h"

namespace Common
{
	template <typename TVALUE>
	struct IMatrixAdapter
	{
		/// <summary>
		/// Returns the number of rows
		/// </summary>
		UInt_8 getRowCount();

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		UInt_8 getColumnCount();

		virtual ~IMatrixAdapter()
		{
		}
	};
}

#endif // COMMONIMATRIXADAPTER_H
