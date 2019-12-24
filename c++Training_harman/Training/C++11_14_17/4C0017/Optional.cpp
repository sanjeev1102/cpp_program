#include <string>
#include <functional>
#include <iostream>
#include <optional>
namespace STDOPtional
{
	/*
	The class template std::optional manages an optional contained value,
	i.e. a value that may or may not be present.

	A common use case for optional is the return value of a function
	that may fail. As opposed to other approaches,
	such as std::pair<T,bool>, optional handles
	expensive-to-construct objects well and is more readable,
	as the intent is expressed explicitly.


	The optional object contains a value in the following conditions:

	The object is initialized with/assigned from a value of
	type T or another optional that contains a value.
	The object does not contain a value in the following conditions:

	The object is default-initialized.
	The object is initialized with/assigned from a value of type std::nullopt_t or an optional object that does not contain a value.
	*/
	// optional can be used as the return type of a factory that may fail
	std::optional<std::string> create(bool b) {
		if (b)
			return "Godzilla";
		return {};
	}

	// std::nullopt can be used to create any (empty) std::optional
	auto create2(bool b) {
		return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
	}

	// std::reference_wrapper may be used to return a reference
	auto create_ref(bool b) {
		static std::string value = "Godzilla";
		return b ? std::optional<std::reference_wrapper<std::string>>{value}
		: std::nullopt;
	}

	void main()//void main
	{
		std::cout << "create(false) returned "
			<< create(false).value_or("empty") << '\n';

		// optional-returning factory functions are usable as conditions of while and if
		if (auto str = create2(true)) {
			std::cout << "create2(true) returned " << *str << '\n';
		}

		if (auto str = create_ref(true)) {
			// using get() to access the reference_wrapper's value
			std::cout << "create_ref(true) returned " << str->get() << '\n';
			str->get() = "Mothra";
			std::cout << "modifying it changed it to " << str->get() << '\n';
		}
	}
}