#include <any>
#include <iostream>
using namespace std;
namespace nm28
{
	void main()
	{
		auto n = 10;

		std::any x = 10;//c++17
		cout << x.type().name() << " " << any_cast<int>(x) << endl;
		x = 3.14159;
		cout << x.type().name() << " " << any_cast<double>(x) << endl;
		x = true;
		cout << x.type().name() << " " << any_cast<bool>(x) << endl;
		x = "sachin";
		cout << x.type().name() << " " << any_cast<const char*>(x) << endl;
		try
		{
			cout << x.type().name() << " " << any_cast<bool>(x) << endl;
		}
		catch (bad_any_cast& e)
		{
			cout << e.what() << endl;
		}
		if (x.has_value())
		{
			cout << x.type().name() << endl;
		}
		x.reset();
	}
}