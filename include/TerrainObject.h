#pragma once
#include "GameObject.h"

class TerrainObject : public GameObject
{
public:
	TerrainObject();
	TerrainObject(Identifiers & id, vec3 pos, ResourceList & list);
	~TerrainObject();
	void update(float time);
	void render();
	vec3 getCenterOffset();
};

