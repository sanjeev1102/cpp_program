namespace E38a
{
	struct SA
	{
		SA()
		{
		}
		
		void fun()
		{
			this->SA::SA();
		}
		virtual void fx1() {}	
	};
	struct SB :SA
	{
		virtual void fx1() {}
	};
};
using namespace E38a;

void main38a()
{
	SB obj;
	obj.fun();
	obj.fx1();
} 