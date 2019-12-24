#include<iostream>
#include<typeinfo>
using namespace std;

namespace Ex61
{
	struct GameObject{};
	//-------------------------------------- 
	struct Ship		 : GameObject{};
	struct Satellite : GameObject{};
	struct Station   : GameObject{};
	//--------------------------------------
	void Collide(GameObject& lhs,GameObject& rhs)
	{
		//.....
	}
};
using namespace Ex61;

void main61()
{
	Ship o1;
	Satellite o2;
	Station o3;

	Collide(o1,o3);
}