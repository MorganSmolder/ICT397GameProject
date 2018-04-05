#pragma once

#include "Maths/Maths.h"

class particle
{
public:
	particle();

	vec3 getPos();
	void setPos(vec3 p);

	vec3 getVel();
	void setVel(vec3 v);

	vec4 getColour();
	void setColour(vec4 c);

	int getLife();
	void setLife(int l);

	float getSize();
	void setSize(float s);

	bool checkCollision(particle p);

private:
	vec3 position;
	vec3 velocity;
	vec4 colour;
	int life;
	float size;
};

