#ifndef COMMONARRAY_H
#define COMMONARRAY_H

// add insert functions

namespace Common
{

	template <typename TVALUE, typename TINDEX = unsigned int>
	struct Array
	{

	protected:
		TINDEX Capacity;
		TINDEX Count;

	public:
		TVALUE *Items;

		Array()
		{
			Count = 0;
			Capacity = 0;
			Items = new TVALUE[0];
		}

		Array(Array<TVALUE, TINDEX> const &copy) // is this needed?
		{
			Count = copy.Count;
			Capacity = copy.Capacity;

			Items = new TVALUE[Capacity];

			for (TINDEX i = 0; i < Count; i++)
				Items[i] = copy.Items[i];
		}

		TINDEX count() const
		{
			return Count;
		}

		TINDEX capacity() const
		{
			return Capacity;
		}

		Array<TVALUE, TINDEX>& remove(const TINDEX index)
		{
			if (index >= Count)
				return;

			for (TINDEX i = (index + 1); i < Count; i++)
				Items[i] = Items[i - 1];

			Count--;
		}

		Array<TVALUE, TINDEX>& addItem(const TVALUE &item)
		{
			return operator +=(item);
		}

		Array<TVALUE, TINDEX>& addArray(const Array<TVALUE, TINDEX> &array)
		{
			return operator +=(array);
		}

		void resize()
		{
			resize(Capacity ? Capacity * 2 : 1);
		}

		void resize(const TINDEX capacity)
		{
			TVALUE *x = new TVALUE[capacity];

			for (TINDEX i = 0; i < Count; i++)
				x[i] = Items[i];

			delete[] Items;

			Items = x;
			Capacity = capacity;
		}

		void clone(); // equals operator? if not, >> could be clone out, << could be clone in
		TINDEX getIndex();

		void clear()
		{
			delete[] Items;

			Items = new TVALUE[0];

			Capacity = 0;
			Count = 0;
		}

		Array<TVALUE, TINDEX> operator+(const TVALUE &item) const;
		Array<TVALUE, TINDEX> operator+(const Array<TVALUE, TINDEX> &array) const;

		Array<TVALUE, TINDEX> & operator+=(const TVALUE &item)
		{
			if (Count == Capacity)
				resize();

			Items[Count] = item;

			Count++;

			return *this;
		}

		Array<TVALUE, TINDEX> & operator+=(const Array<TVALUE, TINDEX> &array)
		{
			//could be more efficient if only resizes once and then copies all items into the array itself
			for (TINDEX i = 0; i < array.Count; i++)
				addItem(array[i]);

			return *this;
		}

		Array<TVALUE, TINDEX> & operator++(int)
		{
			resize(Count++);

			return *this;
		}

		Array<TVALUE, TINDEX> & operator++()
		{
			return this->operator ++(0);
		}

		Array<TVALUE, TINDEX> & operator--(int)
		{
			clear();

			return *this;
		}

		Array<TVALUE, TINDEX> & operator--()
		{
			return this->operator --(0);
		}

		TVALUE & operator[] (TINDEX n)
		{
			return Items[n];
		}

		bool exists(const TVALUE value)
		{
			return false;
		}

		~Array() {
			delete[] Items;
		}
	};

}

#endif // COMMONARRAY_H
