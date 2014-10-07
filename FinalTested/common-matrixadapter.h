#ifndef COMMONMATRIXADAPTER_H
#define COMMONMATRIXADAPTER_H

#include "core.h"
#include "common-imatrixadapter.h"

namespace Common
{
	/// <summary>
	/// Adapter for fixed sized matrix
	/// </summary>
	template <typename TMATRIX, typename TVALUE>
	class MatrixAdapter : IMatrixAdapter<TVALUE>
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
		/// Returns the number of rows
		/// </summary>
		UInt8 getRowCount()
		{
			return _Matrix.getRowCount();
		}

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		UInt8 getColumnCount()
		{
			return _Matrix.getColumnCount();
		}

		/// <summary>
		/// Gets the matrix
		/// </summary>
		TMATRIX& getMatrix()
		{
			return _Matrix;
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		void set(const IMatrixAdapter<TVALUE>& matrix)
		{
			operator=(matrix);
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		void set(const TMATRIX& matrix)
		{
			_Matrix.operator=(matrix);
		}

		/// <summary>
		/// Gets the value
		/// </summary>
		TVALUE get(const UInt8 x, const UInt8 y)
		{
			return _Matrix.get(x, y);
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator=(const TVALUE& value)
		{
			_Matrix.operator=(value);
			
			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator=(const IMatrixAdapter<TVALUE>& matrix)
		{
			// do manually. consider matrix size.

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator=(const TMATRIX& matrix)
		{
			_Matrix.operator=(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator+(const IMatrixAdapter<TVALUE>& matrix) const
		{
			// do manually. consider matrix size.

			return 0;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator+=(const IMatrixAdapter<TVALUE>& matrix)
		{
			operator+=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator+(const TMATRIX& matrix) const
		{
			return MatrixAdapter<TMATRIX, TVALUE>(_Matrix.operator+(matrix));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator+=(const TMATRIX& matrix)
		{
			// do manually. consider matrix size.

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator-(const IMatrixAdapter<TVALUE>& matrix) const
		{
			// do manually. consider matrix size.

			return 0;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator-=(const IMatrixAdapter<TVALUE>& matrix)
		{
			operator-=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator-(const TMATRIX& matrix) const
		{
			return MatrixAdapter<TMATRIX, TVALUE>(_Matrix.operator-(matrix));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator-=(const TMATRIX& matrix)
		{
			operator-=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator*(const IMatrixAdapter<TVALUE>& matrix) const
		{
			// do manually. consider matrix size.

			return 0;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator*=(const IMatrixAdapter<TVALUE>& matrix)
		{
			operator*=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator*(const TMATRIX& matrix) const
		{
			return MatrixAdapter<TMATRIX, TVALUE>(_Matrix.operator*(matrix));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator*=(const TMATRIX& matrix)
		{
			operator*=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator*(const TVALUE value) const
		{
			return MatrixAdapter<TMATRIX, TVALUE>(_Matrix.operator*(value));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator*=(const TVALUE value)
		{
			_Matrix.operator*(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator/(const IMatrixAdapter<TVALUE>& matrix) const
		{
			// do manually. consider matrix size.

			return 0;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator/=(const IMatrixAdapter<TVALUE>& matrix)
		{
			operator/=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator/(const TMATRIX& matrix) const
		{
			return MatrixAdapter<TMATRIX, TVALUE>(_Matrix.operator/(matrix));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator/=(const TMATRIX& matrix)
		{
			operator/=(matrix);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> operator/(const TVALUE value) const
		{
			return MatrixAdapter<TMATRIX, TVALUE>(_Matrix.operator/(value));
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& operator/=(const TVALUE value)
		{
			operator/=(value);

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator==(const IMatrixAdapter<TVALUE>& matrix) const
		{
			// do manually. consider matrix size.

			return false;
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator==(const TMATRIX& matrix) const
		{
			return _Matrix.operator==(matrix);
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator!=(const IMatrixAdapter<TVALUE>& matrix) const
		{
			// do manually. consider matrix size.

			return false;
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator!=(const TMATRIX& matrix) const
		{
			return !_Matrix.operator==(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& multiply(const IMatrixAdapter<TVALUE>& matrix)
		{
			return operator*=(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& multiply(const TMATRIX& matrix)
		{
			_Matrix.operator*=(matrix);
			
			return *this;
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& multiply(const TVALUE value)
		{
			return operator*=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& dotProduct(const IMatrixAdapter<TVALUE>& matrix)
		{
			return operator*=(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& dotProduct(const TMATRIX& matrix)
		{
			_Matrix.operator*=(matrix);

			return *this;
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& scalar(const TVALUE value)
		{
			return operator*=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const IMatrixAdapter<TVALUE>& matrix) const
		{
			return operator==(matrix);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const TMATRIX& matrix) const
		{
			return _Matrix.operator==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& identity()
		{
			_Matrix.identity();

			return *this;
		}

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& zero()
		{
			_Matrix.zero();

			return *this;
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& allOnes()
		{
			_Matrix.allOnes();

			return *this;
		}

		/// <summary>
		/// Transposes the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& transpose()
		{
			_Matrix.transpose();

			return *this;
		}

		/// <summary>
		/// Transpose the matrix passed
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& transpose(const IMatrixAdapter<TVALUE>& matrix)
		{
			_Matrix.transpose(matrix);

			return *this;
		}

		/// <summary>
		/// Transposes the matrix passed
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& transpose(const TMATRIX& matrix)
		{
			_Matrix.transpose(matrix);

			return *this;
		}

		/// <summary>
		/// Returns the transpose of the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> getTransposed()
		{
			return MatrixAdapter<TMATRIX, TVALUE>(_Matrix.getTransposed());
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& inverse()
		{
			_Matrix.inverse();

			return *this;
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& inverse(const IMatrixAdapter<TVALUE>& matrix)
		{
			_Matrix.inverse(matrix);

			return *this;
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE>& inverse(const TMATRIX& matrix)
		{
			_Matrix.inverse(matrix);

			return *this;
		}

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		MatrixAdapter<TMATRIX, TVALUE> getInverted()
		{
			return MatrixAdapter<TMATRIX, TVALUE>(_Matrix.getInverted());
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

#endif // COMMONMATRIXADAPTER_H
