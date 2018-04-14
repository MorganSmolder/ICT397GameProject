#include "GameObjectHandler.h"

std::vector<GameObject*> GameObjectHandler::searchres;

GameObjectHandler::GameObjectHandler()
{
	GOF = Singleton<GameObjectFactory>::getInstance();
	terrain = NULL;
	id.setName("GOH");
}

GameObjectHandler::~GameObjectHandler()
{
	GOF = NULL;
	gameobjectQT.clear();
}

bool GameObjectHandler::addTerrain(Identifiers id, vec3 pos, ResourceList & list) {
	if (id.getType() != "TO") return false;
	
	GameObject* tmp = GOF->create(id, pos, list);

	if (tmp == NULL) return false;

	if (this->terrain != NULL) {
		delete this->terrain;
	}

	this->terrain = tmp;

	return true;
}

bool GameObjectHandler::addObject(Identifiers id, vec3 pos, ResourceList & list){
	GameObject* tmp = GOF->create(id, pos, list);

	if (tmp == NULL) return false;
	else {
		gameobjects.push_back(tmp);
	}
	return true;
}

void GameObjectHandler::msgrcvr() {
	MessagingBus* tmp = Singleton<MessagingBus>::getInstance();
	Message tmpmsg;
	
	while (tmp->hasMessage(id)) {
		tmpmsg = tmp->getMessage(id);
		if (tmpmsg.getInstruction() == ADD_TMP_OBJ) {
			addTmpObj(Identifiers("BLT"), tmpmsg.getData().mvdata.at(0), tmpmsg.getData().mvdata.at(1), ResourceList("model", tmpmsg.getData().sdata));
		}
	}
}

void GameObjectHandler::update(float time) {
	msgrcvr();
	for (unsigned i = 0; i < tmpobjects.size(); i++) {
		tmpobjects.at(i)->update(time);
	}
}

unsigned GameObjectHandler::getNumObjects() {
	return gameobjects.size();
}

GameObject* & GameObjectHandler::getObject(unsigned index) {
	return gameobjects.at(index);
}

int GameObjectHandler::GetGameObjectID(std::string name) {
	int tmpid = -1;
	
	for (unsigned i = 0; i < gameobjects.size() && tmpid == -1; i++) {
		if (gameobjects.at(i)->getIdentifiers().getName() == name) {
			tmpid = (int) gameobjects.at(i)->getID();
		}
	}

	return tmpid;
	
	if (tmpid = -1 && terrain != NULL) {
		if (terrain->getIdentifiers().getName() == name) tmpid = (int) terrain->getID();
	}

	return tmpid;
}

GameObject* GameObjectHandler::GetGameObject(std::string name) {
	GameObject* tmp = NULL;

	for (unsigned i = 0; i < gameobjects.size() && tmp == NULL; i++) {
		if (gameobjects.at(i)->getIdentifiers().getName() == name) {
			tmp = gameobjects.at(i);
		}
	}

	if (tmp == NULL && terrain != NULL) {
		if (terrain->getIdentifiers().getName() == name) tmp = terrain;
	}

	return tmp;
}

void GameObjectHandler::render() {
	searchres.clear();
	gameobjectQT.traverse(travfunc);
	for (unsigned i = 0; i < searchres.size(); i++) {
		searchres.at(i)->render();
	}
	if(terrain != NULL) terrain->render();
	for (unsigned i = 0; i < tmpobjects.size(); i++) {
		tmpobjects.at(i)->render();
	}
}

bool GameObjectHandler::addTmpObj(Identifiers id, vec3 pos, vec3 target, ResourceList model) {
	bool found = false;
	if (model.hasResource("model") == false) return false;
	for (unsigned i = 0; i < tmpobjects.size() && !found; i++) {
		if (tmpobjects.at(i)->isVisible() == false ) {
			found = true;
			tmpobjects.at(i)->setPos(pos);
			tmpobjects.at(i)->setTarget(target);
			if(Singleton<ModelManger>::getInstance()->getModelRefrence(model.getResource("model")) != NULL)
			if(Singleton<ModelManger>::getInstance()->getModelRefrence(model.getResource("model"))->getId() != tmpobjects.at(i)->getModel()->getId())
				tmpobjects.at(i)->setModel(Singleton<ModelManger>::getInstance()->useModel(model.getResource("model")));
		}
	}

	if(found) return true;	

	GameObject * tmp = GOF->create(id, pos, model);

	if (tmp == NULL) return false;

	tmp->setPos(pos);

	tmp->setTarget(target);

	tmpobjects.push_back(tmp);

	return true;
}

void GameObjectHandler::setWorldDimensions(float tlx, float tlz, float brx, float brz) {
	gameobjectQT.setDimensions(pair(tlx, tlz), pair(brx, brz));
}

void  GameObjectHandler::refreshTree() {
	gameobjectQT.clear();
	for (unsigned i = 0; i < gameobjects.size(); i++) {
		gameobjectQT.insert(GameObjectWrapper(gameobjects.at(i)), getposfunc);
	}
}

std::vector<GameObject*> GameObjectHandler::findSpatiallyGroupedGameObjects(GameObject* tofind) {
	searchres.clear();
	gameobjectQT.search(comparisonfunc, onFind, getposfunc, GameObjectWrapper(tofind));
	return searchres;
}

pair GameObjectHandler::getposfunc(const GameObjectWrapper & element) {
	pair temp;

	temp.x = element.pointer->getPos().x();
	temp.z = element.pointer->getPos().z();

	return temp;
}

void  GameObjectHandler::travfunc(const std::vector< std::list<GameObjectWrapper> > & elements, pair topleft, pair bottomright) {
	for (unsigned i = 0; i < elements.size(); i++) {
		for (std::list<GameObjectWrapper>::const_iterator listit = elements.at(i).begin(); listit != elements.at(i).end(); ++listit) {
			searchres.push_back(listit->pointer);
		}
	}
}

bool  GameObjectHandler::comparisonfunc(const GameObjectWrapper & element, const GameObjectWrapper & comparator) {
	if (element.pointer->getID() == comparator.pointer->getID()) {
		return true;
	}

	return false;
}

void  GameObjectHandler::onFind(const std::vector<std::list<GameObjectWrapper> > & elements, pair topleft, pair bottomright) {
	for (unsigned i = 0; i < elements.size(); i++) {
		for (std::list<GameObjectWrapper>::const_iterator listit = elements.at(i).begin(); listit != elements.at(i).end(); ++listit) {
			searchres.push_back(listit->pointer);
		}
	}
}