#include <iostream>
#include<string>
using namespace std;
//1 specialization
template<class T>
void print_list(T value)
{
	cout << value << endl;
}

template<class First, class ...Rest>
void print_list(First first, Rest ...rest)
{
	cout << first << ","; print_list(rest...);
}

void main20_1()
{
	print_list(42, "hello", 2.3, 'a');

}

//************************************************************************
template<typename T>
T Sum(T value)
{
	return value;
}

template<typename T,typename... args> 
T Sum(T first,args... rest)
{
	T val = first + Sum(rest...);
	return val;
}

void main20_2()
{
	cout << Sum(1, 2, 3, 4, 5, 6, 7, 8, 9, 10) << endl;
}






//************************************************************************

void tprintf(const char* format) // base function
{
	std::cout << format;
}

template<typename T, typename... Targs>
void tprintf(const char* format, T value, Targs... Fargs) // recursive variadic function
{
	for (; *format != '\0'; format++) {
		if (*format == '%') {
			std::cout << value;
			tprintf(format + 1, Fargs...); // recursive call
			return;
		}
		std::cout << *format;
	}
}

int main20_3()
{
	tprintf("% world% %\n", "Hello", '!', 123);
	return 0;
}

//****************************************
//1
//variadic templates
template<typename... types>
class MyOverload;
//2
template<typename T, typename... types>
class MyOverload<T, types...> :MyOverload<types...>
{
public:
	using MyOverload<types...>::AddFun;
	void AddFun(T x)
	{
		cout << "AddFun called for type=" << typeid(T).name() << " x= " << x << endl;
	}
};
//3
template<>
class MyOverload<>
{
public:
	//	using MyOverload<T>::AddFun;
	void AddFun()// T x)
	{
		//cout << "AddFun called for type=" << typeid(T).name() <<"x="<<x<< endl;
	}
};

void main20_4()
{
	MyOverload<int, double, string> obj;
	obj.AddFun(10);
	obj.AddFun("sachin");
	obj.AddFun(4.5);
}

//***************************************
// Forward declaration (1st part)
template<typename... Types>
struct ConstVisitor;

// Declaration (2nd part)
template<typename First, typename... Types>
struct ConstVisitor<First, Types...>: ConstVisitor<Types...>
{
	using ConstVisitor<Types...>::visit;
	virtual void visit(const First&) = 0;
};

// Specialized for one (3rd part)
template<typename First>
struct ConstVisitor<First>
{
	virtual void visit(const First&) = 0;
};
// Forwards
struct MyDouble;
struct MyInt;

/// Base class
struct Base
{
	typedef ConstVisitor<MyDouble, MyInt> MyConstVisitor;

	virtual void accept(MyConstVisitor&) = 0;
};

/// Double
struct MyDouble : Base
{
	double x;

	void accept(Base::MyConstVisitor& v)
	{
		v.visit(*this);
	}
};

/// Int
struct MyInt : Base
{
	int x;

	void accept(Base::MyConstVisitor& v)
	{
		v.visit(*this);
	}
};

/// A visitor that does something
struct PrintVisitor : Base::MyConstVisitor
{
	void visit(const MyDouble& x)
	{
		std::cout << "I am a MyDouble: " << x.x << std::endl;
	}

	void visit(const MyInt& x)
	{
		std::cout << "I am a MyInt: " << x.x << std::endl;
	}
};

void main20_5()
{
	PrintVisitor vis;
	MyDouble md;
	md.x = 123.456;
	MyInt mi;
	mi.x = 987;

	Base* b = &md;
	b->accept(vis);
	b = &mi;
	b->accept(vis);

}

//*******************************************************************
//************************nth type of the variadic template class****
template<typename... Types>
struct GetTypeUsingId
{
	// Forward declaration
	template<int id, typename... Types_>
	struct Helper;

	// Declaration
	template<int id, typename TFirst, typename... Types_>
	struct Helper<id, TFirst, Types_...>: Helper<id - 1, Types_...>
	{};

	// Specialized
	template<typename TFirst, typename... Types_>
	struct Helper<0, TFirst, Types_...>
	{
		typedef TFirst DataType;
	};

	template<int id>
	using DataType = typename Helper<id, Types...>::DataType;
};

void main20_6()
{
	typedef GetTypeUsingId<double, int, std::string> MyFoo;
	MyFoo::DataType<0> a(1.23);
	MyFoo::DataType<1> b(123);
	MyFoo::DataType<2> c("Hello");
	std::cout << a << " " << b << " " << c << std::endl;
}

//******************************************