#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

class vec4
{
public:
	glm::vec4 getVec();
	void setVec(glm::vec4 vec);

	/* unsure what type of data is used to store vars in matrix
	float& operator[] (int x)
	{
	return vector[x];
	}
	*/
	vec4 operator* (vec4 vec2)
	{
		glm::vec4 tmpglm;
		tmpglm = vector * vec2.getVec();

		vec4 tmp;
		tmp.setVec(tmpglm);
		return tmp;
	}

	void add(vec4 vec);

private:
	glm::vec4 vector;
};