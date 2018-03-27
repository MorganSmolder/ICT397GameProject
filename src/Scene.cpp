#include "Scene.h"


Scene::Scene()
{
	objects.setWorldDimensions(-100, 1000, 1000, -100);
}


Scene::~Scene()
{
}

void Scene::render() {
	objects.render();
}

bool Scene::addObject(Identifiers & id, vec3 pos, ResourceList & list){
	return objects.addObject(id, pos, list);
}

void Scene::update(float time) {
	objects.update(time);
}

int Scene:: GetGameObjectID(std::string name) {
	return objects.GetGameObjectID(name);
}