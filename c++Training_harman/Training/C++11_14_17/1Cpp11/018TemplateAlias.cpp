#include<iostream>
#include <string>
#include <ios>
#include <vector>
#include <type_traits>
using namespace std;
//*********************************************************************

// type alias, identical to
// typedef std::ios_base::fmtflags flags;
using flags = std::ios_base::fmtflags;
// the name 'flags' now denotes a type:
flags fl = std::ios_base::dec;

void main18_1()
{
cout << typeid(fl).name() <<"="<<fl<< endl;
}


//********************************************************
// type alias, identical to
// typedef void (*func)(int, int);

using func = void(*) (int, int);
// the name 'func' now denotes a pointer to function:
void example(int x, int y) { cout << "x=" << x << " and y=" << y << endl; }
func fn = example;

void main18_2()
{
fn(123, 456);
}

//*********************************using with templates******************************

// template type alias
template<class T> using ptr = T*;
// the name 'ptr<T>' is now an alias for pointer to T
ptr<int> x;

void main18_3()
{
int y = 100;
ptr<int> yPtr = &y;
cout << "y=" << *yPtr<<endl;
cout << typeid(yPtr).name() << "yPtr=" << yPtr <<" and &y="<<&y<< endl;
}


//**********************************************************************

template <class CharT> 
using mystring =std::basic_string<CharT, std::char_traits<CharT>>;
mystring<char> str;

void main18_4()
{
str = "sachin";
cout << str << endl;
cout << typeid(str).name() << endl;
}


//****************************************************************************
// type alias can introduce a member typedef name
template<typename T>
struct Container {
using value_type = T;
};
// which can be used in generic programming
template<typename Container1>
void fn2(const Container1& c,typename Container1::value_type j)
{
typename Container1::value_type n=j;
cout << typeid(n).name() << " and n=" << n << endl;
}

void main18_5()
{
Container<int> con;
fn2(con,909);
}

//***************************************************************************
// type alias used to simplify the syntax of std::enable_if
template <typename T> 
using Invoke = typename T::type;
template <typename Condition> 
using EnableIf = Invoke<std::enable_if<Condition::value>>;
template <typename T, typename = EnableIf<std::is_polymorphic<T>>>
int fpoly_only(T t) {
	cout << "poly called " << endl;
	return 1;
}

template<typename T>
struct ContainerNew {
	using value_type = T;
};

struct S { virtual ~S() {} };
struct S1{};
void main18_6()
{
	ContainerNew<int> con;
	//fpoly_only(con);//error non polymorphic
	S obj;
	fpoly_only(obj);
	S1 obj1;
	//fpoly_only(obj1);//error non polymorphic
}

//****************************************************************************

