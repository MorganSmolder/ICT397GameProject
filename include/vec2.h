#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

/**
*@class vec2
* @brief Facade of vec2 GLM functionality.
*
* @author Matthew MacLennan
* @version 1.3
* @date 10 / 04 / 2018
*/
class vec2
{
public:
	vec2();
	vec2(float a, float b);

	glm::vec2 getVec();
	void setVec(glm::vec2 vec);

	float& operator[] (int x)
	{
	return vector[x];
	}

	vec2 operator* (vec2 v2)
	{
		glm::vec2 tmpglm;
		tmpglm = vector * v2.getVec();

		vec2 tmp;
		tmp.setVec(tmpglm);
		return tmp;
	}

	float x();
	float y();

	void add(vec2 vec);

private:
	glm::vec2 vector; /// GLM type vec2.
};