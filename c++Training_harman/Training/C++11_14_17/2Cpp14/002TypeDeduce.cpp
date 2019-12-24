
#include <string>
#include <iostream>
#include <type_traits>

namespace CPP14LanguageFeatures
{
	// `decltype(auto)`
	//
	//    * `auto` will always deduce a non-reference type.
	//
	//    * `auto&&` will always deduce a reference type.
	//
	//    * `decltype(auto)` deduces a non-reference or
	//      reference type depending upon the value category
	//      and the nature of a particular expression.
	//

	auto func3()
	{
		static std::string test{ "bye!" };

		auto& result(test);
		return result;
	}

	static_assert(std::is_same<decltype(func3()), std::string>(), "");



	decltype(auto) func4()
	{
		static std::string test{ "bye again!" };

		auto& result(test);
		return result;
	}

	static_assert(std::is_same<decltype(func4()), std::string&>(), "");



	decltype(auto) func5()
	{
		std::string test{ "bye one more time!" };
		return std::move(test);

		// By the way, do not `std::move` things out
		// of a function.
		// This actually returns a reference to a
		// local object, which is not right!
		// Rely on the compiler's RVO (Return Value Optimization), instead.
	}

	static_assert(std::is_same<decltype(func5()), std::string&&>(), "");



	// If you want to know more about type deduction
	// in the latest standard, check out this
	// "Type Deduction in C++14"
	// https://github.com/boostcon/cppnow_presentations_2015/
}

int main002() { return 0; }