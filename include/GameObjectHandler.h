#pragma once
#include "GameObjectFactory.h"
#include "QuadTree.h"

/**
* @struct GameObjectWrapper
*
* @brief Wrapper for the game object..
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
struct GameObjectWrapper {
	GameObject* pointer;
	GameObjectWrapper(GameObject* insert) { pointer = insert; };
	GameObjectWrapper() {};
};

/**
* @class GameObjectHandler
*
* @brief Handler for game objects.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class GameObjectHandler
{
public:
	GameObjectHandler();
	~GameObjectHandler();

	/**
	* @brief Set the dimensions for the world
	*
	* @param tlx(float) - The closest x dimension.
	* @param tlz(float) - The closest z dimension.
	* @param brx(float) - The furthest x dimension.
	* @param brz(float) - The furthest z dimension.
	*
	* @return NONE.
	*/
	void setWorldDimensions(float tlx, float tlz, float brx, float brz);

	/**
	* @brief Add a game object.
	*
	* @param id(Identifiers) - The ID of the game object.
	* @param pos(vec3) - The position of the object.
	* @param list(ResourceList &) - The resources for the object.
	*
	* @return bool - If the object was added.
	*/
	bool addObject(Identifiers id, vec3 pos, ResourceList & list);

	/**
	* @brief Update a object.
	*
	* @param time(float) - System time.
	*
	* @return NONE.
	*/
	void update(float time);

	/**
	* @brief Render function.
	*
	* @return NONE.
	*/
	void render();

	/**
	* @brief Find game objects that are spatially grouped near the target.
	*
	* @param tofind(GameObject*) - The target game object being looked for.
	*
	* @return vector<GameObject*> - The grouped game objects.
	*/
	std::vector<GameObject*> findSpatiallyGroupedGameObjects(GameObject* tofind);

	/**
	* @brief Get the game object id for a given object name.
	*
	* @param name(string) - The name of the object.
	* 
	* @return int - The id.
	*/
	int GetGameObjectID(std::string name);

	/**
	* @brief Returns the game object with given name.
	*
	* @param name(string) - The name of the game object.
	*
	* @return GameObject* - The pointer for the game object.
	*/
	GameObject* GetGameObject(std::string name);

	/**
	* @brief Get the number of objects being stored.
	*
	* @return unsigned - The number of objects being stored.
	*/
	unsigned getNumObjects();

	/**
	* @brief Get a object based off its index number.
	*
	* @param index(unsigned) - The objects index number.
	*
	* @return GameObject* - The pointer to the game object.
	*/
	GameObject* & getObject(unsigned index);

	/**
	* @brief refresh the quadtree.
	*
	* @return NONE.
	*/
	void refreshTree();

private:
	std::vector<GameObject*> gameobjects; /// The vector for holding pointers to game objects.
	QuadTree<GameObjectWrapper> gameobjectQT; /// The storage for game objects
	GameObjectFactory* GOF; /// Game factory object to create game objects

	static std::vector<GameObject*> searchres; /// The vector to store game objects that have been searched for.

	/**
	* @brief Get the position function of the wrapper.
	* 
	* @param element(GameObjectWrapper) - The game element.
	*
	* @return pair - The position of the function.
	*/
	static pair getposfunc(const GameObjectWrapper & element);

	/**
	* @brief Get the travel function.
	*
	* @param elements(vector<list<GameObjectWrapper>> &) - The elements being stored in a wrapper in a list.
	* @param topleft(pair) - The elements in the top left of the quadtree.
	* @param bottomright(pair) - The elements in the bottom right of the quadtree.
	*
	* @param NONE.
	*/
	static void travfunc(const std::vector< std::list<GameObjectWrapper> > & elements, pair topleft, pair bottomright);

	/**
	* @brief Comparison of two game object wrappers.
	*
	* @param element(GameObjectWrapper &) - The first element for comparison.
	* @param comparator(GameObjectWrapper &) - The second element for comparison.
	*
	* @return bool - If the elements are the same.
	*/
	static bool comparisonfunc(const GameObjectWrapper & element, const GameObjectWrapper & comparator);

	/**
	* @brief Look around the element in the quad tree.
	*
	* @param elements(vector<list<GameObjectWrapper>> &) - The elements.
	* @param topleft(pair) - To the top left of the element.
	* @param bottomright(pair) - To the bottom right of the element.
	*
	* @return NONE.
	*/
	static void onFind(const std::vector<std::list<GameObjectWrapper> > & elements, pair topleft, pair bottomright);
};

