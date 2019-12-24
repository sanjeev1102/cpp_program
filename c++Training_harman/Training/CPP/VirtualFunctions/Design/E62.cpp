#include<iostream>
#include<typeinfo>
using namespace std;

namespace Ex62
{
	struct GameObject
	{
		virtual ~GameObject(){}
	};
	//-------------------------------------- 
	struct Ship		 : GameObject{};
	struct Satellite : GameObject{};
	struct Station   : GameObject{};
	//--------------------------------------
	void Collide(GameObject& lhs,GameObject& rhs)
	{
		if((typeid(lhs) == typeid(Ship)) &&
				(typeid(rhs) == typeid(Station)))
			cout<<"ship collided with station"<<endl;
		//.....
	}
};
using namespace Ex62;

void main62()
{
	Ship o1;
	Satellite o2;
	Station o3;

	Collide(o1,o3);
}