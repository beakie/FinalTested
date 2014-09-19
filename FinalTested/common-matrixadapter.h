#ifndef MATRIXADAPTER_H
#define MATRIXADAPTER_H

#include "common-imatrixadapter.h"

namespace Common
{
	template <typename TMATRIX, typename TVALUE, typename TINDEX>
	struct MatrixAdapter : IMatrixAdapter<TVALUE, TINDEX>
	{
	private:
		TMATRIX _Matrix;

	public:
		/// <summary>
		/// Constructs an unpopulated matrix adapter
		/// </summary>
		MatrixAdapter()
		{
		}

		/// <summary>
		/// Constructs a matrix adapter and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		MatrixAdapter(const TVALUE value)
		{
			_Matrix = TMATRIX(value);
		}

		/// <summary>
		/// Constructs a matrix adapter and sets the matrix
		/// </summary>
		/// <remarks>Equals operator</remarks>
		MatrixAdapter(const TMATRIX& matrix)
		{
			_Matrix = TMATRIX(matrix);
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		TMATRIX& getMatrix()
		{
			return _Matrix;
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
			_Matrix.operator =(matrix);
		}

		/// <summary>
		/// Gets the value
		/// </summary>
		TVALUE get(const unsigned char x, const unsigned char y)
		{
			return _Matrix.get(x, y);
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator =(const TVALUE& value)
		{
			_Matrix.operator =(value);
			
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
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator =(const TMATRIX& matrix)
		{
			_Matrix.operator =(value);

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
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator +(const TMATRIX& matrix) const
		{
			return MatrixAdapter<TMATRIX, TVALUE, TINDEX>(_Matrix.operator +(matrix));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator +=(const TMATRIX& matrix)
		{
			// do manually. consider matrix size.

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
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator -(const TMATRIX& matrix) const
		{
			return MatrixAdapter<TMATRIX, TVALUE, TINDEX>(_Matrix.operator -(matrix));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator -=(const TMATRIX& matrix)
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
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator *(const TMATRIX& matrix) const
		{
			return MatrixAdapter<TMATRIX, TVALUE, TINDEX>(_Matrix.operator *(matrix));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator *=(const TMATRIX& matrix)
		{
			operator *=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator *(const TVALUE value) const
		{
			_Matrix.operator *(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator *=(const TVALUE value)
		{
			_Matrix.operator *(value);

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
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator /(const TMATRIX& matrix) const
		{
			return MatrixAdapter<TMATRIX, TVALUE, TINDEX>(_Matrix.operator /(matrix));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& operator /=(const TMATRIX& matrix)
		{
			operator /=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> operator /(const TVALUE value) const
		{
			_Matrix.operator /(value);

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
		/// Operator
		/// </summary>
		bool operator ==(const TMATRIX& matrix) const
		{
			return _Matrix.operator ==(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& multiply(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& multiply(const TMATRIX& matrix)
		{
			_Matrix.operator *=(matrix);
			
			return *this;
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& multiply(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& dotProduct(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& dotProduct(const TMATRIX& matrix)
		{
			_Matrix.operator *=(matrix);

			return *this;
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& scalar(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const IMatrixAdapter<TVALUE, TINDEX>& matrix) const
		{
			return operator ==(matrix);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const TMATRIX& matrix) const
		{
			return _Matrix.operator ==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& identity()
		{
			_Matrix.identity();

			return *this;
		}

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& zero()
		{
			_Matrix.zero();

			return *this;
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& allOnes()
		{
			_Matrix.allOnes();

			return *this;
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& inverse()
		{
			_Matrix.inverse();

			return *this;
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& inverse(const IMatrixAdapter<TVALUE, TINDEX>& matrix)
		{
			_Matrix.inverse(matrix);

			return *this;
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX>& inverse(const TMATRIX& matrix)
		{
			_Matrix.inverse(matrix);

			return *this;
		}

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE, TINDEX> getInverse()
		{
			_Matrix.getInverse();

			return *this;
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const
		{
			return _Matrix.getDeterminant();
		}

		virtual ~MatrixAdapter()
		{
		}

	};
}

#endif // MATRIXADAPTER_H
