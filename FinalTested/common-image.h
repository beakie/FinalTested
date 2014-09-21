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
		/// Returns ...
		/// </summary>
		TINDEX getWidth() const
		{
			return X2 - x1;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		TINDEX getHeight() const
		{
			return Y2 - y1;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		bool validateX(const TINDEX x) const
		{
			return (X1 >= x) && (X2 <= x);
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		bool validateY(const TINDEX y) const
		{
			return (Y1 >= y) && (Y2 <= y);
		}

		/// <summary>
		/// Returns ...
		/// </summary>
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
