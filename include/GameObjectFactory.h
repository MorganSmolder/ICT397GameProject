#pragma once

#include <string>
#include "GameObject.h"
#include "NPC.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	GameObject* create(Identifiers & id, vec3 pos, ResourceList & list);
	unsigned nextid;
};

