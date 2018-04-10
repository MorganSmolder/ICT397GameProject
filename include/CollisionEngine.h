#pragma once

#include <map>
#include <vector>
#include "Maths.h"
//#include "vec3.h"
//#include "vec2.h"
#include "GameObject.h"

struct HMPos {
	vec2 tl;
	vec2 br;
};

struct AABB {
	float xmin, ymin, zmin, xmax, ymax, zmax;
	AABB(float xmx, float xmn, float ymx, float ymn, float zmx, float zmn) : xmax(xmx), xmin(xmn), ymax(ymx), ymin(ymn), zmax(zmx), zmin(zmn) {};
	AABB() {};
};

class CollisionEngine
{
public:
	CollisionEngine();
	~CollisionEngine();
	void setHeightMap(std::vector<vec3> & toset);
	void update(GameObject* & toupdate, std::vector<GameObject*> collGO, float time);
private:
	std::map<float, std::map<float, float>> heightmap;

	HMPos findHMLocation(const vec3 & pos);
	float findBarycenter(const vec3 & ppos, HMPos & pos);
	float maxx, minx, maxz, minz;
	bool hasHMap;
};

