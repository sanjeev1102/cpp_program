#include <string>
#include <iostream>
#include <type_traits>
#include <vector>



// C++11 is awesome, but C++14 is even better.

// C++14-compliant compilers are becoming more widespread.
// It is time to leave C++11 behind and move onto the
// newest standard of the language.



// Compiler support:
// * "clang++ 3.5" has full C++14 support.
// * "g++ 5.0" has full C++14 support.

// Refer to the following links for more information:
// * http://en.cppreference.com/w/cpp/compiler_support
// * http://clang.llvm.org/cxx_status.html
// * https://gcc.gnu.org/projects/cxx1y.html

// Let's take a quick look at some the new
// core language features of the C++14 standard:
//
//    * Function return type deduction.
//
//    * `decltype(auto)`.
//
//    * Relaxed constexpr restrictions.
//
//    * Variable templates.
//
//    * Generic lambdas.
//


namespace CPP14LanguageFeatures
{
	// Function return type deduction.
	//
	//    * This feature allows the use of the keyword `auto`
	//      in place of a function's return type.
	//
	//    * You can qualify the `auto` keyword with `const`,
	//      `*`, `&`, etc...
	//
	//    * It follows the same rules as `auto` variable
	//      type deduction.
	//

	auto func0() { return 0; }

	static_assert(std::is_same<decltype(func0()), int>(), "");



	auto func1()
	{
		std::string test{ "hello!" };
		return test;
	}

	static_assert(std::is_same<decltype(func1()), std::string>(), "dfgdfg");



	const auto& func2()
	{
		static std::string test{ "hello again!" };
		return test;
	}

	static_assert(std::is_same<decltype(func2()), const std::string&>(), "");


	// Here are some additional examples:
	template <typename T>
	struct SomeContainerWrapper
	{
		std::vector<const T*> vec;

		typename std::vector<const T*>::iterator beginCPP03() const
		{
			return std::begin(vec);
		}

		auto beginCPP11() const -> decltype(std::begin(vec))
		{
			return std::begin(vec);
		}

		auto beginCPP14() const { return std::begin(vec); }
	};



	template <typename T1, typename T2, typename T3>
	auto complicatedFuncCPP11(T1 x, T2 y, T3 z) -> decltype((x * y) - (y * z))
	{
		return (x * y) - (y * z);
	}

	template <typename T1, typename T2, typename T3>
	auto complicatedFuncCPP14(T1 x, T2 y, T3 z)
	{
		return (x * y) - (y * z);
	}
}

int main001() { return 0; }