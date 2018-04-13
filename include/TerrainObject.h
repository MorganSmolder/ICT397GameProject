#pragma once
#include "GameObject.h"

/**
* @class TerrainObject
* @brief The terrain object data.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class TerrainObject : public GameObject
{
public:
	TerrainObject();
	TerrainObject(Identifiers & id, vec3 pos, ResourceList & list);
	~TerrainObject();

	/**
	* @brief The update function.
	*
	* @param time(float) - The system time.
	*
	* @return NONE.
	*/
	void update(float time);

	/**
	* @brief The render function.
	*
	* @return NONE.
	*/
	void render();

	/**
	* @brief Get the center offset vector.
	*
	* @return vec3 - The center offset.
	*/
	vec3 getCenterOffset();
};

