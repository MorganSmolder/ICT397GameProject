#pragma once
#include "vec3.h"
#include "LUAScriptManager.h"
#include "Singleton.h"
#include <string>
#include "Identifiers.h"
#include "MessagingBus.h"
#include "ResourceList.h"
#include "RenderMOduleStubb.h"
#include "Model.h"

class GameObject
{
public:
	GameObject();
	GameObject(Identifiers & id, vec3 pos, ResourceList & list);
	~GameObject();
	void setID(int id);
	int getID() const;
	void setPos(vec3 pos);
	const vec3 & getPos() const;
	std::string getType();
	virtual void update(float time) = 0;
	virtual void render() = 0;
	virtual vec3 getCenterOffset() = 0;
	const Identifiers &getIdentifiers();
	int getState();
	void setState(int state);
	void setModel(Model* M);
	Model* getModel();
	void setTarget(const vec3 target);
	const vec3 & getTarget();

protected:
	int state;
	vec3 pos;
	vec3 target;
	vec3 targetlook;
	Identifiers id;
	ResourceList resources;
	Model* model;

	void msgrcvr();
};

