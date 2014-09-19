#ifndef MATRIX4_H
#define MATRIX4_H

namespace Common
{
	template <typename TVALUE>
	struct Matrix4
	{
		/// <summary>
		/// The Values of the matrix stored in [x][y] form
		/// </summary>
		TVALUE Values[4][4];

		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		Matrix4()
		{
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		/// <remarks>Equals operator</remarks>
		Matrix4(const TVALUE value)
		{
			operator =(value);
		}

		/// <summary>
		/// Constructs a matrix and sets each value from parameter list
		/// </summary>
		Matrix4(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x4y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x4y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3, const TVALUE x4y3, const TVALUE x1y4, const TVALUE x2y4, const TVALUE x3y4, const TVALUE x4y4)
		{
			set(x1y1, x2y1, x3y1, x4y1, x1y2, x2y2, x3y2, x4y2, x1y3, x2y3, x3y3, x4y3, x1y4, x2y4, x3y4, x4y4);
		}

		/// <summary>
		/// Returns the number of rows
		/// </summary>
		unsigned char getRowCount()
		{
			return 4;
		}

		/// <summary>
		/// Returns the number of columns
		/// </summary>
		unsigned char getColumnCount()
		{
			return 4;
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
		void set(const Matrix4<TVALUE>& matrix)
		{
			operator =(matrix);
		}

		/// <summary>
		/// Sets each value from parameter list
		/// </summary>
		void set(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x4y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x4y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3, const TVALUE x4y3, const TVALUE x1y4, const TVALUE x2y4, const TVALUE x3y4, const TVALUE x4y4)
		{
			Values[0][0] = x1y1;
			Values[0][1] = x1y2;
			Values[0][2] = x1y3;
			Values[0][3] = x1y4;
			Values[1][0] = x2y1;
			Values[1][1] = x2y2;
			Values[1][2] = x2y3;
			Values[1][3] = x2y4;
			Values[2][0] = x3y1;
			Values[2][1] = x3y2;
			Values[2][2] = x3y3;
			Values[2][3] = x3y4;
			Values[3][0] = x4y1;
			Values[3][1] = x4y2;
			Values[3][2] = x4y3;
			Values[3][3] = x4y4;
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
		Matrix4<TVALUE>& operator =(const TVALUE& value)
		{
			Values[0][0] = value;
			Values[0][1] = value;
			Values[0][2] = value;
			Values[0][3] = value;
			Values[1][0] = value;
			Values[1][1] = value;
			Values[1][2] = value;
			Values[1][3] = value;
			Values[2][0] = value;
			Values[2][1] = value;
			Values[2][2] = value;
			Values[2][3] = value;
			Values[3][0] = value;
			Values[3][1] = value;
			Values[3][2] = value;
			Values[3][3] = value;

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator =(const Matrix4<TVALUE>& matrix)
		{
			Values[0][0] = matrix.Values[0][0];
			Values[0][1] = matrix.Values[0][1];
			Values[0][2] = matrix.Values[0][2];
			Values[0][3] = matrix.Values[0][3];
			Values[1][0] = matrix.Values[1][0];
			Values[1][1] = matrix.Values[1][1];
			Values[1][2] = matrix.Values[1][2];
			Values[1][3] = matrix.Values[1][3];
			Values[2][0] = matrix.Values[2][0];
			Values[2][1] = matrix.Values[2][1];
			Values[2][2] = matrix.Values[2][2];
			Values[2][3] = matrix.Values[2][3];
			Values[3][0] = matrix.Values[3][0];
			Values[3][1] = matrix.Values[3][1];
			Values[3][2] = matrix.Values[3][2];
			Values[3][3] = matrix.Values[3][3];

			return *this;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator +(const Matrix4<TVALUE>& matrix) const
		{
			return Matrix4<TVALUE>(Values[0][0] + matrix.Values[0][0],
				Values[1][0] + matrix.Values[1][0],
				Values[2][0] + matrix.Values[2][0],
				Values[3][0] + matrix.Values[3][0],
				Values[0][1] + matrix.Values[0][1],
				Values[1][1] + matrix.Values[1][1],
				Values[2][1] + matrix.Values[2][1],
				Values[3][1] + matrix.Values[3][1],
				Values[0][2] + matrix.Values[0][2],
				Values[1][2] + matrix.Values[1][2],
				Values[2][2] + matrix.Values[2][2],
				Values[3][2] + matrix.Values[3][2],
				Values[0][3] + matrix.Values[0][3],
				Values[1][3] + matrix.Values[1][3],
				Values[2][3] + matrix.Values[2][3],
				Values[3][3] + matrix.Values[3][3]);
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator +=(const Matrix4<TVALUE>& matrix)
		{
			return *this + matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator -(const Matrix4<TVALUE>& matrix) const
		{
			return Matrix4<TVALUE>(Values[0][0] - matrix.Values[0][0],
				Values[1][0] - matrix.Values[1][0],
				Values[2][0] - matrix.Values[2][0],
				Values[3][0] - matrix.Values[3][0],
				Values[0][1] - matrix.Values[0][1],
				Values[1][1] - matrix.Values[1][1],
				Values[2][1] - matrix.Values[2][1],
				Values[3][1] - matrix.Values[3][1],
				Values[0][2] - matrix.Values[0][2],
				Values[1][2] - matrix.Values[1][2],
				Values[2][2] - matrix.Values[2][2],
				Values[3][2] - matrix.Values[3][2],
				Values[0][3] - matrix.Values[0][3],
				Values[1][3] - matrix.Values[1][3],
				Values[2][3] - matrix.Values[2][3],
				Values[3][3] - matrix.Values[3][3]);
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator -=(const Matrix4<TVALUE>& matrix)
		{
			return *this - matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator *(const Matrix4<TVALUE>& matrix) const
		{
			return Matrix4<TVALUE>((matrix.Values[0][0] * Values[0][0]) + (matrix.Values[0][1] * Values[1][0]) + (matrix.Values[0][2] * Values[2][0]) + (matrix.Values[0][3] * Values[3][0]),
									(matrix.Values[1][0] * Values[0][0]) + (matrix.Values[1][1] * Values[1][0]) + (matrix.Values[1][2] * Values[2][0]) + (matrix.Values[1][3] * Values[3][0]),
									(matrix.Values[2][0] * Values[0][0]) + (matrix.Values[2][1] * Values[1][0]) + (matrix.Values[2][2] * Values[2][0]) + (matrix.Values[2][3] * Values[3][0]),
									(matrix.Values[3][0] * Values[0][0]) + (matrix.Values[3][1] * Values[1][0]) + (matrix.Values[3][2] * Values[2][0]) + (matrix.Values[3][3] * Values[3][0]),
									(matrix.Values[0][0] * Values[0][1]) + (matrix.Values[0][1] * Values[1][1]) + (matrix.Values[0][2] * Values[2][1]) + (matrix.Values[0][3] * Values[2][1]),
									(matrix.Values[1][0] * Values[0][1]) + (matrix.Values[1][1] * Values[1][1]) + (matrix.Values[1][2] * Values[2][1]) + (matrix.Values[1][3] * Values[2][1]),
									(matrix.Values[2][0] * Values[0][1]) + (matrix.Values[2][1] * Values[1][1]) + (matrix.Values[2][2] * Values[2][1]) + (matrix.Values[2][3] * Values[2][1]),
									(matrix.Values[3][0] * Values[0][1]) + (matrix.Values[3][1] * Values[1][1]) + (matrix.Values[3][2] * Values[2][1]) + (matrix.Values[3][3] * Values[2][1]),
									(matrix.Values[0][0] * Values[0][2]) + (matrix.Values[0][1] * Values[1][2]) + (matrix.Values[0][2] * Values[2][2]) + (matrix.Values[0][3] * Values[2][2]),
									(matrix.Values[1][0] * Values[0][2]) + (matrix.Values[1][1] * Values[1][2]) + (matrix.Values[1][2] * Values[2][2]) + (matrix.Values[1][3] * Values[2][2]),
									(matrix.Values[2][0] * Values[0][2]) + (matrix.Values[2][1] * Values[1][2]) + (matrix.Values[2][2] * Values[2][2]) + (matrix.Values[2][3] * Values[2][2]),
									(matrix.Values[3][0] * Values[0][2]) + (matrix.Values[3][1] * Values[1][2]) + (matrix.Values[3][2] * Values[2][2]) + (matrix.Values[3][3] * Values[2][2]),
									(matrix.Values[0][0] * Values[0][3]) + (matrix.Values[0][1] * Values[1][3]) + (matrix.Values[0][2] * Values[2][3]) + (matrix.Values[0][3] * Values[2][3]),
									(matrix.Values[1][0] * Values[0][3]) + (matrix.Values[1][1] * Values[1][3]) + (matrix.Values[1][2] * Values[2][3]) + (matrix.Values[1][3] * Values[2][3]),
									(matrix.Values[2][0] * Values[0][3]) + (matrix.Values[2][1] * Values[1][3]) + (matrix.Values[2][2] * Values[2][3]) + (matrix.Values[2][3] * Values[2][3]),
									(matrix.Values[3][0] * Values[0][3]) + (matrix.Values[3][1] * Values[1][3]) + (matrix.Values[3][2] * Values[2][3]) + (matrix.Values[3][3] * Values[2][3]));
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator *=(const Matrix4<TVALUE>& matrix)
		{
			return *this * matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator *(const TVALUE value) const
		{
			return Matrix4<TVALUE>(Values[0][0] * value,
									Values[1][0] * value,
									Values[2][0] * value,
									Values[3][0] * value,
									Values[0][1] * value,
									Values[1][1] * value,
									Values[2][1] * value,
									Values[3][1] * value,
									Values[0][2] * value,
									Values[1][2] * value,
									Values[2][2] * value,
									Values[3][2] * value,
									Values[1][3] * value,
									Values[2][3] * value,
									Values[3][3] * value);
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator *=(const TVALUE value)
		{
			return *this * value;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator /(const Matrix4<TVALUE>& matrix) const
		{
			Matrix4<TVALUE> i = Matrix4<TVALUE>(matrix).inverse();
			TVALUE d = i.getDeterminant();

			if (d == 0)
				return 0;

			return Matrix4<TVALUE>();
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>& operator /=(const Matrix4<TVALUE>& matrix)
		{
			return *this / matrix;
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE> operator /(const TVALUE value) const
		{
			return Matrix4<TVALUE>(Values[0][0] / value,
									Values[1][0] / value,
									Values[2][0] / value,
									Values[3][0] / value,
									Values[0][1] / value,
									Values[1][1] / value,
									Values[2][1] / value,
									Values[3][1] / value,
									Values[0][2] / value,
									Values[1][2] / value,
									Values[2][2] / value,
									Values[3][2] / value,
									Values[0][3] / value,
									Values[1][3] / value,
									Values[2][3] / value,
									Values[3][3] / value);
		}

		/// <summary>
		/// Operator
		/// </summary>
		Matrix4<TVALUE>&  operator /=(const TVALUE value)
		{
			return *this / value;
		}

		bool operator ==(const Matrix4<TVALUE>& matrix)
		{
			for (unsigned char x = 0; x < 4; x++)
				for (unsigned char y = 0; y < 4; y++)
					if (Values[x][y] != matrix.Values[x][y])
						return false;

			return true;
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		Matrix4<TVALUE>& multiply(const Matrix4<TVALUE>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		Matrix4<TVALUE>& multiply(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Dot product multiplication
		/// </summary>
		Matrix4<TVALUE>& dotProduct(const Matrix4<TVALUE>& matrix)
		{
			return operator *=(matrix);
		}

		/// <summary>
		/// Scalar multiplication
		/// </summary>
		Matrix4<TVALUE>& scalar(const TVALUE value)
		{
			return operator *=(value);
		}

		/// <summary>
		/// Compares the matrix
		/// </summary>
		bool equals(const Matrix4<TVALUE>& matrix) const
		{
			return operator ==(matrix);
		}

		/// <summary>
		/// Populates the matrix with an identity matrix
		/// </summary>
		Matrix4<TVALUE>& identity()
		{
			set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);

			return *this;
		}

		/// <summary>
		/// Populates the matrix with a zero matrix
		/// </summary>
		Matrix4<TVALUE>& zero()
		{
			return operator =(0);
		}

		/// <summary>
		/// Populates the matrix with an all-ones matrix
		/// </summary>
		Matrix4<TVALUE>& allOnes()
		{
			return operator =(1);
		}

		/// <summary>
		/// Inverts the matrix
		/// </summary>
		Matrix4<TVALUE>& inverse()
		{
			return inverse(*this);
		}

		/// <summary>
		/// Inverts the matrix passed
		/// </summary>
		Matrix4<TVALUE>& inverse(const Matrix4<TVALUE>& matrix)
		{
			//todo
			return *this;
		}

		/// <summary>
		/// Returns the inverse of the matrix
		/// </summary>
		Matrix4<TVALUE> getInverse()
		{
			//todo
			return Matrix4<TVALUE>();
		}

		/// <summary>
		/// Gets the determinate of the matrix
		/// </summary>
		TVALUE getDeterminant() const
		{
			//todo
			return Matrix4<TVALUE>();
		}

		virtual ~Matrix4()
		{
		}

	};

}

#endif // MATRIX4_H
