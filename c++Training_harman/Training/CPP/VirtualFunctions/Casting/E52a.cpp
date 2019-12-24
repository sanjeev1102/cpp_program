#include<iostream>
using namespace std;

struct SX {	int x1;	int x2;};
struct SY{	int y1;	int y2;};
struct SZ{	int z1;	int z2;};

void DoJob(SX* px)
{
	px->x1 = 100;	//mov px + 0, 100
	px->x2 = 200;	//mov px + 4, 200
}

struct SA : SY , SX			{};
struct SB : SY , SZ, SX		{};
struct SC  : SX,SY,SZ		{};
struct SD  : SY,SZ			{};

void main()
{
	DoJob(new SX);
	DoJob(new SA);
	DoJob(new SB);
	DoJob(new SC);
	DoJob(new SD);
}