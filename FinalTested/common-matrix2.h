#ifndef MATRIX2_H
#define MATRIX2_H

#include "common-imatrix.h"

namespace Common
{
	template <typename TVALUE>
	struct Matrix2 : public IMatrix < TVALUE, unsigned char, Matrix2<TVALUE> >
	{
		/// <summary>
		/// The values or the matrix in [x][y] form
		/// </summary>
		TVALUE values[2][2];

		/// <summary>
		/// Constructs an unpopulated matrix
		/// </summary>
		Matrix2()
		{
		}

		/// <summary>
		/// Constructs a matrix and sets all the values to a single value
		/// </summary>
		Matrix2(const TVALUE value)
		{
			operator =(value);
		}

		/// <summary>
		/// Constructs a matrix and sets each value from parameter list
		/// </summary>
		Matrix2(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x1y2, const TVALUE x2y2)
		{
			set(x1y1, x2y1, x1y2, x2y2);
		}

		void set(const TVALUE value)
		{
			operator =(value);
		}

		void set(const unsigned char x, const unsigned char y, const TVALUE value)
		{
			values[x][y] = value;
		}

		void set(const Matrix2<TVALUE>& matrix)
		{
			operator =(matrix);
		}

		/// <summary>
		/// Sets each value from parameter list
		/// </summary>
		void set(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x1y2, const TVALUE x2y2)
		{
			values[0][0] = x1y1;
			values[0][1] = x1y2;
			values[1][0] = x2y1;
			values[1][1] = x2y2;
		}

		TVALUE get(const unsigned char x, const unsigned char y)
		{
			return values[x][y];
		}

		Matrix2<TVALUE>& operator =(const TVALUE& value)
		{
			values[0][0] = value;
			values[0][1] = value;
			values[1][0] = value;
			values[1][1] = value;

			return *this;
		}

		Matrix2<TVALUE>& operator =(const Matrix2<TVALUE>& matrix)
		{
			values[0][0] = matrix.values[0][0];
			values[0][1] = matrix.values[0][1];
			values[1][0] = matrix.values[1][0];
			values[1][1] = matrix.values[1][1];

			return *this;
		}

		//////////////
		Matrix2<TVALUE> operator +(const Matrix2<TVALUE>& matrix) const
		{
			return Matrix2<TVALUE>(values[0][0] + matrix.values[0][0],
									values[1][0] + matrix.values[1][0],
									values[0][1] + matrix.values[0][1],
									values[1][1] + matrix.values[1][1]);
		}

		//////////////
		Matrix2<TVALUE>& operator +=(const Matrix2<TVALUE>& matrix)
		{
			return *this + matrix;
		}

		//////////////
		Matrix2<TVALUE> operator -(const Matrix2<TVALUE>& matrix) const
		{
			return Matrix2<TVALUE>(values[0][0] - matrix.values[0][0],
									values[1][0] - matrix.values[1][0],
									values[0][1] - matrix.values[0][1],
									values[1][1] - matrix.values[1][1]);
		}

		//////////////
		Matrix2<TVALUE>& operator -=(const Matrix2<TVALUE>& matrix)
		{
			return *this - matrix;
		}

		//////////////
		Matrix2<TVALUE> operator *(const Matrix2<TVALUE>& matrix) const
		{
			return Matrix2<TVALUE>((matrix.values[0][0] * values[0][0]) + (matrix.values[0][1] * values[1][0]),
									(matrix.values[1][0] * values[0][0]) + (matrix.values[1][1] * values[1][0]),
									(matrix.values[0][0] * values[0][1]) + (matrix.values[0][1] * values[1][1]),
									(matrix.values[1][0] * values[0][1]) + (matrix.values[1][1] * values[1][1]));
		}

		//////////////
		Matrix2<TVALUE>& operator *=(const Matrix2<TVALUE>& matrix)
		{
			return *this * matrix;
		}

		//////////////
		Matrix2<TVALUE> operator *(const TVALUE value) const
		{
			return Matrix2<TVALUE>(values[0][0] * value,
									values[1][0] * value,
									values[0][1] * value,
									values[1][1] * value);
		}

		//////////////
		Matrix2<TVALUE>& operator *=(const TVALUE value)
		{
			return *this * value;
		}

		//////////////
		Matrix2<TVALUE> operator /(const Matrix2<TVALUE>& matrix) const
		{
			Matrix2<TVALUE> i = Matrix2<TVALUE>(matrix).inverse();
			TVALUE d = i.getDeterminant();

			if (d == 0)
				throw 123;

			return Matrix2<TVALUE>();
		}

		//////////////
		Matrix2<TVALUE>& operator /=(const Matrix2<TVALUE>& matrix)
		{
			return *this / matrix;
		}

		//////////////
		Matrix2<TVALUE> operator /(const TVALUE value) const
		{
			return Matrix2<TVALUE>(values[0][0] / value,
									values[1][0] / value,
									values[0][1] / value,
									values[1][1] / value);
		}

		//////////////
		Matrix2<TVALUE>& operator /=(const TVALUE value)
		{
			return *this / value;
		}

		//////////////
		bool operator ==(const Matrix2<TVALUE>& matrix) const
		{
			for (unsigned char x = 0; x < 2; x++)
				for (unsigned char y = 0; y < 2; y++)
					if (values[x][y] != matrix.values[x][y])
						return false;

			return true;
		}

		Matrix2<TVALUE>& multiply(const Matrix2<TVALUE>& matrix)
		{
			return this->operator *=(matrix);
		}

		Matrix2<TVALUE>& multiply(const TVALUE value)
		{
			return this->operator *=(value);
		}

		Matrix2<TVALUE>& dotProduct(const Matrix2<TVALUE>& matrix)
		{
			return this->operator *=(matrix);
		}

		Matrix2<TVALUE>& scalar(const TVALUE value)
		{
			return this->operator *=(value);
		}

		Matrix2<TVALUE>& identity()
		{
			set(1, 0, 0, 1);

			return *this;
		}

		Matrix2<TVALUE>& zero()
		{
			return this->operator =(0);
		}

		Matrix2<TVALUE>& allOnes()
		{
			return this->operator =(1);
		}

		Matrix2<TVALUE>& inverse()
		{
			return this->inverse(*this);
		}

		Matrix2<TVALUE>& inverse(const Matrix2<TVALUE>& matrix)
		{
			set(matrix.values[1][1], -matrix.values[1][0], -matrix.values[0][1], matrix.values[0][0]);

			return *this;
		}

		Matrix2<TVALUE> getInverse()
		{
			return Matrix2<TVALUE>();
		}

		TVALUE getDeterminant() const
		{
			return (values[0][0] * values[1][1]) - (values[0][1] * values[1][0]);
		}

		bool equals(const Matrix2<TVALUE>& matrix) const
		{
			return this->operator ==(matrix);
		}

		virtual ~Matrix2()
		{
		}
	};

}

#endif // MATRIX2_H
