#pragma once

#include "GameObject.h"

class StaticEntity : public GameObject
{
public:
	StaticEntity(Identifiers & id, vec3 pos, ResourceList & list);
	StaticEntity();
	~StaticEntity();
	void update(float time);
	void render();
	vec3 getCenterOffset();
};

