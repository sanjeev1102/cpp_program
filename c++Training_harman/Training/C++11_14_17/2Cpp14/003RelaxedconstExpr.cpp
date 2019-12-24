
#include <string>
#include <iostream>
#include <type_traits>

namespace CPP14LanguageFeatures
{
	// Relaxed constexpr restrictions.
	//
	//    * Allows `constexpr` functions to have multiple
	//      instructions and common language constructs
	//      such as branches and loops.

	constexpr int computeSomething(int mX)
	{
		int result{ mX };

		for (int i{ 0 }; i < 10; ++i) result += i;

		if (result > 5) result += 10;

		return result;
	}

	template <int TValue>
	struct Test
	{
	};

	// Compiles!
	Test<computeSomething(10)> instance;


	// "constexpr: C++ At Compile Time"


}

int main003() { return 0; }