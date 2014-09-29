#ifndef COMMONARRAY_H
#define COMMONARRAY_H

// add insert functions
// hide addArray in PArray
//any methods with this delete need to be overriden in parray so u can delete items too

namespace Common
{

	template <typename TVALUE, typename TINDEX = UInt_32>
	/// <summary>
	/// 1 dimensional array of values
	/// </summary>
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

			Items = new TVALUE[Capacity];
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
				return *this;

			for (TINDEX i = index; i < (Count - 1); i++)
				Items[i] = Items[i + 1];

			Count--;

			return *this;
		}

		Array<TVALUE, TINDEX>& addItem(const TVALUE item)
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

		void clone(const Array<TVALUE, TINDEX> &array)
		{
			operator =(array);
		}

		TINDEX getIndex(TVALUE value)
		{
			for (TINDEX i = 0; i < Count; i++)
				if (Items[i] == value)
					return i + 1;

			return 0;
		}

		void clear()
		{
			delete[] Items;

			Items = new TVALUE[0];

			Capacity = 0;
			Count = 0;
		}

		Array<TVALUE, TINDEX>& operator =(const Array<TVALUE, TINDEX>& array)
		{
			TVALUE* tmp = new TVALUE[array.capacity];
			Capacity = array.Capacity;
			Count = array.Count;

			for (TINDEX i = 0; i < Count; i++)
				tmp[i] = array.Items[i];

			delete[] Items;

			Items = tmp;

			return *this;
		}

		Array<TVALUE, TINDEX> & operator+=(const TVALUE item)
		{
			if (Count == Capacity)
				resize();

			Items[Count] = item;

			Count++;

			return *this;
		}

		Array<TVALUE, TINDEX> & operator+=(const Array<TVALUE, TINDEX> &array)
		{
			TINDEX arrayCount = array.Count;

			//could be more efficient if only resizes once and then copies all items into the array itself
			for (TINDEX i = 0; i < arrayCount; i++)
				addItem(array.Items[i]);

			return *this;
		}

		Array<TVALUE, TINDEX> & operator++(int)
		{
			resize();

			return *this;
		}

		Array<TVALUE, TINDEX> & operator++() // whats the point?
		{
			resize();

			return *this;
		}

		Array<TVALUE, TINDEX> & operator--(int)
		{
			clear();

			return *this;
		}

		Array<TVALUE, TINDEX> & operator--()
		{
			clear();

			return *this;
		}

		TVALUE & operator[] (TINDEX n)
		{
			return Items[n];
		}

		bool exists(const TVALUE value)
		{
			for (TINDEX i = 0; i < Count; i++)
				if (Items[i] == value)
					return true;

			return false;
		}

		~Array() {
			delete[] Items;
		}
	};

}

#endif // COMMONARRAY_H
