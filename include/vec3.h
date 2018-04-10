#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "vec4.h"

class vec3
{
public:
	vec3();
	vec3(float x, float y, float z);
	vec3(vec4 v4); // Used in camera class? unsure why.

	glm::vec3 getVec();
	void setVec(glm::vec3 vec);

	float x() const;
	float y() const;
	float z() const;
	float sx(float nx);
	float sy(float ny);
	float sz(float nz);

	float& operator[] (int x)
	{
	return vector[x];
	}

	vec3 operator* (vec3 vec2)
	{
		glm::vec3 tmpglm;
		tmpglm = vector * vec2.getVec();

		vec3 tmp;
		tmp.setVec(tmpglm);
		return tmp;
	}

	vec3 operator* (float f)
	{
		vector[0] = vector[0] * f;
		vector[1] = vector[1] * f;
		vector[2] = vector[2] * f;

		vec3 tmp;
		tmp.setVec(vector);

		return tmp;
	}

	void operator+= (vec3 v)
	{	
		vec3 tmp;
		tmp.setVec(vector);
		tmp.add(v);

		vector = tmp.getVec();
	}

	void operator-= (vec3 v)
	{
		vec3 tmp;
		tmp.setVec(vector);
		tmp.subtract(v);

		vector = tmp.getVec();
	}

	vec3 operator+ (vec3 v)
	{
		vec3 tmp;
		tmp.setVec(vector);
		tmp.add(v);

		return tmp;
	}

	vec3 operator- (vec3 v)
	{
		vec3 tmp;
		tmp.setVec(vector);
		tmp.subtract(v);

		return tmp;
	}

	vec3 operator- ()
	{
		vec3 tmp;
		tmp.setVec(-vector);
		return tmp;
	}
	
	void subtract(vec3 vec);

	void add(vec3 vec);

private:
	glm::vec3 vector;
};