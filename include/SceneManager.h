#pragma once
#include "Scene.h"
#include "AudioEngine.h"
#include "Controls.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void addScene(void);
	bool addObject(Identifiers & id, unsigned sceneno, vec3 pos, ResourceList & list);
	bool attachTerrain(Identifiers & id, unsigned sceneno, vec3 pos, ResourceList & lists);
	int GetGameObjectID(std::string name);
	void update(float time);
	void render();
	void setCurrScene(unsigned sceneno);
	unsigned getNumScenes();
	GameObject* GetGameObject(std::string name);
	bool setSceneHeightMap(unsigned sceneno, GameObject* hmObj);
	bool attachControls(unsigned sceneno, ResourceList toset);

private:
	std::vector<Scene> scenes;
	unsigned currscene;
	Identifiers id;
	
	void initScene(unsigned sceneind);
	void closeScene(unsigned sceneind);
	void msgrcvr();
};

