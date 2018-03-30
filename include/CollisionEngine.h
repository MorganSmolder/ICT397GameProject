#pragma once

#include <map>
#include <vector>
#include "vec3.h"
#include "vec2.h"
#include "GameObject.h"

struct HMPos {
	vec2 tl;
	vec2 br;
};

class CollisionEngine
{
public:
	CollisionEngine();
	~CollisionEngine();
	void setHeightMap(std::vector<vec3> & toset);
	void update(GameObject* & toupdate);
private:
	std::map<float, std::map<float, float>> heightmap;

	HMPos findHMLocation(const vec3 & pos);
	float findBarycenter(const vec3 & ppos, HMPos & pos);
	int step;

	float maxx, minx, maxz, minz;
};

