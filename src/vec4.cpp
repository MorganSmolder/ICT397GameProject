#include "vec4.h"

glm::vec4 vec4::getVec()
{
	return vector;
}

void vec4::setVec(glm::vec4 vec)
{
	vector = vec;
}

void vec4::add(vec4 vec)
{
	vector[0] = vector[0] + vec.getVec()[0];
	vector[1] = vector[1] + vec.getVec()[1];
	vector[2] = vector[2] + vec.getVec()[2];
	vector[3] = vector[3] + vec.getVec()[3];
}