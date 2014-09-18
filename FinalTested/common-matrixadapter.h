#ifndef MATRIXADAPTER_H
#define MATRIXADAPTER_H

#include "common-imatrixadapter.h"

namespace Common
{
	template <typename TMATRIX, typename TVALUE, typename TINDEX>
	struct MatrixAdapter : TMATRIX, IMatrixAdapter<TVALUE, TINDEX>
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
			TMATRIX::set(matrix);
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
			TMATRIX::operator =(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator +(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			TMATRIX::operator +(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator +=(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			TMATRIX::operator +=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator -(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			TMATRIX::operator -(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator -=(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			TMATRIX::operator -=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator *(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			TMATRIX::operator *(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator *=(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			TMATRIX::operator *=(matrix);

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
			TMATRIX::operator *=(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator /(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			TMATRIX::operator /(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator /=(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			TMATRIX::operator /=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator /(const TVALUE value) const
		{
			TMATRIX::operator /(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator /=(const TVALUE value)
		{
			TMATRIX::operator /=(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator ==(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			return TMATRIX::operator ==(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& multiply(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			TMATRIX::multiply(matrix);

			return *this;
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& multiply(const TVALUE value)
		{
			TMATRIX::multiply(value);

			return *this;
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& dotProduct(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			TMATRIX::dotProduct(matrix);

			return *this;
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& scalar(const TVALUE value)
		{
			TMATRIX::scalar(value);

			return *this;
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			return TMATRIX::equals(matrix);
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
			TMATRIX::getDeterminant();

			return *this;
		}

		virtual ~MatrixAdapter()
		{
		}

	};
}

#endif // MATRIXADAPTER_H
