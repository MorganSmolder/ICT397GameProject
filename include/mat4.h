#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "vec4.h"

class mat4
{
public:
	glm::mat4 getMat();
	void setMat(glm::mat4 mat);

	/*
	float& operator[] (int x)
	{
		return matrix[x];
	}
	*/

	mat4 operator* (mat4 mat2)
	{
		glm::mat4 tmpglm;
		tmpglm = matrix * mat2.getMat();

		mat4 tmp;
		tmp.setMat(tmpglm);
		return tmp;
	}

	vec4 operator* (vec4 v)
	{
		glm::vec4 tmpglm;
		tmpglm = matrix * v.getVec;

		vec4 tmp;
		tmp.setVec(tmpglm);

		return tmp;
	}

private:
	glm::mat4 matrix;
};