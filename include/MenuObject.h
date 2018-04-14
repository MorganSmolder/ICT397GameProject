#pragma once

#include "GameObject.h"

class MenuObject : public GameObject {
	public:	
		MenuObject() {};
		MenuObject(Identifiers & id, vec3 pos, ResourceList & list);
		void update(float time);
		void render();
		bool isCollidable();
		vec3 getCenterOffset();
		void setModel(Model* M);

	private:
		bool visible;
};