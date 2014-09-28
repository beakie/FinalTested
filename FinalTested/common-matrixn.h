#ifndef MATRIXN_H
#define MATRIXN_H

namespace Common
{
	//should i add build matrix method and call from constructors

	template <typename TVALUE>
	struct MatrixN
	{
		/// <summary>
		/// The values of the matrix stored in [x][y] form
		/// </summary>
		TVALUE** Values; // could this be Image<TVALUE> (private)?

		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		MatrixN(unsigned char rows, unsigned char columns)
		{
			//todo
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		MatrixN(unsigned char rows, unsigned char columns, const TVALUE value)
			: MatrixN(rows, columns)
		{
			operator =(value);
		}

		/// <summary>
		/// Returns the number of rows
		/// </summary>
		unsigned char getRowCount()
		{
			//todo
		}

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		unsigned char getColumnCount()
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
		void set(const unsigned char x, const unsigned char y, const TVALUE value)
		{
			Values[x][y] = value;
		}

		/// <summary>
		/// Copies values from matrix
		/// </summary>
		void set(const MatrixN<TVALUE>& matrix)
		{
			operator =(matrix);
		}

		/// <summary>
		/// Gets the value
		/// </summary>
		TVALUE get(const unsigned char x, const unsigned char y)
		{
			return Values[x][y];
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE>& operator =(const TVALUE& value);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE>& operator =(const MatrixN<TVALUE>& matrix);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE> operator +(const MatrixN<TVALUE>& matrix) const
		{
			MatrixN<TVALUE> m = *this;

			m += matrix;

			return m;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE>& operator +=(const MatrixN<TVALUE>& matrix);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE> operator -(const MatrixN<TVALUE>& matrix) const
		{
			MatrixN<TVALUE> m = *this;

			m -= matrix;

			return m;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE>& operator -=(const MatrixN<TVALUE>& matrix);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE> operator *(const MatrixN<TVALUE>& matrix) const
		{
			MatrixN<TVALUE> m = *this;

			m *= matrix;

			return m;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE>& operator *=(const MatrixN<TVALUE>& matrix);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE> operator *(const TVALUE value) const
		{
			MatrixN<TVALUE> m = *this;

			m *= value;

			return m;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE>& operator *=(const TVALUE value);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE> operator /(const MatrixN<TVALUE>& matrix) const
		{
			MatrixN<TVALUE> m = *this;

			m /= matrix;

			return m;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE>& operator /=(const MatrixN<TVALUE>& matrix);

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE> operator /(const TVALUE value) const
		{
			MatrixN<TVALUE> m = *this;

			m /= value;

			return m;
		}

		/// <summary>
		/// Operator
		/// </summary>
		MatrixN<TVALUE>& operator /=(const TVALUE value);

		/// <summary>
		/// Operator
		/// </summary>
		bool operator ==(const MatrixN<TVALUE>& matrix) const;

		/// <summary>
		/// Operator
		/// </summary>
		bool operator !=(const MatrixN<TVALUE>& matrix) const
		{
			return operator ==(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixN<TVALUE>& multiply(const MatrixN<TVALUE>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixN<TVALUE>& multiply(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		MatrixN<TVALUE>& dotProduct(const MatrixN<TVALUE>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		MatrixN<TVALUE>& scalar(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const MatrixN<TVALUE>& matrix) const
		{
			return operator ==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		MatrixN<TVALUE>& identity();

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		MatrixN<TVALUE>& zero()
		{
			return operator =(0);
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		MatrixN<TVALUE>& allOnes()
		{
			return operator =(1);
		}

		/// <summary>
		/// Transposes the matrix
		/// </summary>
		MatrixN<TVALUE>& transpose()
		{
			return transpose(*this);
		}

		/// <summary>
		/// Transposes the matrix passed
		/// </summary>
		MatrixN<TVALUE>& transpose(const MatrixN<TVALUE>& matrix);

		/// <summary>
		/// Returns the transpose of the matrix
		/// </summary>
		MatrixN<TVALUE> getTransposed()
		{
			return MatrixN<TVALUE>(*this).transpose();
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		MatrixN<TVALUE>& inverse()
		{
			return inverse(*this);
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		MatrixN<TVALUE>& inverse(const MatrixN<TVALUE>& matrix);

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		MatrixN<TVALUE> getInverted()
		{
			return MatrixN<TVALUE>(*this).inverse();
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const;

		virtual ~MatrixN()
		{
		}
	};

}
#endif // MATRIXN_H
