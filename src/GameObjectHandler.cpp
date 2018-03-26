#include "GameObjectHandler.h"

std::vector<GameObject*> GameObjectHandler::searchres;

GameObjectHandler::GameObjectHandler()
{
	GOF = Singleton<GameObjectFactory>::getInstance();
}

GameObjectHandler::~GameObjectHandler()
{
	GOF = NULL;
	gameobjectQT.clear();
}

bool GameObjectHandler::addObject(Identifiers id, vec3 pos, ResourceList & list){
	GameObject* tmp = GOF->create(id, pos, list);

	if (tmp == NULL) return false;
	else gameobjects.push_back(tmp);

	return true;
}

void GameObjectHandler::update(float time) {
	refreshTree();
	for (unsigned i = 0; i < gameobjects.size(); i++) {
		gameobjects.at(i)->update(time);
	}
}

int GameObjectHandler::GetGameObjectID(std::string name) {
	int tmpid = -1;
	
	for (unsigned i = 0; i < gameobjects.size() && tmpid == -1; i++) {
		if (gameobjects.at(i)->getIdentifiers().getName() == name) {
			tmpid = (int) gameobjects.at(i)->getID();
		}
	}

	return tmpid;
}

void GameObjectHandler::render() {
	searchres.clear();
	gameobjectQT.traverse(travfunc);
	for (unsigned i = 0; i < searchres.size(); i++) {
		searchres.at(i)->render();
	}
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