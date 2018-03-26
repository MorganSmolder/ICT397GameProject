#include "GameObjectFactory.h"

GameObjectFactory::GameObjectFactory(){
	nextid = 0;
}

GameObject* GameObjectFactory::create(Identifiers & id, vec3 pos, ResourceList & list){

	GameObject* tmp;

	id.setId(nextid++);

	if (id.getType() == "NPC"){
		tmp = new NPC(id, pos, list);
		return tmp;
	}
	else{
		nextid--;
		return NULL;
	}

}