#include<iostream>
#include<vector>
using namespace std;

namespace Ex27
{
	struct MetaData
	{
		void* Address;
		size_t size;
		MetaData(void* a,size_t s):Address(a),size(s) {}
	};
	//vector of all heap objects
	vector<MetaData> heap;

	//method to traverse all objects in the vector
	void TraverseHeap()
	{
		for(int i=0;i < heap.size();i++)
		{
			cout<<" allocated "<<heap[i].size <<" at "<<heap[i].Address<<endl;
		}
	}
	//***********************************************************************
	struct Managed {} managed;
};
using namespace Ex27;

static void* operator new(size_t size,Managed)
{
		void* pv = ::operator new(size);
		heap.push_back(MetaData(pv,size)); 
		return pv;
}

void main()
{
	int* p1 = new(managed) int();

	double* p2 = new(managed) double();

	int* p3 = new(managed) int();

	TraverseHeap();
}