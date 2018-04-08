#pragma once

#include "particle.h"
#include <vector>
#include <stdlib.h>
#include "GL/glut.h"


using namespace std;

typedef vector <particle> particleBuffer; // Particle container

class particleSystem
{
public:
	particleBuffer pb; /// Buffer for particles.

	particle generateParticle(); // Used when particles are first created.

	void populateBuffer(); // Populates the buffer with particles.

	bool updateBuffer(); // Updates each particle within the buffer and reuses 'dead' particles.

	void drawBuffer(); // Draw buffer function.
	void drawParticle(particle p); // Draw individual particle function called by draw buffer function.

	// Gets and sets
	vec3 getEPos();
	void setEPos(vec3 p);

private:
	vec3 position; /// Position of effect.
};