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
	virtual vec3 getCenterOffset();
	const Identifiers &getIdentifiers();
	int getState();
	void setState(int state);
	virtual void setModel(Model* M);
	Model* getModel();
	virtual void setTarget(const vec3 target);
	const vec3 & getTarget();
	virtual bool isCollidable();
	virtual bool isVisible();
	virtual void stop();

protected:
	int state;
	vec3 pos;
	vec3 target;
	vec3 targetlook;
	Identifiers id;
	ResourceList resources;
	Model* model;

	GameObject(const GameObject&) {};

	void msgrcvr();
};

