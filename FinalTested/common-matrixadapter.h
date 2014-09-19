#ifndef MATRIXADAPTER_H
#define MATRIXADAPTER_H

#include "common-imatrixadapter.h"

namespace Common
{
	template <typename TMATRIX, typename TVALUE, typename TINDEX>
	struct MatrixAdapter : IMatrixAdapter<TVALUE, TINDEX>
	{
		TMATRIX Matrix;

		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		MatrixAdapter()
		{
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		MatrixAdapter(const TVALUE value)
		{
			Matrix = TMATRIX(value);
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		void set(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			operator =(matrix);
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		void set(const TMATRIX& matrix)
		{
			Matrix.operator = (matrix);
		}

		/// <summary>
		/// Gets the value
		/// </summary>
		TVALUE get(const unsigned char x, const unsigned char y)
		{
			return Matrix.get(x, y);
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator =(const TVALUE& value)
		{
			Matrix.operator =(value);
			
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
			Matrix.operator *(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator *=(const TVALUE value)
		{
			Matrix.operator *(value);

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
			Matrix.operator /(value);

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
			Matrix.identity();

			return *this;
		}

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& zero()
		{
			Matrix.zero();

			return *this;
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& allOnes()
		{
			Matrix.allOnes();

			return *this;
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& inverse()
		{
			Matrix.inverse();

			return *this;
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& inverse(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			Matrix.inverse(matrix);

			return *this;
		}

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> getInverse()
		{
			Matrix.getInverse();

			return *this;
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const
		{
			return Matrix.getDeterminant();
		}

		virtual ~MatrixAdapter()
		{
		}

	};
}

#endif // MATRIXADAPTER_H
