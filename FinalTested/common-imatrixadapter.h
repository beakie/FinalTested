#ifndef IMATRIXADAPTER_H
#define IMATRIXADAPTER_H

namespace Common
{
	template <typename TVALUE>
	struct IMatrixAdapter
	{
		/// <summary>
		/// Returns the number of rows
		/// </summary>
		unsigned char getRowCount();

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		unsigned char getColumnCount();

		virtual ~IMatrixAdapter()
		{
		}
	};
}

#endif // IMATRIXADAPTER_H
