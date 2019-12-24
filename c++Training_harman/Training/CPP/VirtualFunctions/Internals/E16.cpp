#include<iostream>
using namespace std;

namespace Ex16
{
	class CA
	{
/*		static FUNPTR ca_vtable[];
		FUNPTR ca_vptr;
		CA():ca_vptr(ca_vtable){}
*/		
	};
	//  FUNPTR CA::ca_vtable[] = {CA::fx1,CA::fx2};
	
	class CB 
	{
/*		static FUNPTR cb_vtable[];
		FUNPTR cb_vptr;
		CB():cb_vptr(cb_vtable){}
*/
	};
	//  FUNPTR CB::cb_vtable[] = {CB::fx3,CB::fx4};

	class CC : public CA, public CB
	{
/*		static FUNPTR cc_ca_vtable[];
		static FUNPTR cc_cb_vtable[];
		CA():ca_vptr(cc_ca_vtable),cb_vptr(cc_cb_vtable){}
*/		
	};
	//  FUNPTR CC::cc_ca_vtable[] = {CC::fx1,CC::fx2,CC:fx5};
	//  FUNPTR CC::cc_cb_vtable[] = {CC::fx3,CC::fx4};
}
using namespace Ex16;

void main16()
{
	cout<<sizeof(CC)<<endl;
}
