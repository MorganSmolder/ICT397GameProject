#include "particle.h"

particle::particle()
{

}

vec3 particle::getPos()
{
	return position;
}

void particle::setPos(vec3 p)
{
	position = p;

}

vec3 particle::getVel()
{
	return velocity;
}

void particle::setVel(vec3 v)
{
	velocity = v;
}

vec4 particle::getColour()
{
	return colour;
}

void particle::setColour(vec4 c)
{
	colour = c;
}

int particle::getLife()
{
	return life;
}

void particle::setLife(int l)
{
	life = l;
}

float particle::getSize()
{
	return size;
}

void particle::setSize(float s)
{
	size = s;
}

bool particle::checkCollision(particle p)
{
	if ((position[0] + size / 2) > (p.getPos()[0] - p.getSize() / 2) && (position[1] + size / 2) > (p.getPos()[1] - p.getSize() / 2) && (position[1] + size / 2) > (p.getPos()[2] - p.getSize() / 2))
	{
		return true;
	}
	else if ((position[0] - size / 2) < (p.getPos()[0] + p.getSize() / 2) && (position[1] - size / 2) < (p.getPos()[1] + p.getSize() / 2) && (position[1] - size / 2) < (p.getPos()[2] + p.getSize() / 2))
	{
		return true;
	}
	return false;
}