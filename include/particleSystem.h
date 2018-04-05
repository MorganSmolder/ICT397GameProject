#pragma once

#include "particle.h"
#include <vector>
#include <stdlib.h>

using namespace std;

typedef vector <particle> particleBuffer;

class particleSystem
{
public:
	particleBuffer pb;

	vec3 position;
	vec4 colour;

	particle gernerateParticle(); // Used when particles are first created.

	bool updateBuffer();

	virtual void draw()
	{
		// TBD
	}
};

class pExplosion
{
public:

private:
	static int const DEFAULT_NUM_OF_PARTICLES = 150;

	vec3 pos; // Position of the explostion;
	vec4 col; // Colour of the explosion
};

