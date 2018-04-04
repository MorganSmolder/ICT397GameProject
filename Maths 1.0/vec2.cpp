#include "vec2.h"

glm::vec2 vec2::getVec()
{
	return vector;
}

void vec2::setVec(glm::vec2 vec)
{
	vector = vec;
}

float vec2::x()
{
	return vector[0];
}

float vec2::y()
{
	return vector[1];
}

void vec2::add(vec2 vec)
{
	vector[0] = vector[0] + vec.getVec()[0];
	vector[1] = vector[1] + vec.getVec()[1];
}