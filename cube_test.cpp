#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include "cube.h"
#include "Singmaster.h"

using namespace std;

int main()
{
	cube* RCPoint= new cube();
	//RCPoint->rubik[1+2][0+2][-2+2]=100;
	RCPoint->print();
	RCPoint->readIn("cubestate1.txt");
	RCPoint->print();
	solutions * sol=new Singmaster();
	//cout<<"cpp Point 1.0"<<endl;
	sol->allSteps(*RCPoint);
	//string comm="  R F     S   R'  ";
	/*
	RCPoint->X();
	RCPoint->print();
	RCPoint->Xr();
	RCPoint->print();
	RCPoint->X2();
	*/
	//RCPoint->rotate(comm);
	RCPoint->print();
	delete RCPoint;
	delete sol;
	return 0;
}
