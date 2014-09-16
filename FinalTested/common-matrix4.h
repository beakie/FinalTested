#ifndef MATRIX4_H
#define MATRIX4_H

#include "common-imatrix.h"

namespace Common
{

	template <typename TVALUE>
	struct Matrix4 : public IMatrix<TVALUE, unsigned char, Matrix4<TVALUE> >
	{
		TVALUE values[4][4];

		Matrix4()
		{
		}

		Matrix4(const TVALUE value)
		{
			set(value);
		}

		Matrix4(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x4y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x4y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3, const TVALUE x4y3, const TVALUE x1y4, const TVALUE x2y4, const TVALUE x3y4, const TVALUE x4y4)
		{
			set(x1y1, x2y1, x3y1, x4y1, x1y2, x2y2, x3y2, x4y2, x1y3, x2y3, x3y3, x4y3, x1y4, x2y4, x3y4, x4y4);
		}

		Matrix4(const Matrix4<TVALUE> &matrix)
		{
			set(matrix);
		}

		void set(const TVALUE value)
		{
			operator =(value);
		}

		void set(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x3y1, const TVALUE x4y1, const TVALUE x1y2, const TVALUE x2y2, const TVALUE x3y2, const TVALUE x4y2, const TVALUE x1y3, const TVALUE x2y3, const TVALUE x3y3, const TVALUE x4y3, const TVALUE x1y4, const TVALUE x2y4, const TVALUE x3y4, const TVALUE x4y4)
		{
			values[0][0] = x1y1;
			values[0][1] = x1y2;
			values[0][2] = x1y3;
			values[0][3] = x1y4;
			values[1][0] = x2y1;
			values[1][1] = x2y2;
			values[1][2] = x2y3;
			values[1][3] = x2y4;
			values[2][0] = x3y1;
			values[2][1] = x3y2;
			values[2][2] = x3y3;
			values[2][3] = x3y4;
			values[3][0] = x4y1;
			values[3][1] = x4y2;
			values[3][2] = x4y3;
			values[3][3] = x4y4;
		}

		void set(const unsigned char x, const unsigned char y, const TVALUE value)
		{
			values[x][y] = value;
		}

		void set(const Matrix4<TVALUE> &matrix)
		{
			for (unsigned char x = 0; x < 4; x++)
				for (unsigned char y = 0; y < 4; y++)
					values[x][y] = matrix.values[x][y];
		}

		TVALUE get(const unsigned char x, const unsigned char y)
		{
			return values[x][y];
		}

		bool equals(const Matrix4<TVALUE> &matrix)
		{
			return this->operator ==(matrix);
		}

		Matrix4<TVALUE> & multiply(const Matrix4<TVALUE> &matrix)
		{
			return this->operator *(matrix);
		}

		Matrix4<TVALUE> & operator=(const TVALUE &value)
		{
			for (unsigned char x = 0; x < 4; x++)
				for (unsigned char y = 0; y < 4; y++)
					values[x][y] = value;

			return *this;
		}

		Matrix4<TVALUE> & operator=(const Matrix4<TVALUE> &matrix)
		{
			set(matrix);

			return *this;
		}

