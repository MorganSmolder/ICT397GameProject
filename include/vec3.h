#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

class vec3
{
public:
	vec3() {};
	vec3(float x, float y, float z) : vector(x, y, z) {};
	vec3(const vec3 & tocpy) : vector(tocpy.vector) {};

	float x() const;
	float y() const;
	float z() const;
	float sx(float nx);
	float sy(float ny);
	float sz(float nz);

	vec3 normalise();
	vec3 cross(const vec3 & rhs);
	float dot(const vec3 & rhs);
	float angle(const vec3 & rhs);
	
	void operator = (const vec3 & rhs);

	float& operator [] (int index);

	vec3 operator += (const vec3 & rhs);
	vec3 operator *= (const vec3 & rhs);
	vec3 operator /= (const vec3 & rhs);
	vec3 operator -= (const vec3 & rhs);

	vec3 operator + (const vec3 & rhs);
	vec3 operator * (const vec3 & rhs);
	vec3 operator / (const vec3 & rhs);
	vec3 operator - (const vec3 & rhs);

	vec3 operator + (const float rhs);
	vec3 operator * (const float rhs);
	vec3 operator / (const float rhs);
	vec3 operator - (const float rhs);

	vec3 operator += (const float rhs);
	vec3 operator *= (const float rhs);
	vec3 operator /= (const float rhs);
	vec3 operator -= (const float rhs);

	bool almostEqual(const vec3 & tocompare, float threshold);

	void clear();

	vec3(const glm::vec3 & tocpy) : vector(tocpy) {};

private:

	glm::vec3 vector;
};