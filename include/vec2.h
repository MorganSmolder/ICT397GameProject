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

	/**
	* @brief Get function for glm::vec2 type variable.
	*
	* @param vector(glm::vec2) - GLM type vector.
	*
	* @return glm::vec2 - GLM type vector.
	*/
	glm::vec2 getVec();

	/**
	* @brief Set function for glm::vec2 type variable.
	*
	* @param vector(glm::vec2) - GLM type vector.
	* @param vec(glm::vec2) - New GLM type vector.
	*
	* @return NONE.
	*/
	void setVec(glm::vec2 vec);

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
	* @brief Overload function for * operator with another vec2 variable.
	*
	* @param v2(vec2) - Vector being multiplied into current vec2.
	* @param tmpglm(glm::vec2) - Temporary glm vec2.
	* @param tmp(vec2) - Temporary vec2.
	*
	* @return vec2 - Calculation.
	*/
	vec2 operator* (vec2 v2)
	{
		glm::vec2 tmpglm;
		tmpglm = vector * v2.getVec();

		vec2 tmp;
		tmp.setVec(tmpglm);
		return tmp;
	}

	/**
	* @brief Return first value (x).
	*
	* @return float - x value.
	*/
	float x();

	/**
	* @brief Return second value (y).
	*
	* @return float - y value.
	*/
	float y();

	/**
	* @brief Add second vector to first.
	*
	* @param vec(vec2) - Second vector being added.
	*
	* @return NONE.
	*/
	void add(vec2 vec);

private:
	glm::vec2 vector; /// GLM type vec2.
};