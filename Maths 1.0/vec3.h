#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

class vec3
{
public:
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

	void add(vec3 vec);

private:
	glm::vec3 vector;
};