#pragma once

#include <map>
#include <vector>
#include "Maths.h"
//#include "vec3.h"
//#include "vec2.h"
#include "GameObject.h"

/**
* @struct HMPos
*
* @brief Position of height map.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
struct HMPos {
	vec2 tl;
	vec2 br;
};

/**
* @struct AABB
*
* @brief AABB collider object.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
struct AABB {
	float xmin, ymin, zmin, xmax, ymax, zmax; /// Min and max coord values.
	AABB(float xmx, float xmn, float ymx, float ymn, float zmx, float zmn) : xmax(xmx), xmin(xmn), ymax(ymx), ymin(ymn), zmax(zmx), zmin(zmn) {};
	AABB() {};
};

/**
* @class CollisionEngine
*
* @brief Class handling collision.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class CollisionEngine
{
public:
	CollisionEngine();
	~CollisionEngine();

	/**
	* @brief Setter for height map.
	*
	* @param toset(vector<vec3>) - The new map.
	*
	* @return NONE.
	*/
	void setHeightMap(std::vector<vec3> & toset);

	/**
	* @brief Update function to find collisions with GameObjects.
	*
	* @param toupdate(GameObject* &) - The game object being updated.
	* @param collGO(vector<GameObject*> - Vector of GameObjects to check for collisions with.
	* @param time(float) - The system time.
	*
	* @return NONE.
	*/
	void update(GameObject* & toupdate, std::vector<GameObject*> collGO, float time);
private:
	std::map<float, std::map<float, float>> heightmap; /// Height map data container.

	/**
	* @brief Returns a HMPos type variable from the vec3 variable.
	*
	* @param pos(const vec3 &) - Position of the heightmap.
	*
	* @return HMPos - Height map position.
	*/
	HMPos findHMLocation(const vec3 & pos);

	/**
	* @brief Find the center of a object based.
	*
	* @param ppos(const vec3 &) - Position of the object.
	* @param pos(HMPos &) - Heightmap position.
	*
	* @return float - The center.
	*/
	float findBarycenter(const vec3 & ppos, HMPos & pos);

	float maxx, minx, maxz, minz; /// Max and min X and Z coords.
	bool hasHMap; /// Flag for height map.
};

