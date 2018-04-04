#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

class mat4
{
public:
	mat4() {};
	mat4(const mat4 & tocpy) : matrix(tocpy.matrix) {};
	
	float & operator [] (int index);

	void operator = (const mat4 & rhs);

	mat4 operator += (const mat4 & rhs);
	mat4 operator *= (const mat4 & rhs);
	mat4 operator /= (const mat4 & rhs);
	mat4 operator -= (const mat4 & rhs);

	mat4 operator + (const mat4 & rhs);
	mat4 operator * (const mat4 & rhs);
	mat4 operator / (const mat4 & rhs);
	mat4 operator - (const mat4 & rhs);

	mat4 operator + (const float rhs);
	mat4 operator * (const float rhs);
	mat4 operator / (const float rhs);
	mat4 operator - (const float rhs);

	mat4 operator += (const float rhs);
	mat4 operator *= (const float rhs);
	mat4 operator /= (const float rhs);
	mat4 operator -= (const float rhs);

private:
	mat4(const glm::mat4 & tocpy) : matrix(tocpy) {};
	glm::mat4 matrix;

};