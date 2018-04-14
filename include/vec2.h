#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

class vec2
{
public:
	vec2() {};
	vec2(float x, float y) : vector(x, y) {};
	vec2(const vec2 & tocpy) : vector(tocpy.vector) {};

	float x();
	float y();
	float sx(float nx);
	float sy(float ny);

	vec2 normalise();
	void normailse();
	float dot(const vec2 & rhs);
	float angle(const vec2 & rhs);

	void operator = (const vec2 & rhs);

	float& operator [] (int index);

	vec2 operator += (const vec2 & rhs);
	vec2 operator /= (const vec2 & rhs);
	vec2 operator *= (const vec2 & rhs);
	vec2 operator -= (const vec2 & rhs);

	vec2 operator + (const vec2 & rhs);
	vec2 operator * (const vec2 & rhs);
	vec2 operator / (const vec2 & rhs);
	vec2 operator - (const vec2 & rhs);

	vec2 operator + (const float rhs);
	vec2 operator * (const float rhs);
	vec2 operator / (const float rhs);
	vec2 operator - (const float rhs);

	vec2 operator += (const float rhs);
	vec2 operator *= (const float rhs);
	vec2 operator /= (const float rhs);
	vec2 operator -= (const float rhs);

private:
	vec2(const glm::vec2 & tocpy) : vector(tocpy) {};
	glm::vec2 vector;
};