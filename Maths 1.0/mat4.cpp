#include "mat4.h"

glm::mat4 mat4::getMat()
{
	return matrix;
}

void mat4::setMat(glm::mat4 mat)
{
	matrix = mat;
}