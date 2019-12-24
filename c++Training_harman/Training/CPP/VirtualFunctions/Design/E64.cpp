#include<iostream>
#include<typeinfo>
using namespace std;

namespace Ex64
{
	struct GameObject
	{
		virtual void Collide(GameObject& rhs)=0;
		virtual ~GameObject(){}
	};
	//-------------------------------------- 
	struct Station;
	struct Ship		 : GameObject
	{
		void Collide(GameObject& rhs) 
		{
			if(typeid(rhs) == typeid(Station))
				cout<<"ship collided with station";	 
			//...
		}
	};
	struct Satellite : GameObject
	{
		void Collide(GameObject& rhs) 	{	}
	};
	struct Station   : GameObject
	{
		void Collide(GameObject& rhs) 	{	}
	};
	//--------------------------------------
	void Collide(GameObject& lhs,GameObject& rhs)
	{
		lhs.Collide(rhs);
	}
};
using namespace Ex64;

void main64()
{
	Ship o1;		Satellite o2;	Station o3;
	Collide(o1,o3);
}