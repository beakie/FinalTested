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

		static TVALUE getUpperBound()
		{
			Image<TVALUE, TINDEX>* t;

			if (dynamic_cast<Image<bool, TINDEX>*> (t) != nullptr)
				return 1;
			if (dynamic_cast<Image<unsigned char, TINDEX>*> (t) != nullptr)
				return 255;
			if (dynamic_cast<Image<unsigned int, TINDEX>*> (t) != nullptr)
				return 65535;

				return 0;
		}
		
		virtual ~Image()
		{
		}
	};
}

#endif // IMAGE_H

template <typename TVALUE>
TVALUE getUpperBound()
{
	SomeStruct<TVALUE>* t = 0;

	if (dynamic_cast<SomeStruct<bool>*> (t) != nullptr)
		return 1;
	if (dynamic_cast<SomeStruct<unsigned char>*> (t) != nullptr)
		return 255;
	if (dynamic_cast<SomeStruct<unsigned int>*> (t) != nullptr)
		return 65535;

	return 0;
}
