#pragma once
//#include "vec3.h"
#include "Maths.h"
#include "LUAScriptManager.h"
#include "Singleton.h"
#include <string>
#include "Identifiers.h"
#include "MessagingBus.h"
#include "ResourceList.h"
#include "RenderMOduleStubb.h"
#include "Model.h"

/**
* @class GameObject
*
* @brief Container for the game object data.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class GameObject
{
public:
	GameObject();
	GameObject(Identifiers & id, vec3 pos, ResourceList & list);
	~GameObject();

	/**
	* @brief Setter for object id.
	*
	* @param id(int) - New id.
	*
	* @return NONE.
	*/
	void setID(int id);

	/**
	* @brief Getter for object id.
	*
	* @return int - Object id.
	*/
	int getID() const;

	/**
	* @brief Setter for object position.
	*
	* @param pos(vec3) - The new position.
	*
	* @return NONE.
	*/
	void setPos(vec3 pos);

	/**
	* @brief Getter for object position.
	*
	* @return vec3 - Object position.
	*/
	const vec3 & getPos() const;

	/**
	* @brief Getter for object type.
	*
	* @return string - Object type.
	*/
	std::string getType();

	/**
	* @brief Virtual update function for the object.
	*
	* @param time(float) - System time.
	*
	* @return NONE.
	*/
	virtual void update(float time) = 0;

	/**
	* @brief Virtual render function.
	*
	* @return NONE.
	*/
	virtual void render() = 0;

	/**
	* @brief Virtual get offset function.
	*
	* @return vec3 - Center offset.
	*/
	virtual vec3 getCenterOffset() = 0;

	/**
	* @brief Getter for identifiers.
	*
	* @return Identifiers - The object identitfier.
	*/
	const Identifiers &getIdentifiers();

	/**
	* @brief Getter for object state.
	*
	* @return int - Object state.
	*/
	int getState();

	/**
	* @brief Setter for object state,
	*
	* @param state(int) - The state the object is in.
	*
	* @return NONE.
	*/
	void setState(int state);

	/**
	* @brief Setter for the model data.
	*
	* @param M(Model*) - The new model data.
	*
	* @return NONE.
	*/
	void setModel(Model* M);

	/**
	* @brief Getter for the model data.
	*
	* @return Model* - A pointer to the model data.
	*/
	Model* getModel();

	/**
	* @brief Setter for the target position vector.
	*
	* @param target(vec3) - The new target vector.
	*
	* @return NONE.
	*/
	void setTarget(const vec3 target);

	/**
	* @brief Getter for target vector.
	*
	* @return vec3 - Target position vector.
	*/
	const vec3 & getTarget();

protected:
	int state; /// The state the game engine is in.
	vec3 pos; /// The x, y, z position of the game object.
	vec3 target; /// The target position of the game object.
	vec3 targetlook; /// The target look at position of the game object.
	Identifiers id; /// The game objects ID.
	ResourceList resources; /// The resources required for the game object.
	Model* model; /// The model of the object.

	/**
	* @brief Receives messages from other parts of the system.
	*
	* @return NONE.
	*/
	void msgrcvr();
};

