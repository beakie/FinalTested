//struct Foo
//{
//	unsigned int Count;
//	int* Items;
//
//	Foo()
//	{
//		Count = 0;
//		Items = 0;
//	}
//
//	Foo(const Foo& foo)
//	{
//		Items = 0;
//		swap(&foo, this); // cannot convert argument 1 from 'const Foo' to 'Foo *'
//	}
//
//	Foo(const unsigned int itemCount)
//	{
//		Count = itemCount;
//		Items = new int[itemCount];
//		for (int i = 0; i < itemCount; i++)
//		{
//			Items[i] = 123;
//		}
//	}
//
//	Foo& operator=(const Foo& foo)
//	{
//		swap(&foo, this); // cannot convert argument 1 from 'const Foo' to 'Foo *'
//
//		return *this;
//	}
//
//	void swap(Foo* foo1, Foo* foo2)
//	{
//		unsigned int a(foo1->Count);
//		int* b(foo1->Items);
//
//		foo1->Count = foo2->Count;
//		foo1->Items = foo2->Items;
//
//		foo2->Count = a;
//		foo2->Items = b;
//	}
//
//	~Foo()
//	{
//		delete[] Items;
//	}
//};
