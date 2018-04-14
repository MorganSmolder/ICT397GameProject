#pragma once
#include "GameObject.h"

class Bullet : public GameObject
{
public:
	Bullet();
	~Bullet() {};
	Bullet(Identifiers & id, vec3 pos, ResourceList & list);
	void update(float time);
	void render();
	bool isVisible();
	void setTarget(const vec3 target);
private:
	bool inUse;
	float lifespan;
	float timealive;
	float speed;
};

