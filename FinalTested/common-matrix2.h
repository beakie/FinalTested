#ifndef MATRIX2_H
#define MATRIX2_H

#include "common-imatrix.h"

namespace Common
{

	template <typename TVALUE>
	struct Matrix2 : public IMatrix<TVALUE, unsigned char, Matrix2<TVALUE> >
	{
		TVALUE values[2][2];

		Matrix2()
		{
		}

		Matrix2(const TVALUE value)
		{
			operator =(value);
		}

		Matrix2(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x1y2, const TVALUE x2y2)
		{
			set(x1y1, x2y1, x1y2, x2y2);
		}

		void set(const TVALUE value)
		{
			operator =(value);
		}

		void set(const TVALUE x1y1, const TVALUE x2y1, const TVALUE x1y2, const TVALUE x2y2)
		{
			values[0][0] = x1y1;
			values[0][1] = x1y2;
			values[1][0] = x2y1;
			values[1][1] = x2y2;
		}

		void set(const unsigned char x, const unsigned char y, const TVALUE value)
		{
			values[x][y] = value;
		}

		void set(const Matrix2<TVALUE> &matrix)
		{
			operator =(matrix);
		}

		//////////////
		TVALUE get(const unsigned char x, const unsigned char y)
		{
			return values[x][y];
		}

		//////////////
		bool equals(const Matrix2<TVALUE> &matrix)
		{
			return this->operator ==(matrix);
		}

		//////////////
		Matrix2<TVALUE> & multiply(const Matrix2<TVALUE> &matrix)
		{
			return this->operator *(matrix);
		}

		Matrix2<TVALUE> & operator=(const TVALUE &value)
		{
			values[0][0] = value;
			values[0][1] = value;
			values[1][0] = value;
			values[1][1] = value;

			return *this;
		}

		Matrix2<TVALUE> & operator=(const Matrix2<TVALUE> &matrix)
		{
			values[0][0] = matrix.values[0][0];
			values[0][1] = matrix.values[0][1];
			values[1][0] = matrix.values[1][0];
			values[1][1] = matrix.values[1][1];

			return *this;
		}

		//////////////
		Matrix2<TVALUE> operator*(const Matrix2<TVALUE> &matrix) const
		{
			return Matrix2<TVALUE>((matrix.values[0][0] * values[0][0]) + (matrix.values[0][1] * values[1][0]),
									(matrix.values[1][0] * values[0][0]) + (matrix.values[1][1] * values[1][0]),
									(matrix.values[0][0] * values[0][1]) + (matrix.values[0][1] * values[1][1]),
									(matrix.values[1][0] * values[0][1]) + (matrix.values[1][1] * values[1][1]));
		}

		//////////////
		Matrix2<TVALUE> & operator*=(const Matrix2<TVALUE> &matrix)
		{
			return *this * matrix;
		}

		//////////////
		Matrix2<TVALUE> operator+(const Matrix2<TVALUE> &matrix) const
		{
			return Matrix2<TVALUE>(values[0][0] + matrix.values[0][0],
									values[1][0] + matrix.values[1][0],
									values[0][1] + matrix.values[0][1],
									values[1][1] + matrix.values[1][1]);
		}

		//////////////
		Matrix2<TVALUE> & operator+=(const Matrix2<TVALUE> &matrix)
		{
			return *this + matrix;
		}

		//////////////
		Matrix2<TVALUE> operator-(const Matrix2<TVALUE> &matrix) const
		{
			return Matrix2<TVALUE>(values[0][0] - matrix.values[0][0],
									values[1][0] - matrix.values[1][0],
									values[0][1] - matrix.values[0][1],
									values[1][1] - matrix.values[1][1]);
		}

		//////////////
		Matrix2<TVALUE> & operator-=(const Matrix2<TVALUE> &matrix)
		{
			return *this - matrix;
		}

		//////////////
		bool operator==(const Matrix2<TVALUE> &matrix)
		{
			for (unsigned char x = 0; x < 2; x++)
				for (unsigned char y = 0; y < 2; y++)
					if (values[x][y] != matrix.values[x][y])
						return false;

			return true;
		}

		//////////////
		void identity()
		{
			set(1, 0, 0, 1);
		}

		//////////////
		void zero()
		{
			operator =(0);
		}

		virtual ~Matrix2()
		{
		}

	};

}

#endif // MATRIX2_H
