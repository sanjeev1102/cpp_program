
#include <string>
#include <iostream>
#include <type_traits>

namespace CPP14LanguageFeatures5
{
	// Generic lambdas.
	//
	//    * Lambda function parameters can now be `auto`.
	//
	//    * This effectively makes the lambda behave like
	//      a functor with a templated `operator()`.
	//

	auto l0([](auto x)
	{
		return x * 2;
	});

	static_assert(std::is_same<decltype(l0(1)), int>(), "");

	static_assert(std::is_same<decltype(l0(1.f)), float>(), "");

	static_assert(std::is_same<decltype(l0(1.)), double>(), "");



	// Lambdas can also take variadic parameter packs.
	auto l1([](auto... xs)
	{
		return sizeof...(xs);
	});



	// This lambda...
	auto l2([](auto x, auto y)
	{
		return x * y;
	});

	// ...gets converted to something like this during
	// compilation:
	struct CompilerGeneratedL2
	{
		template <typename T1, typename T2>
		auto operator()(T1 x, T2 y) const
		{
			return x * y;
		}
	};
}

int main005() { 
	using namespace CPP14LanguageFeatures5;
	std::cout << l0(100) << std::endl;
	std::cout << l1(5, 2,5,6) << std::endl;
	std::cout << l2(5, 2) << std::endl;
	return 0; 
}