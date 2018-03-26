#pragma once
#include "Scene.h"
#include "AudioEngine.h"

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	void addScene(void);
	bool addObject(Identifiers & id, unsigned sceneno, vec3 pos, ResourceList & list);
	int GetGameObjectID(std::string name);
	void update(float time);
	void render();
	void setCurrScene(unsigned sceneno);
	unsigned getNumScenes();
private:
	std::vector<Scene> scenes;
	unsigned currscene;
	Identifiers id;
	
	void initScene(unsigned sceneind);
	void closeScene(unsigned sceneind);
	void msgrcvr();
};

