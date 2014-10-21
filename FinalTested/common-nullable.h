#ifndef COMMONNULLABLE_H
#define COMMONNULLABLE_H

#include "common-bounds_.h"
#include "common-nullablenull.h"

namespace Common
{

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
			Value = nullable.Value;
			HasValue = nullable.HasValue;
		}

		Nullable(const T value)
		{
			Value = value;
			HasValue = true;
		}

		Nullable(const NullableNull& null)
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

		Nullable<T>& operator=(const NullableNull& null)
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

		bool operator==(const NullableNull& null) const
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

		bool operator!=(const NullableNull& null) const
		{
			return false;
		}

		T getValueOrDefault() const
		{
			if (HasValue)
				return Value;
			else
				return getDefault<T>();
		}

		bool isNull() const
		{
			return !HasValue;
		}

		bool isNotNull() const
		{
			return HasValue;
		}

		Nullable<T>& null()
		{
			HasValue = false;

			return *this;
		}

		operator T()
		{
			return getValueOrDefault();
		}

		~Nullable()
		{
		}
	};

}

#endif // COMMONNULLABLE_H