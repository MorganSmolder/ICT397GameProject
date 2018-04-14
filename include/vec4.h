#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

class vec4
{
public:
	vec4() {};
	vec4(float x, float y, float z, float w) : vector(x, y, z, w) {};
	vec4(const vec4 & tocpy) : vector(tocpy.vector) {};

	float x() const;
	float y() const;
	float z() const;
	float w() const;
	float sx(float nx);
	float sy(float ny);
	float sz(float nz);
	float sw(float nw);

	vec4 normalise();
	void normailse();
	float dot(const vec4 & rhs);
	float angle(const vec4 & rhs);

	void operator = (const vec4 & rhs);

	float operator [] (int index);

	vec4 operator += (const vec4 & rhs);
	vec4 operator *= (const vec4 & rhs);
	vec4 operator /= (const vec4 & rhs);
	vec4 operator -= (const vec4 & rhs);

	vec4 operator + (const vec4 & rhs);
	vec4 operator * (const vec4 & rhs);
	vec4 operator / (const vec4 & rhs);
	vec4 operator - (const vec4 & rhs);

	vec4 operator + (const float rhs);
	vec4 operator * (const float rhs);
	vec4 operator / (const float rhs);
	vec4 operator - (const float rhs);

	vec4 operator += (const float rhs);
	vec4 operator *= (const float rhs);
	vec4 operator /= (const float rhs);
	vec4 operator -= (const float rhs);

private:
	vec4(const glm::vec4 & tocpy) : vector(tocpy) {};
	glm::vec4 vector;
};