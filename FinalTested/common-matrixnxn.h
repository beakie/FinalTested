#ifndef MATRIXNXN_H
#define MATRIXNXN_H

namespace Common
{
	//should i add build matrix method and call from constructors

	template <typename TVALUE, typename TINDEX>
	struct MatrixNxN
	{
		/// <summary>
		/// The values of the matrix stored in [x][y] form
		/// </summary>
		TVALUE** Values; // could this be Image<TVALUE, TINDEX> (private)?

		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		MatrixNxN(TINDEX rows, TINDEX columns)
		{
			//todo
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		MatrixNxN(TINDEX rows, TINDEX columns, const TVALUE value)
			: MatrixNxN(rows, columns)
		{
			operator =(value);
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

		/// <summary>
		/// Sets all the values to a single value
		/// </summary>
		void set(const TVALUE value)
		{
			operator =(value);
		}

		/// <summary>
		/// Sets specified value
		/// </summary>
		void set(const TINDEX x, const TINDEX y, const TVALUE value)
		{
			Values[x][y] = value;
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		void set(const MatrixNxN<TVALUE, TINDEX>& matrix)
		{
			operator =(matrix);
		}

		/// <summary>
		/// Gets the value
		/// </summary>
		TVALUE get(const TINDEX x, const TINDEX y)
		{
			return Values[x][y];
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& operator =(const TVALUE& value);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& operator =(const MatrixNxN<TVALUE, TINDEX>& matrix);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX> operator +(const MatrixNxN<TVALUE, TINDEX>& matrix) const;

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& operator +=(const MatrixNxN<TVALUE, TINDEX>& matrix)
		{
			return *this + matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX> operator -(const MatrixNxN<TVALUE, TINDEX>& matrix) const;

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& operator -=(const MatrixNxN<TVALUE, TINDEX>& matrix)
		{
			return *this - matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX> operator *(const MatrixNxN<TVALUE, TINDEX>& matrix) const;

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& operator *=(const MatrixNxN<TVALUE, TINDEX>& matrix)
		{
			return *this * matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX> operator *(const TVALUE value) const;

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& operator *=(const TVALUE value)
		{
			return *this * value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX> operator /(const MatrixNxN<TVALUE, TINDEX>& matrix) const;

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& operator /=(const MatrixNxN<TVALUE, TINDEX>& matrix)
		{
			return *this / matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX> operator /(const TVALUE value) const;

		/// <summary>
		/// Operator
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& operator /=(const TVALUE value)
		{
			return *this / value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator ==(const MatrixNxN<TVALUE, TINDEX>& matrix) const;

		/// <summary>
		/// Operator
		/// </summary>
		bool operator !=(const MatrixNxN<TVALUE, TINDEX>& matrix) const
		{
			return operator ==(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& multiply(const MatrixNxN<TVALUE, TINDEX>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& multiply(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& dotProduct(const MatrixNxN<TVALUE, TINDEX>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& scalar(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const MatrixNxN<TVALUE, TINDEX>& matrix) const
		{
			return operator ==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& identity();

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& zero()
		{
			return operator =(0);
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& allOnes()
		{
			return operator =(1);
		}

		/// <summary>
		/// Transposes the matrix
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& transpose()
		{
			return transpose(*this);
		}

		/// <summary>
		/// Transposes the matrix passed
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& transpose(const MatrixNxN<TVALUE, TINDEX>& matrix);

		/// <summary>
		/// Returns the transpose of the matrix
		/// </summary>
		MatrixNxN<TVALUE, TINDEX> getTransposed()
		{
			return MatrixNxN<TVALUE, TINDEX>(*this).transpose();
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& inverse()
		{
			return inverse(*this);
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		MatrixNxN<TVALUE, TINDEX>& inverse(const MatrixNxN<TVALUE, TINDEX>& matrix);

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		MatrixNxN<TVALUE, TINDEX> getInverted()
		{
			return MatrixNxN<TVALUE, TINDEX>(*this).inverse();
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const;

		virtual ~MatrixNxN()
		{
		}
	};

}
#endif // MATRIXNXN_H
