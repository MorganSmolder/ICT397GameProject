#pragma once
#include "GameObjectHandler.h"

class Scene
{
public:
	Scene();
	~Scene();
	bool addObject(Identifiers & id, vec3 pos, ResourceList & list);
	void update(float time);
	void render();
	int GetGameObjectID(std::string name);

private:
	GameObjectHandler objects;
};

