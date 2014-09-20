#ifndef MATRIX3_H
#define MATRIX3_H

namespace Common
{
	template <typename TVALUE>
	struct Matrix3
	{
		/// <summary>
		/// The Values of the matrix stored in [x][y] form
		/// </summary>
		TVALUE Values[3][3];

		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		Matrix3()
		{
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Matrix3(const TVALUE value)
		{
			operator =(value);
		}

		/// <summary>
		/// Constructs a matrix and sets each value from parameter list
		/// </summary>
		Matrix3(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3)
		{
			set(x1y1, x2y1, x3y1, x1y2, x2y2, x3y2, x1y3, x2y3, x3y3);
		}

		/// <summary>
		/// Returns the number of rows
		/// </summary>
		unsigned char getRowCount()
		{
			return 3;
		}

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		unsigned char getColumnCount()
		{
			return 3;
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
		void set(const Matrix3<TVALUE>& matrix)
		{
			operator =(matrix);
		}

		/// <summary>
		/// Sets each value from parameter list
		/// </summary>
		void set(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3)
		{
			Values[0][0] = x1y1;
			Values[0][1] = x1y2;
			Values[0][2] = x1y3;
			Values[1][0] = x2y1;
			Values[1][1] = x2y2;
			Values[1][2] = x2y3;
			Values[2][0] = x3y1;
			Values[2][1] = x3y2;
			Values[2][2] = x3y3;
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
		Matrix3<TVALUE>& operator =(const TVALUE& value)
		{
			Values[0][0] = value;
			Values[0][1] = value;
			Values[0][2] = value;
			Values[1][0] = value;
			Values[1][1] = value;
			Values[1][2] = value;
			Values[2][0] = value;
			Values[2][1] = value;
			Values[2][2] = value;

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE>& operator =(const Matrix3<TVALUE>& matrix)
		{
			Values[0][0] = matrix.Values[0][0];
			Values[0][1] = matrix.Values[0][1];
			Values[0][2] = matrix.Values[0][2];
			Values[1][0] = matrix.Values[1][0];
			Values[1][1] = matrix.Values[1][1];
			Values[1][2] = matrix.Values[1][2];
			Values[2][0] = matrix.Values[2][0];
			Values[2][1] = matrix.Values[2][1];
			Values[2][2] = matrix.Values[2][2];

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE> operator +(const Matrix3<TVALUE>& matrix) const
		{
			return Matrix3<TVALUE>(Values[0][0] + matrix.Values[0][0],
									Values[1][0] + matrix.Values[1][0],
									Values[2][0] + matrix.Values[2][0],
									Values[0][1] + matrix.Values[0][1],
									Values[1][1] + matrix.Values[1][1],
									Values[2][1] + matrix.Values[2][1],
									Values[0][2] + matrix.Values[0][2],
									Values[1][2] + matrix.Values[1][2],
									Values[2][2] + matrix.Values[2][2]);
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE>& operator +=(const Matrix3<TVALUE>& matrix)
		{
			return *this + matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE> operator -(const Matrix3<TVALUE>& matrix) const
		{
			return Matrix3<TVALUE>(Values[0][0] - matrix.Values[0][0],
									Values[1][0] - matrix.Values[1][0],
									Values[2][0] - matrix.Values[2][0],
									Values[0][1] - matrix.Values[0][1],
									Values[1][1] - matrix.Values[1][1],
									Values[2][1] - matrix.Values[2][1],
									Values[0][2] - matrix.Values[0][2],
									Values[1][2] - matrix.Values[1][2],
									Values[2][2] - matrix.Values[2][2]);
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE>& operator -=(const Matrix3<TVALUE>& matrix)
		{
			return *this - matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE> operator *(const Matrix3<TVALUE>& matrix) const
		{
			return Matrix3<TVALUE>((matrix.Values[0][0] * Values[0][0]) + (matrix.Values[0][1] * Values[1][0]) + (matrix.Values[0][2] * Values[2][0]),
									(matrix.Values[1][0] * Values[0][0]) + (matrix.Values[1][1] * Values[1][0]) + (matrix.Values[1][2] * Values[2][0]),
									(matrix.Values[2][0] * Values[0][0]) + (matrix.Values[2][1] * Values[1][0]) + (matrix.Values[2][2] * Values[2][0]),
									(matrix.Values[0][0] * Values[0][1]) + (matrix.Values[0][1] * Values[1][1]) + (matrix.Values[0][2] * Values[2][1]),
									(matrix.Values[1][0] * Values[0][1]) + (matrix.Values[1][1] * Values[1][1]) + (matrix.Values[1][2] * Values[2][1]),
									(matrix.Values[2][0] * Values[0][1]) + (matrix.Values[2][1] * Values[1][1]) + (matrix.Values[2][2] * Values[2][1]),
									(matrix.Values[0][0] * Values[0][2]) + (matrix.Values[0][1] * Values[1][2]) + (matrix.Values[0][2] * Values[2][2]),
									(matrix.Values[1][0] * Values[0][2]) + (matrix.Values[1][1] * Values[1][2]) + (matrix.Values[1][2] * Values[2][2]),
									(matrix.Values[2][0] * Values[0][2]) + (matrix.Values[2][1] * Values[1][2]) + (matrix.Values[2][2] * Values[2][2]));
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE>& operator *=(const Matrix3<TVALUE>& matrix)
		{
			return *this * matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE> operator *(const TVALUE value) const
		{
			return Matrix3<TVALUE>(Values[0][0] * value,
									Values[1][0] * value,
									Values[2][0] * value,
									Values[0][1] * value,
									Values[1][1] * value,
									Values[2][1] * value,
									Values[0][2] * value,
									Values[1][2] * value,
									Values[2][2] * value);
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE>& operator *=(const TVALUE value)
		{
			return *this * value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE> operator /(const Matrix3<TVALUE>& matrix) const
		{
			TVALUE d = matrix.getDeterminant();

			if (d == 0)
				return 0;

			return Matrix3<TVALUE>(matrix).inverse();
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE>& operator /=(const Matrix3<TVALUE>& matrix)
		{
			return *this / matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE> operator /(const TVALUE value) const
		{
			return Matrix3<TVALUE>(Values[0][0] / value,
									Values[1][0] / value,
									Values[2][0] / value,
									Values[0][1] / value,
									Values[1][1] / value,
									Values[2][1] / value,
									Values[0][2] / value,
									Values[1][2] / value,
									Values[2][2] / value);
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix3<TVALUE>& operator /=(const TVALUE value)
		{
			return *this / value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator ==(const Matrix3<TVALUE>& matrix) const
		{
			return (Values[0][0] == matrix.Values[0][0])
					&& (Values[0][1] == matrix.Values[0][1])
					&& (Values[0][2] == matrix.Values[0][2])
					&& (Values[1][0] == matrix.Values[1][0])
					&& (Values[1][1] == matrix.Values[1][1])
					&& (Values[1][2] == matrix.Values[1][2])
					&& (Values[2][0] == matrix.Values[2][0])
					&& (Values[2][1] == matrix.Values[2][1])
					&& (Values[2][2] == matrix.Values[2][2]);
		}

		/// <summary>
		/// Operator
		/// </summary>
		bool operator !=(const Matrix3<TVALUE>& matrix) const
		{
			return operator ==(matrix);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		Matrix3<TVALUE>& multiply(const Matrix3<TVALUE>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		Matrix3<TVALUE>& multiply(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		Matrix3<TVALUE>& dotProduct(const Matrix3<TVALUE>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		Matrix3<TVALUE>& scalar(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const Matrix3<TVALUE>& matrix) const
		{
			return operator ==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		Matrix3<TVALUE>& identity()
		{
			set(1, 0, 0, 0, 1, 0, 0, 0, 1);

			return *this;
		}

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		Matrix3<TVALUE>& zero()
		{
			return operator =(0);
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		Matrix3<TVALUE>& allOnes()
		{
			return operator =(1);
		}

		/// <summary>
		/// Transposes the matrix
		/// </summary>
		Matrix3<TVALUE>& transpose()
		{
			return transpose(*this);
		}

		/// <summary>
		/// Transposes the matrix passed
		/// </summary>
		Matrix3<TVALUE>& transpose(const Matrix3<TVALUE>& matrix)
		{
			//todo
			return *this;
		}

		/// <summary>
		/// Returns the transpose of the matrix
		/// </summary>
		Matrix3<TVALUE> getTransposed()
		{
			//todo
			return Matrix3<TVALUE>();
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		Matrix3<TVALUE>& inverse()
		{
			return inverse(*this);
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		Matrix3<TVALUE>& inverse(const Matrix3<TVALUE>& matrix)
		{
			//todo
			return *this;
		}

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		Matrix3<TVALUE> getInverted()
		{
			//todo
			return Matrix3<TVALUE>();
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const
		{
			//todo
			return Matrix3<TVALUE>();
		}

		virtual ~Matrix3()
		{
		}

	};

}

#endif // MATRIX3_H
