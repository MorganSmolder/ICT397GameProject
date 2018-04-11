#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "vec4.h"

/**
*@class Mat4
* @brief Facade of mat4 GLM functionality.
*
* @author Matthew MacLennan
* @version 1.3
* @date 10 / 04 / 2018
*/
class mat4
{
public:
	/**
	* @brief Get function for glm::mat4 type variable.
	*
	* @param matrix(glm::mat4) - GLM type matrix.
	*
	* @return glm::mat4 - GLM type matrix.
	*/
	glm::mat4 getMat();

	/**
	* @brief Set function for glm::mat4 type variable.
	*
	* @param matrix(glm::mat4) - GLM type matrix.
	* @param mat(glm::mat4) - New GLM type matrix.
	*
	* @return NONE.
	*/
	void setMat(glm::mat4 mat);

	/**
	* @brief Overload function for * operator with another mat4.
	*
	* @param mat(mat4) - matrix being multiplied to current vector.
	* @param tmpglm(glm::mat4) - Temporary GLM matrix used to store calculation to be returned.
	*
	* @return mat4 - Calculation.
	*/
	mat4 operator* (mat4 mat)
	{
		glm::mat4 tmpglm;
		tmpglm = matrix * mat.getMat();

		mat4 tmp;
		tmp.setMat(tmpglm);
		return tmp;
	}

	/**
	* @brief Overload function for * operator with a vec4.
	*
	* @param v(vec4) - Vector being multiplied to current vector.
	* @param tmpglm(glm::vec4) - Temporary GLM vector used to store calculation to be returned.
	*
	* @return vec4 - Calculation.
	*/
	vec4 operator* (vec4 v)
	{
		glm::vec4 tmpglm;
		tmpglm = matrix * v.getVec;

		vec4 tmp;
		tmp.setVec(tmpglm);

		return tmp;
	}

private:
	glm::mat4 matrix; /// GLM type mat4.
};