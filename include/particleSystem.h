#pragma once

#include "particle.h"
#include <vector>

using namespace std;

typedef vector <particle> particleBuffer;

class particleSystem
{
public:
	particleBuffer pb;

	void update();

};

