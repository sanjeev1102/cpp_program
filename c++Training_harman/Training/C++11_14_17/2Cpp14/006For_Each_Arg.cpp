#include <iostream>
namespace ex6Part1 {


	// "`for_each_arg` explained and expanded"

	// ----------------------------------------------------------------

	// So, what does `for_each_argument` do?
	// Well, the name is pretty self-explanatory...

	// It invokes a callable object on every passed argument.

	template <class F, class... Args>
	void for_each_argument(F f, Args&&... args)
	{
		[](...)
		{
		}((f(std::forward<Args>(args)), 0)...);
	}

	int main()
	{
		// Prints "hello123".
		for_each_argument(
			[](const auto& x)
		{
			std::cout << x << std::endl;
		},

			"hello", 1, 2, 3);

		std::cout << std::endl;
		return 0;
	}

	// That is cool. How does it work?
	// Let's discover that in the next code segment.
}





//#include <iostream>
namespace ex6Part2 {

	// Let's rewrite the code snippet in a more organized
	// manner, using comments to make obvious what it is
	// actually happening.

	template <typename TF, typename... Ts>
	void forArgs(TF&& mFn, Ts&&... mArgs)
	{
		// Instead of a generic variadic lambda, we can use
		// an `initializer_list` to create a context where
		// variadic parameter expansion can take place.

		// Any "brace-initializable" container works, such as
		// C-style arrays. (Examples: `bool[]`, `int[]`)

		// This guarantees that the arguments will be
		// evaluated in the correct order.

		return (void)std::initializer_list<int>{
			// Every element of the `initializer_list` is an
			// expression enclosed in round parenthesis.
			(
				// In the parenthesis, the result of the `mFn`
				// function call is followed by the comma
				// operator and an integer (zero in this
				// case).

				// Thanks to the comma operator, the expression
				// evaluates to an (unused) integer, which is
				// accepted by the `initializer_list`.

				mFn(
					// As we're taking the variadic arguments by
					// "universal reference", it is important
					// to use `std::forward` to correctly forward
					// their reference types to `mFn`.
					std::forward<Ts>(mArgs)),

				0)...};
	}

	// Still confused? Everything becomes clearer with an example
	// expansion of a `forArgs` call:

	/*
	// The following `forArgs` call...
	forArgs
	(
	[](const auto& x){ std::cout << x << " "; },
	"hello",
	1,
	2,
	3
	);
	// ..roughly expands to...
	(void) std::initializer_list<int>
	{
	([](const auto& x){ std::cout << x; }("hello"), 0),
	([](const auto& x){ std::cout << x; }(1), 0),
	([](const auto& x){ std::cout << x; }(2), 0),
	([](const auto& x){ std::cout << x; }(3), 0)
	}
	// ...which is the same as writing...
	std::cout << "hello";
	std::cout << 1;
	std::cout << 2;
	std::cout << 3;
	*/

	int main006()
	{
		// Prints "hello123".
		forArgs(
			[](const auto& x)
		{
			std::cout << x;
		},

			"hello", 1, 2, 3);

		std::cout << "\n";
		return 0;
	}
}