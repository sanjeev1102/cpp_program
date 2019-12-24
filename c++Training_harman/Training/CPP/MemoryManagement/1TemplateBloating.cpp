
//be aware of template bloating
namespace Ex2
{
	class CBase
	{
	public:
		void fun()
		{
		}
	};
	template<typename T>
	class CA : public CBase
	{
	public:
		void fun2(T i)
		{
		}
	};
};
using namespace Ex2;

void main2()
{
	CA<int> obj1;
	CA<float> obj2;
	CA<double> obj3;

	obj1.fun();
	obj1.fun2(100);
	obj2.fun();
	obj2.fun2(100.5f);
	obj3.fun();
	obj3.fun2(100.56);

}
