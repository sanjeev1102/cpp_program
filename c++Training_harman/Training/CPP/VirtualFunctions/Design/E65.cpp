#include<iostream>
#include<string>
#include<map>
using namespace std;

namespace Ex65
{
	struct GameObject
	{
		virtual ~GameObject(){}
	};
	//-------------------------------------- 
	struct Ship		 : GameObject{};
	struct Satellite : GameObject{};
	struct Station   : GameObject{};
	//--------------------------------------------------------
	class CollideHandler
	{
		typedef void(CollideHandler:: *FUNPTR)(GameObject& lhs,GameObject& rhs);
		map<string,FUNPTR> vtable;
		//---------------------------------------------------------
		void ShipCollideSatellite(GameObject& lhs,GameObject& rhs)			{	cout<<" ship collide with Satellite"<<endl;	}
		void ShipCollideStation(GameObject& lhs,GameObject& rhs)				{	cout<<" ship collide with Station"<<endl;	}
		void ShipCollideShip(GameObject& lhs,GameObject& rhs)					{	cout<<" ship collide with ship"<<endl;		}
		//-------------------------------------------------- can replace this by command pattern
	public:
		CollideHandler()
		{
			string n1 = typeid(Ship).name();		//can remove rtti
			string n2 = typeid(Satellite).name();
			string n3 = typeid(Station).name();

			vtable[n1 + n2] = &CollideHandler::ShipCollideSatellite;
			vtable[n2 + n1] = &CollideHandler::ShipCollideSatellite;
			vtable[n1 + n3] = &CollideHandler::ShipCollideStation;
			vtable[n3 + n1] = &CollideHandler::ShipCollideStation;
			vtable[n1 + n1] = &CollideHandler::ShipCollideShip;
			//...	
		}

		
		void Collide(GameObject& lhs,GameObject& rhs)
		{
			string nlhs =typeid(lhs).name();		//can remove rtti
			string nrhs =typeid(rhs).name();

			FUNPTR pfun = vtable[nlhs + nrhs];
			((*this).*pfun)(lhs,rhs);
		}
	};
};
using namespace Ex65;

void main65()
{
	Ship o1;		Satellite o2;		Station o3;

	CollideHandler handler;	//can use singleton pattern
	handler.Collide(o1,o3);
}
