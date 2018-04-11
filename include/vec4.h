#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

/**
* @class vec4
* @brief Facade of vec4 GLM functionality.
*
* @author Matthew MacLennan
* @version 1.3
* @date 10 / 04 / 2018
*/
class vec4
{
public:
	vec4();
	vec4(float a, float b, float c, float d);

	/**
	* @brief Get function for glm::vec4 type variable.
	*
	* @param vector(glm::vec4) - GLM type vector.
	*
	* @return glm::vec4 - GLM type vector.
	*/
	glm::vec4 getVec();

	/**
	* @brief Set function for glm::vec4 type variable.
	*
	* @param vector(glm::vec4) - GLM type vector.
	* @param vec(glm::vec4) - New GLM type vector.
	*
	* @return NONE.
	*/
	void setVec(glm::vec4 vec);

	/**
	* @brief Overload function for [] operator to return the value at the location in the vector specified.
	*
	* @param x(int) - Location in vector being requested.
	*
	* @return float& - Data in requested location.
	*/
	float& operator[] (int x)
	{
	return vector[x];
	}

	/**
	* @brief Overload function for * operator with another vec4.
	*
	* @param vec2(vec4) - The second vector.
	* @param tmpglm(glm::vec4) - Temporary glm type vector.
	* @param tmp(vec4) - Temporary vector.
	*
	* @return vec4 - Calcuation.
	*/
	vec4 operator* (vec4 vec2)
	{
		glm::vec4 tmpglm;
		tmpglm = vector * vec2.getVec();

		vec4 tmp;
		tmp.setVec(tmpglm);
		return tmp;
	}

	/**
	* @brief Function to add input vector to current vector.
	*
	* @param vec(vec4) - Vector being added.
	*
	* @return NONE.
	*/
	void add(vec4 vec);

private:
	glm::vec4 vector; /// GLM type vec4.
};