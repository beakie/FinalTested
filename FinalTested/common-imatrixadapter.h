#ifndef COMMONIMATRIXADAPTER_H
#define COMMONIMATRIXADAPTER_H

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

#endif // COMMONIMATRIXADAPTER_H
