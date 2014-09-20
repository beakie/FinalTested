#ifndef IMAGE_H
#define IMAGE_H

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

		template <typename T = TVALUE>
		static T getUpperBound();

		template <>
		static bool getUpperBound<bool>()
		{
			return 1;
		}

		template <>
		static unsigned char getUpperBound<unsigned char>()
		{
			return 255;
		}

		template <>
		static unsigned int getUpperBound<unsigned int>()
		{
			return 65535;
		}

		virtual ~Image()
		{
		}
	};
}

#endif // IMAGE_H
