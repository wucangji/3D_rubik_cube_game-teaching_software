#ifndef SOLUTIONS_H
#define SOLUTIONS_H

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include "cube.h"

class solutions
{
	public:
		virtual vector<string> allSteps(cube& cub)=0;//this will return all the  steps which will make a cube totally solved
		virtual string someSteps(cube& cub)=0;//this will return some steps and make you achieve a small goal
		virtual string oneRotate(cube& cub)=0;//this will return a recommend rotation that should be helpful
		virtual string hint(cube& cub)=0;//this will return some steps to make your cube turn to a standard state(same state as you can find on a solution guidance)
		virtual int stepNumber(cube& cub)=0;//will return the estimated number of solutions by this algorithm
};



#endif
