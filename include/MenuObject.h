#pragma once

#include "GameObject.h"

<<<<<<< HEAD
=======
/**
* @class MenuObject
* @brief Class for handling the menu
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
>>>>>>> origin/particles
class MenuObject : public GameObject {
	public:	
		MenuObject() {};
		MenuObject(Identifiers & id, vec3 pos, ResourceList & list);
<<<<<<< HEAD
		void update(float time);
		void render();
		bool isCollidable();
		vec3 getCenterOffset();
		void setModel(Model* M);

	private:
=======

		/**
		* @brief Update the menu.
		* 
		* @param time - The system time.
		*/
		void update(float time);

		/**
		* @brief The render function.
		*/
		void render();

		/**
		* @brief If the menu is colliable.
		*
		* @return bool - If the object is collidable.
		*/
		bool isCollidable();

		/**
		* @brief Get the center offset.
		*
		* @return vec3 - The center offset vector.
		*/
		vec3 getCenterOffset();

		/**
		* @brief Set the model.
		*
		* @param M - The model data.
		*/
		void setModel(Model* M);

	private:
		/// Is the menu visable.
>>>>>>> origin/particles
		bool visible;
};