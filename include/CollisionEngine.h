#pragma once

#include <map>
#include <vector>
#include "vec3.h"
#include "GameObject.h"

class CollisionEngine
{
public:
	CollisionEngine();
	~CollisionEngine();
	void setHeightMap(std::vector<vec3> & toset);
	void update(GameObject* & toupdate);
private:
	std::map<int, std::map<int, float>> heightmap;

	float linearInterpolate(float a, float b, float f);
	int step;
};

