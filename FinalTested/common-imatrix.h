#ifndef IMATRIX_H
#define IMATRIX_H

namespace Common
{

	template <typename TVALUE, typename TINDEX, typename TIMPLEMENTATION>
	struct IMatrix
	{
	public:
		virtual void set(const TVALUE value) = 0;
		virtual void set(const TINDEX x, const TINDEX y, const TVALUE value) = 0;
		virtual void set(const TIMPLEMENTATION &matrix) = 0;
		virtual TVALUE get(const TINDEX x, const TINDEX y) = 0;
		virtual bool equals(const TIMPLEMENTATION &matrix) = 0;
		virtual TIMPLEMENTATION & multiply(const TIMPLEMENTATION &matrix) = 0;
		virtual TIMPLEMENTATION & operator=(const TVALUE &value) = 0;
		virtual TIMPLEMENTATION & operator=(const TIMPLEMENTATION &matrix) = 0;
		virtual TIMPLEMENTATION operator*(const TIMPLEMENTATION &matrix) const = 0;
		virtual TIMPLEMENTATION & operator*=(const TIMPLEMENTATION &matrix) = 0;
		virtual TIMPLEMENTATION operator+(const TIMPLEMENTATION &matrix) const = 0;
		virtual TIMPLEMENTATION & operator+=(const TIMPLEMENTATION &matrix) = 0;
		virtual TIMPLEMENTATION operator-(const TIMPLEMENTATION &matrix) const = 0;
		virtual TIMPLEMENTATION & operator-=(const TIMPLEMENTATION &matrix) = 0;
		virtual bool operator==(const TIMPLEMENTATION &matrix) = 0;
		virtual ~IMatrix() { }
	};

}

#endif // IMATRIX_H
