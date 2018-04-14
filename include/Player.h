#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player(Identifiers & id, vec3 pos, ResourceList & list);
	Player();
	void update(float time);
	void render();
	vec3 getCenterOffset();
	bool isCollidable();
private:
	vec3 front;
};

