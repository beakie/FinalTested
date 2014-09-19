#ifndef IMATRIXADAPTER_H
#define IMATRIXADAPTER_H

namespace Common
{
	template <typename TVALUE, typename TINDEX>
	struct IMatrixAdapter
	{
		/// <summary>
		/// Returns the number of rows
		/// </summary>
		TINDEX getRowCount();

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		TINDEX getColumnCount();

		virtual ~IMatrixAdapter()
		{
		}
	};
}

#endif // IMATRIXADAPTER_H
