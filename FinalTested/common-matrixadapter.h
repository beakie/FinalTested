#ifndef MATRIXADAPTER_H
#define MATRIXADAPTER_H

#include "common-imatrixadapter.h"

namespace Common
{
	template <typename TMATRIX, typename TVALUE, typename TINDEX>
	struct MatrixAdapter : private TMATRIX, IMatrixAdapter<TVALUE, TINDEX>
	{
		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		MatrixAdapter() : TMATRIX()
		{
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		MatrixAdapter(const TVALUE value) : TMATRIX(value)
		{
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		void set(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			operator =(matrix);
		}

		/// <summary>
		/// Gets the value
		/// </summary>
		TVALUE get(const unsigned char x, const unsigned char y)
		{
			return TMATRIX::get(x, y);
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator =(const TVALUE& value)
		{
			TMATRIX::operator =(value);
			
			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator =(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			// do manually. consider matrix size.

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator +(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			// do manually. consider matrix size.

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator +=(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			operator +=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator -(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			// do manually. consider matrix size.

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator -=(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			operator -=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator *(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			// do manually. consider matrix size.

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator *=(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			operator *=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator *(const TVALUE value) const
		{
			TMATRIX::operator *(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator *=(const TVALUE value)
		{
			operator *=(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator /(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			// do manually. consider matrix size.

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator /=(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			operator /=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator /(const TVALUE value) const
		{
			// do manually. consider matrix size.

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator /=(const TVALUE value)
		{
			operator /=(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator ==(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			// do manually. consider matrix size.

			return false;
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& multiply(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			return this->operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& multiply(const TVALUE value)
		{
			return this->operator *=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& dotProduct(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			return this->operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& scalar(const TVALUE value)
		{
			return this->operator *=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			return this->operator ==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& identity()
		{
			TMATRIX::identity();

			return *this;
		}

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& zero()
		{
			TMATRIX::zero();

			return *this;
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& allOnes()
		{
			TMATRIX::allOnes();

			return *this;
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& inverse()
		{
			TMATRIX::inverse();

			return *this;
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& inverse(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			TMATRIX::inverse(matrix);

			return *this;
		}

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> getInverse()
		{
			TMATRIX::getInverse();

			return *this;
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const
		{
			return TMATRIX::getDeterminant();
		}

		virtual ~MatrixAdapter()
		{
		}

	};
}

#endif // MATRIXADAPTER_H
