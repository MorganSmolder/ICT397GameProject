#include "vec3.h"

glm::vec3 vec3::getVec()
{
	return vector;
}
void vec3::setVec(glm::vec3 vec)
{
	vector = vec;
}

float vec3::x() const
{
	return vector[0];
}

float vec3::y() const
{
	return vector[1];
}

float vec3::z() const
{
	return vector[2];
}

float vec3::sx(float nx)
{
	vector[0] = nx;
	return vector[0];
}

float vec3::sy(float ny)
{
	vector[1] = ny;
	return vector[1];
}

float vec3::sz(float nz)
{
	vector[2] = nz;
	return vector[2];
}

void vec3::add(vec3 vec)
{
	vector[0] = vector[0] + vec.getVec()[0];
	vector[1] = vector[1] + vec.getVec()[1];
	vector[2] = vector[2] + vec.getVec()[2];
}
