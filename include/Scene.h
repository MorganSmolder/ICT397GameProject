#pragma once
#include "GameObjectHandler.h"
#include "CollisionEngine.h"

class Scene
{
public:
	Scene();
	~Scene();
	bool addObject(Identifiers & id, vec3 pos, ResourceList & list);
	void update(float time);
	void render();
	int GetGameObjectID(std::string name);
	GameObject* GetGameObject(std::string name);
	bool setHeightMap(GameObject* hmObj);
	bool attachTerrain(Identifiers & id, vec3 pos, ResourceList & list);

private:
	GameObjectHandler objects;
	CollisionEngine collision;
};

