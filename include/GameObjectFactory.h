#pragma once

#include <string>
#include "NPC.h"
#include "camera.h"
#include "ModelManger.h"
#include "Singleton.h"
#include "StaticEntity.h"
#include "TerrainObject.h"
#include "MenuObject.h"

class GameObjectFactory
{
public:
	GameObjectFactory();
	GameObject* create(Identifiers & id, vec3 pos, ResourceList & list);
	unsigned nextid;
private:
	bool setModel(GameObject* & GO, std::string model);
};

