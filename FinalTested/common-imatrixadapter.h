#ifndef COMMONIMATRIXADAPTER_H
#define COMMONIMATRIXADAPTER_H

#include "core.h"

namespace Common
{
	template <typename TVALUE>
	/// <summary>
	/// Matrix adapter interface
	/// </summary>
	struct IMatrixAdapter
	{
		/// <summary>
		/// Returns the number of rows
		/// </summary>
		UInt8 getRowCount();

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		UInt8 getColumnCount();

		virtual ~IMatrixAdapter()
		{
		}
	};
}

#endif // COMMONIMATRIXADAPTER_H