		Matrix4<TVALUE> operator*(const Matrix4<TVALUE> &matrix) const
		{
			return Matrix4<TVALUE>((matrix.values[0][0] * values[0][0]) + (matrix.values[0][1] * values[1][0]) + (matrix.values[0][2] * values[2][0]) + (matrix.values[0][3] * values[3][0]),
									(matrix.values[1][0] * values[0][0]) + (matrix.values[1][1] * values[1][0]) + (matrix.values[1][2] * values[2][0]) + (matrix.values[1][3] * values[3][0]),
									(matrix.values[2][0] * values[0][0]) + (matrix.values[2][1] * values[1][0]) + (matrix.values[2][2] * values[2][0]) + (matrix.values[2][3] * values[3][0]),
									(matrix.values[3][0] * values[0][0]) + (matrix.values[3][1] * values[1][0]) + (matrix.values[3][2] * values[2][0]) + (matrix.values[3][3] * values[3][0]),
									(matrix.values[0][0] * values[0][1]) + (matrix.values[0][1] * values[1][1]) + (matrix.values[0][2] * values[2][1]) + (matrix.values[0][3] * values[2][1]),
									(matrix.values[1][0] * values[0][1]) + (matrix.values[1][1] * values[1][1]) + (matrix.values[1][2] * values[2][1]) + (matrix.values[1][3] * values[2][1]),
									(matrix.values[2][0] * values[0][1]) + (matrix.values[2][1] * values[1][1]) + (matrix.values[2][2] * values[2][1]) + (matrix.values[2][3] * values[2][1]),
									(matrix.values[3][0] * values[0][1]) + (matrix.values[3][1] * values[1][1]) + (matrix.values[3][2] * values[2][1]) + (matrix.values[3][3] * values[2][1]),
									(matrix.values[0][0] * values[0][2]) + (matrix.values[0][1] * values[1][2]) + (matrix.values[0][2] * values[2][2]) + (matrix.values[0][3] * values[2][2]),
									(matrix.values[1][0] * values[0][2]) + (matrix.values[1][1] * values[1][2]) + (matrix.values[1][2] * values[2][2]) + (matrix.values[1][3] * values[2][2]),
									(matrix.values[2][0] * values[0][2]) + (matrix.values[2][1] * values[1][2]) + (matrix.values[2][2] * values[2][2]) + (matrix.values[2][3] * values[2][2]),
									(matrix.values[3][0] * values[0][2]) + (matrix.values[3][1] * values[1][2]) + (matrix.values[3][2] * values[2][2]) + (matrix.values[3][3] * values[2][2]),
									(matrix.values[0][0] * values[0][3]) + (matrix.values[0][1] * values[1][3]) + (matrix.values[0][2] * values[2][3]) + (matrix.values[0][3] * values[2][3]),
									(matrix.values[1][0] * values[0][3]) + (matrix.values[1][1] * values[1][3]) + (matrix.values[1][2] * values[2][3]) + (matrix.values[1][3] * values[2][3]),
									(matrix.values[2][0] * values[0][3]) + (matrix.values[2][1] * values[1][3]) + (matrix.values[2][2] * values[2][3]) + (matrix.values[2][3] * values[2][3]),
									(matrix.values[3][0] * values[0][3]) + (matrix.values[3][1] * values[1][3]) + (matrix.values[3][2] * values[2][3]) + (matrix.values[3][3] * values[2][3]));
		}

		Matrix4<TVALUE> & operator*=(const Matrix4<TVALUE> &matrix)
		{
			return *this * matrix;
		}

		Matrix4<TVALUE> operator+(const Matrix4<TVALUE> &matrix) const
		{
			return Matrix4<TVALUE>(values[0][0] + matrix.values[0][0],
									values[1][0] + matrix.values[1][0],
									values[2][0] + matrix.values[2][0],
									values[3][0] + matrix.values[3][0],
									values[0][1] + matrix.values[0][1],
									values[1][1] + matrix.values[1][1],
									values[2][1] + matrix.values[2][1],
									values[3][1] + matrix.values[3][1],
									values[0][2] + matrix.values[0][2],
									values[1][2] + matrix.values[1][2],
									values[2][2] + matrix.values[2][2],
									values[3][2] + matrix.values[3][2],
									values[0][3] + matrix.values[0][3],
									values[1][3] + matrix.values[1][3],
									values[2][3] + matrix.values[2][3],
									values[3][3] + matrix.values[3][3]);
		}

		Matrix4<TVALUE> & operator+=(const Matrix4<TVALUE> &matrix)
		{
			return *this + matrix;
		}

		Matrix4<TVALUE> operator-(const Matrix4<TVALUE> &matrix) const
		{
			return Matrix4<TVALUE>(values[0][0] - matrix.values[0][0],
				values[1][0] - matrix.values[1][0],
				values[2][0] - matrix.values[2][0],
				values[3][0] - matrix.values[3][0],
				values[0][1] - matrix.values[0][1],
				values[1][1] - matrix.values[1][1],
				values[2][1] - matrix.values[2][1],
				values[3][1] - matrix.values[3][1],
				values[0][2] - matrix.values[0][2],
				values[1][2] - matrix.values[1][2],
				values[2][2] - matrix.values[2][2],
				values[3][2] - matrix.values[3][2],
				values[0][3] - matrix.values[0][3],
				values[1][3] - matrix.values[1][3],
				values[2][3] - matrix.values[2][3],
				values[3][3] - matrix.values[3][3]);
		}

		Matrix4<TVALUE> & operator-=(const Matrix4<TVALUE> &matrix)
		{
			return *this - matrix;
		}

		bool operator==(const Matrix4<TVALUE> &matrix)
		{
			for (unsigned char x = 0; x < 4; x++)
				for (unsigned char y = 0; y < 4; y++)
					if (values[x][y] != matrix.values[x][y])
						return false;

			return true;
		}

		void identity()
		{
			set(1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1);
		}

		void zero()
		{
			operator =(0);
		}

		virtual ~Matrix4()
		{
		}

	};

}

#endif // MATRIX4_H
