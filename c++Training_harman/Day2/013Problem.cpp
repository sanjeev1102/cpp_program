#include<iostream>
using std::cout;
using std::endl;
namespace nm13
{
	class SmartArray
	{
		int arr[3];
	public:
		SmartArray() :arr{ 11,22,33 }
		{
		}
		class Helper
		{
			int index;
			SmartArray *ptr;
		public:
			Helper(int index, SmartArray *ptr) :index(index), ptr(ptr)
			{
			}
			operator int()
			{
				cout << "Reading done " << endl;
				return ptr->arr[index];
			}
			Helper& operator=(int par)
			{
				cout << "Writing done " << endl;
				ptr->arr[index] = par;
				return *this;
			}
			Helper& operator=(Helper par)
			{
				cout << "Reading/Writing done " << endl;
				ptr->arr[index] = par.ptr->arr[par.index];
				return *this;
			}
		};

		Helper operator[](int index)
		{
			return Helper(index, this);
		}
		friend std::ostream & operator<<(std::ostream& os, SmartArray & par)
		{
			for (int i = 0; i < 3; i++)
			{
				os << "arr[" << i << "]=" << par.arr[i] << endl;
			}
			return os;
		}
	};

	void main()
	{
		SmartArray arrObj;

		int k = arrObj[0];
		arrObj[1] = 999;
		arrObj[2] = arrObj[1];

		cout << arrObj;

		cout << "k=" << k << endl;

	}
}