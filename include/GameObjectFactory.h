#pragma once

#include <string>
#include "GameObject.h"
#include "NPC.h"
#include "camera.h"
#include "ModelManger.h"
#include "Singleton.h"
#include "StaticEntity.h"
#include "TerrainObject.h"

/**
* @class GameObjectFactory
*
* @brief Creates game objects.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class GameObjectFactory
{
public:
	GameObjectFactory();

	/**
	* @brief Create game object.
	*
	* @param id(Identifiers &) - The identifier of the game object.
	* @param pos(vec3) - The position of the game object.
	* @param list(ResourceList &) - The resources for the game object.
	* 
	* @return GameObject* - A pointer to the game object created.
	*/
	GameObject* create(Identifiers & id, vec3 pos, ResourceList & list);

	unsigned nextid; /// The next game object ID.
private:

	/**
	* @brief Set the model for a game object.
	*
	* @param GO(GameObject* &) - The game object.
	* @param model(string) - The model data.
	*
	* @return bool - If the model was set in the game object.
	*/
	bool setModel(GameObject* & GO, std::string model);
};

