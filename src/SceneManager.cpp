#include "SceneManager.h"


SceneManager::SceneManager()
{
	currscene = 0;
	id.setName("SM");
}


SceneManager::~SceneManager()
{
}

bool SceneManager::addObject(Identifiers & id, unsigned sceneno, vec3 pos, ResourceList & list) {
	if (scenes.size() <= sceneno) return false;
	else return(scenes.at(sceneno).addObject(id, pos, list));
}

void SceneManager::addScene(void ) {
	Scene tmp;
	scenes.push_back(tmp);
	Singleton<AudioEngine>::getInstance()->addChannelSubgroup(scenes.size()-1);
}

void SceneManager::update(float time) {
	msgrcvr();
	scenes.at(currscene).update(time);
}

void SceneManager::render() {
	scenes.at(currscene).render();
}

void SceneManager::setCurrScene(unsigned sceneno) {
	if (sceneno < scenes.size()) {
		closeScene(currscene);
		currscene = sceneno;
		initScene(sceneno);
	}
}

unsigned SceneManager::getNumScenes() {
	return scenes.size();
}

void SceneManager::initScene(unsigned sceneind) {
	Singleton<AudioEngine>::getInstance()->setActiveChannelSubGroup(sceneind);
}

void SceneManager::closeScene(unsigned sceneind) {

}

void SceneManager::msgrcvr() {
	MessagingBus* tmp = Singleton<MessagingBus>::getInstance();

	while (tmp->hasMessage(id)) {
		Message tmpmsg = tmp->getMessage(id);
		if (tmpmsg.getInstruction() == "CS") {
			setCurrScene((unsigned) (currscene + 1) % scenes.size());
		}
	}
}

int  SceneManager::GetGameObjectID(std::string name) {
	int tmpid = -1;
	for (unsigned i = 0; i < scenes.size() && tmpid == -1; i++) {
		tmpid = scenes.at(currscene).GetGameObjectID(name);
	}

	return tmpid;
}