
#include<iostream>
using namespace std;

namespace nm01
{
	int main() {
		int i = 10, j = 20;

			auto sayHelloWorld = [ i, j ](int p, int q)   // or  auto sayHelloWorld = [ = ](int p, int q)      both are same i.e pass by value. and hence we can not change the value of i and j in side lambda function.
			{
				//i = 20;   // wrong
				//j = 30;   // wrong
				cout << "p + q =  " <<p+q+i+j<< endl;
			};
			

			/*	auto sayHelloWorld = [&i, &j](int p, int q)   // or  auto sayHelloWorld = [ & ](int p, int q)      both are same i.e pass by referance . and hence we can change the value of i and j in side lambda function.
				{
					i = 20;   // correct
					j = 30;   // correct
					cout << "p + q + i + j =  " << p + q + i + j << endl;
				};
				*/

				/*	auto sayHelloWorld = [&i, &j](int p, int q)->int  // or  auto sayHelloWorld = [ & ](int p, int q)      both are same i.e pass by referance . and hence we can change the value of i and j in side lambda function.
					{
						i = 20;   // correct
						j = 30;   // correct
						float f = 5.5;
						return p + q + i + j + f;
					};

					*/


			sayHelloWorld(1, 2);

		return 0;
	}
}