#ifndef MATRIX3_H
#define MATRIX3_H

#include "common-imatrix.h"

namespace Common
{

	template <typename TVALUE>
	struct Matrix3 : public IMatrix<TVALUE, unsigned char, Matrix3<TVALUE> >
	{
		TVALUE values[3][3];

		Matrix3()
		{
		}

		Matrix3(const TVALUE value)
		{
			operator =(value);
		}

		Matrix3(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3)
		{
			set(x1y1, x2y1, x3y1, x1y2, x2y2, x3y2, x1y3, x2y3, x3y3);
		}

		void set(const TVALUE value)
		{
			operator =(value);
		}

		void set(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3)
		{
			values[0][0] = x1y1;
			values[0][1] = x1y2;
			values[0][2] = x1y3;
			values[1][0] = x2y1;
			values[1][1] = x2y2;
			values[1][2] = x2y3;
			values[2][0] = x3y1;
			values[2][1] = x3y2;
			values[2][2] = x3y3;
		}

		void set(const unsigned char x, const unsigned char y, const TVALUE value)
		{
			values[x][y] = value;
		}

		void set(const Matrix3<TVALUE> &matrix)
		{
			operator =(matrix);
		}

		TVALUE get(const unsigned char x, const unsigned char y)
		{
			return values[x][y];
		}

		bool equals(const Matrix3<TVALUE> &matrix)
		{
			return this->operator ==(matrix);
		}

		Matrix3<TVALUE> & multiply(const Matrix3<TVALUE> &matrix)
		{
			return this->operator *(matrix);
		}

		Matrix3<TVALUE> & operator=(const TVALUE &value)
		{
			values[0][0] = value;
			values[0][1] = value;
			values[0][2] = value;
			values[1][0] = value;
			values[1][1] = value;
			values[1][2] = value;
			values[2][0] = value;
			values[2][1] = value;
			values[2][2] = value;

			return *this;
		}

		Matrix3<TVALUE> & operator=(const Matrix3<TVALUE> &matrix)
		{
			values[0][0] = matrix.values[0][0];
			values[0][1] = matrix.values[0][1];
			values[0][2] = matrix.values[0][2];
			values[1][0] = matrix.values[1][0];
			values[1][1] = matrix.values[1][1];
			values[1][2] = matrix.values[1][2];
			values[2][0] = matrix.values[2][0];
			values[2][1] = matrix.values[2][1];
			values[2][2] = matrix.values[2][2];

			return *this;
		}

		Matrix3<TVALUE> operator*(const Matrix3<TVALUE> &matrix) const
		{
			return Matrix3<TVALUE>((matrix.values[0][0] * values[0][0]) + (matrix.values[0][1] * values[1][0]) + (matrix.values[0][2] * values[2][0]),
									(matrix.values[1][0] * values[0][0]) + (matrix.values[1][1] * values[1][0]) + (matrix.values[1][2] * values[2][0]),
									(matrix.values[2][0] * values[0][0]) + (matrix.values[2][1] * values[1][0]) + (matrix.values[2][2] * values[2][0]),
									(matrix.values[0][0] * values[0][1]) + (matrix.values[0][1] * values[1][1]) + (matrix.values[0][2] * values[2][1]),
									(matrix.values[1][0] * values[0][1]) + (matrix.values[1][1] * values[1][1]) + (matrix.values[1][2] * values[2][1]),
									(matrix.values[2][0] * values[0][1]) + (matrix.values[2][1] * values[1][1]) + (matrix.values[2][2] * values[2][1]),
									(matrix.values[0][0] * values[0][2]) + (matrix.values[0][1] * values[1][2]) + (matrix.values[0][2] * values[2][2]),
									(matrix.values[1][0] * values[0][2]) + (matrix.values[1][1] * values[1][2]) + (matrix.values[1][2] * values[2][2]),
									(matrix.values[2][0] * values[0][2]) + (matrix.values[2][1] * values[1][2]) + (matrix.values[2][2] * values[2][2]));
		}

		Matrix3<TVALUE> & operator*=(const Matrix3<TVALUE> &matrix)
		{
			return *this * matrix;
		}

		Matrix3<TVALUE> operator+(const Matrix3<TVALUE> &matrix) const
		{
			return Matrix3<TVALUE>(values[0][0] + matrix.values[0][0],
									values[1][0] + matrix.values[1][0],
									values[2][0] + matrix.values[2][0],
									values[0][1] + matrix.values[0][1],
									values[1][1] + matrix.values[1][1],
									values[2][1] + matrix.values[2][1],
									values[0][2] + matrix.values[0][2],
									values[1][2] + matrix.values[1][2],
									values[2][2] + matrix.values[2][2]);
		}

		Matrix3<TVALUE> & operator+=(const Matrix3<TVALUE> &matrix)
		{
			return *this + matrix;
		}

		Matrix3<TVALUE> operator-(const Matrix3<TVALUE> &matrix) const
		{
			return Matrix3<TVALUE>(values[0][0] - matrix.values[0][0],
									values[1][0] - matrix.values[1][0],
									values[2][0] - matrix.values[2][0],
									values[0][1] - matrix.values[0][1],
									values[1][1] - matrix.values[1][1],
									values[2][1] - matrix.values[2][1],
									values[0][2] - matrix.values[0][2],
									values[1][2] - matrix.values[1][2],
									values[2][2] - matrix.values[2][2]);
		}

		Matrix3<TVALUE> & operator-=(const Matrix3<TVALUE> &matrix)
		{
			return *this - matrix;
		}

		bool operator==(const Matrix3<TVALUE> &matrix)
		{
			for (unsigned char x = 0; x < 3; x++)
				for (unsigned char y = 0; y < 3; y++)
					if (values[x][y] != matrix.values[x][y])
						return false;

			return true;
		}

		void identity()
		{
			set(1, 0, 0, 0, 1, 0, 0, 0, 1);
		}

		void zero()
		{
			operator =(0);
		}

		virtual ~Matrix3()
		{
		}

	};

}

#endif // MATRIX3_H
