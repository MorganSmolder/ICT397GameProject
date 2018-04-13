#pragma once
#include "GameObject.h"
#include <iostream>
#include "AudioEngine.h"

/**
* @class NPC
*
* @brief Creation for NPCs.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class NPC : public GameObject
{
public:
	NPC(Identifiers & id, vec3 pos, ResourceList & list);
	NPC();
	~NPC();

	/**
	* @brief Update the NPCs
	*
	* @param time(float) - The system time.
	*
	* @return NONE.
	*/
	void update(float time);

	/**
	* @brief Render function.
	*
	* @return NONE.
	*/
	void render();

	/**
	* @brief Get the off set.
	*
	* @return vec3 - The off set vector.
	*/
	vec3 getCenterOffset();
};

