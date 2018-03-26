#pragma once
#include "vec3.h"
#include "LUAScriptManager.h"
#include "Singleton.h"
#include <string>
#include "Identifiers.h"
#include "MessagingBus.h"
#include "ResourceList.h"

class GameObject
{
public:
	GameObject();
	GameObject(Identifiers & id, vec3 pos, ResourceList & list);
	void setID(int id);
	int getID() const;
	void setPos(vec3 pos);
	const vec3 & getPos() const;
	std::string getType();
	virtual void update(float time) = 0;
	virtual void render() = 0;
	const Identifiers &getIdentifiers();
	int getState();
	void setState(int state);

protected:
	int state;
	vec3 pos;
	Identifiers id;
	ResourceList resources;

	void msgrcvr();
};

