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

		TINDEX Width;
		TINDEX Height;

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
		Image(TINDEX width, TINDEX height)
		{
			Width = width;
			Height = height;
		}

		/// <summary>
		/// Constructs a image and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Image(TINDEX width, TINDEX height, const TVALUE value)
			: Image(width, height)
		{
			//todo
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		TINDEX getWidth() const
		{
			return Width;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		TINDEX getHeight() const
		{
			return Height;
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		bool validateX(const TINDEX x) const
		{
			return (x <= Width) && (x >= 0);
		}

		/// <summary>
		/// Returns ...
		/// </summary>
		bool validateY(const TINDEX y) const
		{
			return (y <= Height) && (y >= 0);
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
