#pragma once
#include "GameObjectFactory.h"
#include "QuadTree.h"

struct GameObjectWrapper {
	GameObject* pointer;
	GameObjectWrapper(GameObject* insert) { pointer = insert; };
	GameObjectWrapper() {};
};

class GameObjectHandler
{
public:
	GameObjectHandler();
	~GameObjectHandler();

	void setWorldDimensions(float tlx, float tlz, float brx, float brz);
	bool addObject(Identifiers id, vec3 pos, ResourceList & list);
	void update(float time);
	void render();
	std::vector<GameObject*> findSpatiallyGroupedGameObjects(GameObject* tofind);
	int GetGameObjectID(std::string name);

private:
	std::vector<GameObject*> gameobjects;
	QuadTree<GameObjectWrapper> gameobjectQT;
	GameObjectFactory* GOF;

	void refreshTree();

	static std::vector<GameObject*> searchres;
	static pair getposfunc(const GameObjectWrapper & element);
	static void travfunc(const std::vector< std::list<GameObjectWrapper> > & elements, pair topleft, pair bottomright);
	static bool comparisonfunc(const GameObjectWrapper & element, const GameObjectWrapper & comparator);
	static void onFind(const std::vector<std::list<GameObjectWrapper> > & elements, pair topleft, pair bottomright);
};

