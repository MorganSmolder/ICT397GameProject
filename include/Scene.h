#pragma once
#include "GameObjectHandler.h"
#include "CollisionEngine.h"

/**
* @class Scene
* @brief Class for creating the scene
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class Scene
{
public:
	Scene();
	~Scene();

	/**
	* @brief Add a object to the scene.
	*
	* @param id - The identifier.
	* @param pos - The position vector.
	* @param list - The resource list.
	*
	* @return bool - If the object was added.
	*/
	bool addObject(Identifiers & id, vec3 pos, ResourceList & list);

	/**
	* @brief Update function.
	*
	* @param time - The system clock.
	*/
	void update(float time);

	/**
	* @brief The render method.
	*/
	void render();

	/**
	* @brief Get the game object id.
	*
	* @param name - The game object name.
	*
	* @return int - The game object id.
	*/
	int GetGameObjectID(std::string name);

	/**
	* @brief Get the game object.
	*
	* @param name - The object name.
	*
	* @return GameObject* - The game object pointer.
	*/
	GameObject* GetGameObject(std::string name);

	/**
	* @brief Set the height map.
	*
	* @param hmObj* - The heightmap object.
	*
	* @return bool - If the heightmap was set.
	*/
	bool setHeightMap(GameObject* hmObj);

	/**
	* @brief Attach the terrain to the scene object.
	*
	* @param id - The identifier.
	* @param pos - The position of the heightmap.
	* @param list - The resource list.
	*
	* @return bool - If the terrain was attached.
	*/
	bool attachTerrain(Identifiers & id, vec3 pos, ResourceList & list);

private:
	/// The game object handler.
	GameObjectHandler objects;
	/// The collision object.
	CollisionEngine collision;
};

