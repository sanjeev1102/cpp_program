#include<iostream>
#include<typeinfo>
using namespace std;

namespace Ex63
{
	struct GameObject
	{
		virtual void Collide(GameObject& rhs)=0;
		virtual void Collide()=0;
		virtual ~GameObject(){}
	};
	//-------------------------------------- 
	struct Ship		 : GameObject
	{
		void Collide(GameObject& rhs) 	{	cout<<"ship collided with";	 rhs.Collide();		}
		void Collide()							{	cout<<" ship "<<endl;									}
	};
	struct Satellite : GameObject
	{
		void Collide(GameObject& rhs) 	{	cout<<"Satellite collided with"; rhs.Collide();}
		void Collide()							{	cout<<" Satellite "<<endl;							}
	};
	struct Station   : GameObject
	{
		void Collide(GameObject& rhs) 	{	cout<<"Station collided with"; rhs.Collide();	}
		void Collide()							{	cout<<" Station "<<endl;								}
	};
	//--------------------------------------
	void Collide(GameObject& lhs,GameObject& rhs)
	{
		lhs.Collide(rhs);
	}
};
using namespace Ex63;

void main63()
{
	Ship o1;
	Satellite o2;
	Station o3;

	Collide(o1,o3);
}