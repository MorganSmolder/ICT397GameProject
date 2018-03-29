#include "GameObjectFactory.h"

GameObjectFactory::GameObjectFactory(){
	nextid = 0;
}

GameObject* GameObjectFactory::create(Identifiers & id, vec3 pos, ResourceList & list){

	GameObject* tmp;

	id.setId(nextid++);

	if (id.getType() == "NPC"){
		tmp = new NPC(id, pos, list);
		if (list.hasResource("model")) setModel(tmp, list.getResource("model"));

		return tmp;
	}
	else
	if (id.getType() == "CAM") {
		tmp = new Camera(id, pos, list);
		if (list.hasResource("model")) setModel(tmp, list.getResource("model"));
		return tmp;
	}
	else{
		nextid--;
		return NULL;
	}

}

bool GameObjectFactory::setModel(GameObject* & GO, std::string model) {
	if (GO == NULL) return false;

	Model* tmp = Singleton<ModelManger>::getInstance()->useModel(model);
	
	if (tmp == NULL) return false;

	GO->setModel(tmp);

	return true;
}