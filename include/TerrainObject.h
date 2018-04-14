#pragma once
#include "GameObject.h"

<<<<<<< HEAD
=======
/**
* @class TerrainObject
* @brief Class for creating the terrain object
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
>>>>>>> origin/particles
class TerrainObject : public GameObject
{
public:
	TerrainObject();
	TerrainObject(Identifiers & id, vec3 pos, ResourceList & list);
	~TerrainObject();
<<<<<<< HEAD
	void update(float time);
	void render();
	void setModel(Model* M);
=======

	/**
	* @brief The update function.
	*
	* @param time - The system clock.
	*/
	void update(float time);

	/**
	* @brief The render function.
	*/
	void render();

	/**
	* @brief Set the model data.
	* 
	* @param M - The model data.
	*/
	void setModel(Model* M);

	/**
	* @brief Get the off set vector.
	*
	* @return vec3 - The vector off set data.
	*/
>>>>>>> origin/particles
	vec3 getCenterOffset();
};

