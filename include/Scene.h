#pragma once
#include "GameObjectHandler.h"
#include "CollisionEngine.h"

/**
* @class Scene
* @brief The scene object.
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
	* @brief Add another game object to the scene.
	*
	* @param id(Identifiers) - The id of the object being added.
	* @param pos(vec3) - The position of the object.
	* @param list(ResourceList) - The resources for the game object.
	*
	* @return bool - If the object was added.
	*/
	bool addObject(Identifiers & id, vec3 pos, ResourceList & list);

	/**
	* @brief Update function
	*
	* @param time(float) - System time.
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
	* @brief Get the game object id.
	*
	* @param name(string) - The game object name.
	*
	* @return int - The game object id.
	*/
	int GetGameObjectID(std::string name);

	/**
	* @brief Get the game object.
	*
	* @param name(string) - The game object name.
	*
	* @return GameObject* - The game object.
	*/
	GameObject* GetGameObject(std::string name);

	/**
	* @brief Set the height map.
	*
	* @param hmObj(GameObject*) - The height map game object.
	*
	* @return bool - If the heightmap was changed.
	*/
	bool setHeightMap(GameObject* hmObj);

private:
	GameObjectHandler objects; /// The object handeler.
	CollisionEngine collision; /// The collision object.
};

