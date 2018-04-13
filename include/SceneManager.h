#pragma once
#include "Scene.h"
#include "AudioEngine.h"
#include "Controls.h"

/**
* @class SceneManager
* @brief The scene manager.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	/**
	* @brief Add a scene.
	*
	* @return NONE.
	*/
	void addScene(void);

	/**
	* @brief Add a object to the scene.
	*
	* @param id(Identifiers) - The game object id.
	*
	* @return bool - If the object was added.
	*/
	bool addObject(Identifiers & id, unsigned sceneno, vec3 pos, ResourceList & list);

	/**
	* @brief Get the game object id.
	*
	* @param name(string) - The name of the game object.
	*
	* @return int - The game object id.
	*/
	int GetGameObjectID(std::string name);

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
	* @brief Set the current scene.
	*
	* @param sceneno(unsigned) - The scene number.
	*
	* @return NONE.
	*/
	void setCurrScene(unsigned sceneno);

	/**
	* @brief Get the number of scenes.
	*
	* @return unsigned - The number of scenes.
	*/
	unsigned getNumScenes();

	/**
	* @brief Get the game object.
	*
	* @param name(string) - The name of the game object.
	*
	* @return GameObject* - The game object.
	*/
	GameObject* GetGameObject(std::string name);
	
	/**
	* @brief The Scene Height map setter.
	*
	* @param sceneno(unsigned) - The scene number.
	* @param hmObj(GameObject*) - The heightmap.
	* 
	* @return bool - If the heightmap was set.
	*/
	bool setSceneHeightMap(unsigned sceneno, GameObject* hmObj);

	/**
	* @brief Attach the controls to the scene.
	*
	* @param sceneno(unsigned) - The scene number.
	* @param toset(ResourceList) - The resources to be set.
	*
	* @return bool - If the controls where set.
	*/
	bool attachControls(unsigned sceneno, ResourceList toset);

private:
	std::vector<Scene> scenes; /// Vector of scenes.
	unsigned currscene; /// Current scene id.
	Identifiers id; /// Identifier for scenes.
	
	/**
	* @brief The initilisation for the scene.
	*
	* @param sceneind(unsigned) - The scene index.
	*
	* @return NONE.
	*/
	void initScene(unsigned sceneind);

	/**
	* @brief Close the scene.
	*
	* @param sceneind(unsigned) - The scene index.
	*
	* @return NONE.
	*/
	void closeScene(unsigned sceneind);

	/**
	* @brief Message receiver.
	*
	* @return NONE.
	*/
	void msgrcvr();
};

