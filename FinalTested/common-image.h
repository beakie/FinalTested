#ifndef IMAGE_H
#define IMAGE_H

#include "common-static.h"

namespace Common
{
	template <typename TVALUE, typename TINDEX>
	struct Image
	{
		/// <summary>
		/// The values of the image stored in [x][y] form
		/// </summary>
		TVALUE** Values;

		/// <summary>
		/// Constructs an unpopulated image
		/// </summary>
		Image()
		{
			//todo
		}

		/// <summary>
		/// Constructs an unpopulated image
		/// </summary>
		Image(TINDEX rows, TINDEX columns)
		{
			//todo
		}

		/// <summary>
		/// Constructs a image and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Image(TINDEX rows, TINDEX columns, const TVALUE value)
			: Image(rows, columns)
		{
			//todo
		}

		/// <summary>
		/// Returns the number of rows
		/// </summary>
		TINDEX getRowCount()
		{
			//todo
		}

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		TINDEX getColumnCount()
		{
			//todo
		}

		static TVALUE getMaxValue()
		{
			return Common::getUpperBound<TVALUE>();
		}

		virtual ~Image()
		{
		}
	};
}

#endif // IMAGE_H
