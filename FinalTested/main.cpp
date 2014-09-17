
#include <QtCore/QCoreApplication>

#include "common-matrix2.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Common::Matrix2<float> matrix = Common::Matrix2<float>();

	Common::Matrix2<float> matrix2 = Common::Matrix2<float>(matrix);

	return a.exec();
}

//// I have created an interface that takes the implementation as a template parameter.
//
//template<typename T, typename TIMPLEMENTATION>
//struct IStruct
//{
//	virtual TIMPLEMENTATION DoSomething() = 0;
//};
//
//// I implement the interface like this.
//
//template<typename T>
//struct MyStruct : IStruct<T, MyStruct<T>>
//{
//	MyStruct<T> DoSomething()
//	{
//		return MyStruct<T>();
//	}
//};
//
//// I can then call it like so.
//
//int main()
//{
//	MyStruct<int> myStructBasic;
//	myStructBasic.DoSomething(); // <-- return MyStruct<int>.... which is good
//}
//
//// So far, so good.
//
//// If I create a class that inherits from MyStruct, like this...
//
//struct Foo : MyStruct<int>
//{
//};
//
//int main()
//{
//	MyStruct<int> myStructBasic;
//	myStructBasic.DoSomething(); // <-- still returns MyStruct<int> WOOOOOOO
//
//	Foo foo;
//	foo.DoSomething(); // <-- returns MyStruct<int> not Foo. BOOOOOOOOO
//
//}
//
//// So in my head, I imagine doing something like this... which is wrong, I know.
//
//struct Bar : MyStruct<int, Bar>
//{
//};
//
//int main()
//{
//	// So, I would like to be able to get this
//	Bar bar;
//	bar.DoSomething(); // <-- returns Bar
//}
