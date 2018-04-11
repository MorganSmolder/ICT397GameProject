#pragma once

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"
#include "glm/ext.hpp"
#include "glm/gtc/type_ptr.hpp"

#include "vec4.h"

/**
*@class vec3
* @brief Facade of vec3 GLM functionality.
*
* @author Matthew MacLennan
* @version 1.3
* @date 10 / 04 / 2018
*/
class vec3
{
public:
	vec3();
	vec3(float x, float y, float z);
	vec3(vec4 v4);

	/**
	* @brief Get function for glm::vec3 type variable.
	*
	* @param vector(glm::vec3) - GLM type vector.
	*
	* @return glm::vec3 - GLM type vector.
	*/
	glm::vec3 getVec();

	/**
	* @brief Set function for glm::vec3 type variable.
	*
	* @param vector(glm::vec3) - GLM type vector.
	* @param vec(glm::vec3) - New GLM type vector.
	*
	* @return NONE.
	*/
	void setVec(glm::vec3 vec);

	float x() const;
	float y() const;
	float z() const;
	float sx(float nx);
	float sy(float ny);
	float sz(float nz);

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
	* @brief Overload function for * operator with another vec3 variable.
	*
	* @param vec2(vec3) - The second vector being muliplied.
	* @param tmpglm(glm::vec3) - Temporary GLM vector.
	* @param tmp(vec3) - Temporary vector.
	*
	* @return vec3 - Calculation.
	*/
	vec3 operator* (vec3 vec2)
	{
		glm::vec3 tmpglm;
		tmpglm = vector * vec2.getVec();

		vec3 tmp;
		tmp.setVec(tmpglm);
		return tmp;
	}

	/**
	* @brief Overload function for * operator with a float.
	*
	* @param f(float) - The float being applied to matrix.
	* @param tmpglm(glm::vec3) - Temporary GLM vector.
	* @param tmp(vec3) - Temporary vector.
	*
	* @return vec3 - Calculation.
	*/
	vec3 operator* (float f)
	{
		glm::vec3 tmpglm;
		tmpglm[0] = vector[0] * f;
		tmpglm[1] = vector[1] * f;
		tmpglm[2] = vector[2] * f;

		vec3 tmp;
		tmp.setVec(vector);

		return tmp;
	}

	/**
	* @brief Overload function for += operator with a vec3.
	*
	* @param v(vec3) - Vector being added to the current vector.
	* @param tmp(vec3) - Temporary vector.
	*
	* @return NONE.
	*/
	void operator+= (vec3 v)
	{	
		vec3 tmp;
		tmp.setVec(vector);
		tmp.add(v);

		vector = tmp.getVec();
	}

	/**
	* @brief Overload function for -= operator with a vec3.
	*
	* @param v(vec3) - Vector being subtracted from the current vector.
	* @param tmp(vec3) - Temporary vector.
	*
	* @return NONE.
	*/
	void operator-= (vec3 v)
	{
		vec3 tmp;
		tmp.setVec(vector);
		tmp.subtract(v);

		vector = tmp.getVec();
	}

	/**
	* @brief Overload function for + operator with a vec3.
	*
	* @param v(vec3) - Vector being added to the current vector.
	* @param tmp(vec3) - Temporary vector.
	*
	* @return vec3 - Calculation.
	*/
	vec3 operator+ (vec3 v)
	{
		vec3 tmp;
		tmp.setVec(vector);
		tmp.add(v);

		return tmp;
	}

	/**
	* @brief Overload function for - operator with a vec3.
	*
	* @param v(vec3) - Vector being subtracted from the current vector.
	* @param tmp(vec3) - Temporary vector.
	*
	* @return vec3 - Calculation.
	*/
	vec3 operator- (vec3 v)
	{
		vec3 tmp;
		tmp.setVec(vector);
		tmp.subtract(v);

		return tmp;
	}

	/** 
	* @brief Overload function for - operator to turn vector negative.
	*
	* @param tmp(vec3) - Temporary vector.
	*
	* @return vec3 - Negative vector.
	*/
	vec3 operator- ()
	{
		vec3 tmp;
		tmp.setVec(-vector);
		return tmp;
	}
	
	/**
	* @brief Function to subtract input vector from current vector.
	*
	* @param vec(vec3) - Vector being subtracted.
	* 
	* @return NONE.
	*/
	void subtract(vec3 vec);

	/**
	* @brief Function to add input vector to current vector.
	*
	* @param vec(vec3) - Vector being added.
	*
	* @return NONE.
	*/
	void add(vec3 vec);

private:
	glm::vec3 vector; /// GLM type vec3.
};