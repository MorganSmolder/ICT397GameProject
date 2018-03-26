#pragma once
#include "GameObject.h"
#include <iostream>


class NPC : public GameObject
{
public:
	NPC(Identifiers & id, vec3 pos, ResourceList & list);
	NPC();
	~NPC();
	void update(float time);
	void render();
};

