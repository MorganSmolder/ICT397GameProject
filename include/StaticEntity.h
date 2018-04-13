#pragma once

#include "GameObject.h"

/**
* @class StaticEntity
* @brief A static entity for data.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class StaticEntity : public GameObject
{
public:
	StaticEntity(Identifiers & id, vec3 pos, ResourceList & list);
	StaticEntity();
	~StaticEntity();

	/**
	* @brief The update function.
	*
	* @param time(float) - The system time.
	*
	* @return NONE.
	*/
	void update(float time);

	/**
	* @brief The renderer function.
	*
	* @return NONE.
	*/
	void render();

	/**
	* @brief Get the center offset vector.
	*
	* @return vec3 - The offset vector.
	*/
	vec3 getCenterOffset();
};

