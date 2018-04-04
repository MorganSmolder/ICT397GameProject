#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "mat4.h"
#include "vec4.h"
#include "vec3.h"
#include "vec2.h"

class Maths
{
public:
	// overload [] for setting matrix 4x4

	// setup for 3x3 matrix using 0's around edges of 4x4

	// overload * operator 4x4 X 4x4 & 4x4 X 3b x1 etc.

	mat4 setmat4(mat4 mat, float i); // Identity matrix
	mat4 setmat4(mat4 mat, float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p); // Set all vars
	vec4 setvec4(vec4 vec, float a, float b, float c, float d);
	vec3 setvec3(vec3 vec, float a, float b, float c);

	vec4 mat4Xvec4(mat4 mat, vec4 vec);

	mat4 translate(mat4 mat, vec3 vec);
	mat4 rotate(mat4 mat, vec3 rotv, float angle);
	mat4 scale(mat4 mat, vec3 scalev);
	mat4 perspective(float fovy, float width, float height, float near, float far);
	vec4 normalize(vec4 vec); //??

	mat4 transform(mat4 mat1, mat4 mat2);
	mat4 transform(mat4 projectionm, mat4 translatem, mat4 rotm);
	mat4 transform(mat4 translatem, mat4 rotm, mat4 scalem, mat4 mat);
};