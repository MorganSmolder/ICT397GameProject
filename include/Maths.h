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
	static mat4 setmat4(mat4 mat, float i); // Identity matrix
	static mat4 setmat4(mat4 mat, float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p); // Set all vars
	static vec4 setvec4(vec4 vec, float a, float b, float c, float d);
	static vec3 setvec3(vec3 vec, float a, float b, float c);

	static vec4 mat4Xvec4(mat4 mat, vec4 vec);

	static mat4 translate(mat4 mat, vec3 vec);
	static mat4 rotate(mat4 mat, float angle, vec3 rotv);
	static mat4 scale(mat4 mat, vec3 scalev);
	static 	mat4 perspective(float fovy, float width, float height, float near, float far);
	static vec4 normalize(vec4 vec);
	static vec3 normalize(vec3 vec);
	static float radians(float a);
	static mat4 inverse(mat4 m);
	static mat4 perspective(float a, float b, float c, float d);
	static mat4 translate(mat4 m, vec3 v);

	static mat4 transform(mat4 mat1, mat4 mat2);
	static mat4 transform(mat4 projectionm, mat4 translatem, mat4 rotm);
	static mat4 transform(mat4 translatem, mat4 rotm, mat4 scalem, mat4 mat);
};