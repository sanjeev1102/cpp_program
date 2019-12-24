
#include <string>
#include <iostream>
#include <type_traits>

namespace CPP14LanguageFeatures4
{
	// Variable templates.
	//
	//    * C++14 allows the creation of templated variables.
	//
	//    * Variable templates can also be specialized.
	//

	template <typename T>
	//T pi={ 3.14159265359 };
	T pi =  3.14159265359 ;
	void test0()
	{
		auto piFloat(pi<float>);
		auto piDouble(pi<double>);
		std::cout << piDouble << std::endl;
		/*
		auto piInt(pi<int>);
		// Will not compile because narrowing `double` to `int`
		// is not allowed using uniform initialization syntax.
		*/
	}





	
	template <typename T>
	int typeID{ 10 };
	template <>
	constexpr int typeID<int>{0};
	template <>
	constexpr int typeID<float>{1};
	template <>
	constexpr int typeID<double>{2};

	void test1()
	{
		static_assert(typeID<int> == 0, "haha");
		static_assert(typeID<float> == 1, "");
		static_assert(typeID<double> == 2, "");
	}
	

	template<class T>
	constexpr T pi1 = T(3.1415926535897932385L);  // variable template

	template<class T>
	T circular_area(T r) // function template
	{
		return pi1<T> * r * r; // pi<T> is a variable template instantiation
	}



	
}

int main004() {
	using namespace CPP14LanguageFeatures4;
	test0();
	std::cout << circular_area(2.3) << std::endl;
	return 0; }