#ifndef COMMONNULLABLE_H
#define COMMONNULLABLE_H

#include "common-math_.h"

namespace Common
{
	static struct Null
	{
	};

	template <typename T>
	struct Nullable
	{
		T Value;
		bool HasValue;

		Nullable()
		{
			HasValue = false;
		}

		Nullable(const Nullable<T>& nullable)
		{
			operator=(nullable);
		}

		Nullable(const T value)
		{
			Value = value;
			HasValue = true;
		}

		Nullable(const Null null)
		{
			HasValue = false;
		}

		Nullable<T>& operator=(const T value)
		{
			Value = value;
			HasValue = true;

			return *this;
		}

		Nullable<T>& operator=(const Nullable<T>& nullable)
		{
			Value = nullable.Value;
			HasValue = nullable.HasValue;

			return *this;
		}

		Nullable<T>& operator=(const Null& null)
		{
			HasValue = false;

			return *this;
		}

		// +

		Nullable<T> operator+(const Nullable<T>& nullable) const
		{
			Nullable<T> n = *this;

			n += nullable;

			return n;
		}

		Nullable<T>& operator+=(const Nullable<T>& nullable)
		{
			if (!HasValue || !nullable.HasValue)
				HasValue = false;
			else
				Value += nullable.Value;

			return *this;
		}

		Nullable<T> operator+(const T value) const
		{
			Nullable<T> n = *this;

			n += value;

			return n;
		}

		Nullable<T>& operator+=(const T value)
		{
			if (HasValue)
				Value += value;

			return *this;
		}

		// -

		Nullable<T> operator-(const Nullable<T>& nullable) const
		{
			Nullable<T> n = *this;

			n -= nullable;

			return n;
		}

		Nullable<T>& operator-=(const Nullable<T>& nullable)
		{
			if (!HasValue || !nullable.HasValue)
				HasValue = false;
			else
				Value -= nullable.Value;

			return *this;
		}

		Nullable<T> operator-(const T value) const
		{
			Nullable<T> n = *this;

			n -= value;

			return n;
		}

		Nullable<T>& operator-=(const T value)
		{
			if (HasValue)
				Value -= value;

			return *this;
		}

		// *

		Nullable<T> operator*(const Nullable<T>& nullable) const
		{
			Nullable<T> n = *this;

			n *= nullable;

			return n;
		}

		Nullable<T>& operator*=(const Nullable<T>& nullable)
		{
			if (!HasValue || !nullable.HasValue)
				HasValue = false;
			else
				Value *= nullable.Value;

			return *this;
		}

		Nullable<T> operator*(const T value) const
		{
			Nullable<T> n = *this;

			n *= value;

			return n;
		}

		Nullable<T>& operator*=(const T value)
		{
			if (HasValue)
				Value *= value;

			return *this;
		}

		// /

		Nullable<T> operator/(const Nullable<T>& nullable) const
		{
			Nullable<T> n = *this;

			n /= nullable;

			return n;
		}

		Nullable<T>& operator/=(const Nullable<T>& nullable)
		{
			if (!HasValue || !nullable.HasValue)
				HasValue = false;
			else
				Value /= nullable.Value;

			return *this;
		}

		Nullable<T> operator/(const T value) const
		{
			Nullable<T> n = *this;

			n /= value;

			return n;
		}

		Nullable<T>& operator/=(const T value)
		{
			if (HasValue)
				Value /= value;

			return *this;
		}

		// &

		Nullable<T> operator&(const Nullable<T>& nullable) const
		{
			Nullable<T> n = *this;

			n &= nullable;

			return n;
		}

		Nullable<T>& operator&=(const Nullable<T>& nullable)
		{
			if (!HasValue || !nullable.HasValue)
				HasValue = false;
			else
				Value &= nullable.Value;

			return *this;
		}

		Nullable<T> operator&(const T value) const
		{
			Nullable<T> n = *this;

			n &= value;

			return n;
		}

		Nullable<T>& operator&=(const T value)
		{
			if (HasValue)
				Value &= value;

			return *this;
		}

		// |

		Nullable<T> operator|(const Nullable<T>& nullable) const
		{
			Nullable<T> n = *this;

			n |= nullable;

			return n;
		}

		Nullable<T>& operator|=(const Nullable<T>& nullable)
		{
			if (!HasValue || !nullable.HasValue)
				HasValue = false;
			else
				Value |= nullable.Value;

			return *this;
		}

		Nullable<T> operator|(const T value) const
		{
			Nullable<T> n = *this;

			n |= value;

			return n;
		}

		Nullable<T>& operator|=(const T value)
		{
			if (HasValue)
				Value |= value;

			return *this;
		}

		// ==

		bool operator==(const Nullable<T>& nullable) const
		{
			return HasValue && nullable.HasValue && (Value == nullable.Value);
		}

		bool operator==(const T& value) const
		{
			return HasValue && (Value == value);
		}

		bool operator==(const Null& null) const
		{
			return false;
		}

		// !=

		bool operator!=(const Nullable<T>& nullable) const
		{
			return !operator==(nullable);
		}

		bool operator!=(const T& value) const
		{
			return !operator==(value);
		}

		bool operator!=(const Null& null) const
		{
			return false;
		}

		~Nullable()
		{
		}
	};

}

#endif // COMMONNULLABLE_H
