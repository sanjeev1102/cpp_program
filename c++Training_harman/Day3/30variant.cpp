#include <variant>
#include <iostream>
#include<string>
#include<random>
using namespace std;
namespace nm30
{
	void main1()
	{

		variant<int, float> x;
		x = 12;
		cout << get<int>(x) << endl;
		x = 3.45f;
		cout << get<float>(x) << endl;
		try
		{
			cout << get<0>(x) << endl;
		}
		catch (bad_variant_access& err)
		{
			cout << err.what() << endl;
		}
		cout << get<1>(x) << endl;
	}

	template<typename T>
	int typeId{ 100 };
	template<>
	constexpr int typeId<int>{1};
	template<>
	constexpr int typeId<float>{2};
	template<>
	constexpr int typeId<double>{3};

	static_assert(typeId<int> == 1, "not macthing");
	static_assert(typeId<float> == 2, "not macthing");


	template<typename T>
	constexpr T pi1 = T(3.141592353465365);//variable template c++ 14
	void main2()
	{
		cout << pi1<float> << endl;


	}

	void main()
	{
		random_device rd;
		std::mt19937 gen(rd());
		uniform_int_distribution<> dis(100, 1000);

		for (int i = 0; i < 10; i++)
		{
			cout << dis(gen) << "\t";
		}
		cout << endl;

	}

}
