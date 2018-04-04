#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

class mat4
{
public:
	glm::mat4 getMat();
	void setMat(glm::mat4 mat);

	/* unsure what type of data is used to store vars in matrix
	float& operator[] (int x)
	{
		return matrix[x];
	}
	*/

	mat4 operator* (mat4 mat2)
	{
		glm::mat4 tmpglm;
		tmpglm = matrix * mat2.getMat();

		mat4 tmp;
		tmp.setMat(tmpglm);
		return tmp;
	}

private:
	glm::mat4 matrix;
};