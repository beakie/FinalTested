#ifndef IMATRIX_H
#define IMATRIX_H

namespace Common
{

	template <typename TVALUE, typename TINDEX, typename TIMPLEMENTATION>
	struct IMatrix
	{
	public:
		/// <summary>
		/// Sets all the values to a single value
		/// </summary>
		virtual void set(const TVALUE value) = 0;
		/// <summary>
		/// Sets specified value
		/// </summary>
		virtual void set(const TINDEX x, const TINDEX y, const TVALUE value) = 0;
		/// <summary>
		/// Copies values from matrix
		/// </summary>
		virtual void set(const TIMPLEMENTATION& matrix) = 0;

		/// <summary>
		/// Gets the value
		/// </summary>
		virtual TVALUE get(const TINDEX x, const TINDEX y) = 0;

		virtual TIMPLEMENTATION& operator = (const TVALUE& value) = 0;
		virtual TIMPLEMENTATION& operator = (const TIMPLEMENTATION& matrix) = 0;

		virtual TIMPLEMENTATION operator + (const TIMPLEMENTATION& matrix) const = 0;
		virtual TIMPLEMENTATION& operator += (const TIMPLEMENTATION& matrix) = 0;
		virtual TIMPLEMENTATION operator - (const TIMPLEMENTATION& matrix) const = 0;
		virtual TIMPLEMENTATION& operator -= (const TIMPLEMENTATION& matrix) = 0;

		virtual TIMPLEMENTATION operator * (const TIMPLEMENTATION& matrix) const = 0;
		virtual TIMPLEMENTATION& operator *= (const TIMPLEMENTATION& matrix) = 0;
		virtual TIMPLEMENTATION operator * (const TVALUE value) const = 0;
		virtual TIMPLEMENTATION& operator *= (const TVALUE value) = 0;

		virtual TIMPLEMENTATION operator / (const TIMPLEMENTATION& matrix) const = 0;
		virtual TIMPLEMENTATION& operator /= (const TIMPLEMENTATION& matrix) = 0;
		virtual TIMPLEMENTATION operator / (const TVALUE value) const = 0;
		virtual TIMPLEMENTATION& operator /= (const TVALUE value) = 0;

		virtual bool operator == (const TIMPLEMENTATION& matrix) const = 0;

		virtual TIMPLEMENTATION& multiply(const TIMPLEMENTATION& matrix) = 0;
		/// <summary>
		/// Scalar multiplication
		/// </summary>
		virtual TIMPLEMENTATION& multiply(const TVALUE value) = 0;
		/// <summary>
		/// Dot product multiplication
		/// </summary>
		virtual TIMPLEMENTATION& dotProduct(const TIMPLEMENTATION& matrix) = 0;
		/// <summary>
		/// Scalar multiplication
		/// </summary>
		virtual TIMPLEMENTATION& scalar(const TVALUE value) = 0;

		/// <summary>
		/// Compares the matrix
		/// </summary>
		virtual bool equals(const TIMPLEMENTATION& matrix) const = 0;

		virtual void identity() = 0;
		virtual void zero() = 0;
		virtual void allOnes() = 0;

		//static TIMPLEMENTATION getIdentity();
		//static TIMPLEMENTATION getZero();
		//static TIMPLEMENTATION getAllOnes();

		virtual ~IMatrix () { }
	};

}

#endif // IMATRIX_H
