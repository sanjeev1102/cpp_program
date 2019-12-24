class CA{
	int a1;	int a2;
};
class CB{
	int b1;int b2;int b3;
};
class CC{
	int c1;double c2;
};
class CX : CB,CA,CC{
	int d1;
};
class CY : CC,CB,CA{
};
class CZ: CA,CB{
	double z1;
};
class CP : CA{
};


void main39A()
{
	CA* p = new CA;

	CA* p2 = new CX; + 12

	CA* p3 = new CZ; +  0

	CA* p4 = new CP; + 0

	p->a1 = 10;
	// mov p + 0, 10

	p2->a1 = 10;
	// mov p + 0, 10

	p3->a1 = 10;
	// mov p + 0, 10

	p4->a1 =  10;
	// mov p + 0, 10

}
/*
void DoJob(CA& p)
{
    p.a1 = 10;
//  mov p + 0, 10	
}



DoJob(new CA)
DoJob(new CX + 12)
DoJob(new Cy + 24)
DoJob(new CZ + 0)
DoJob(new CP + 0)
*/

CB * p;
p->b1 = 10;
//mov p + 0, 10