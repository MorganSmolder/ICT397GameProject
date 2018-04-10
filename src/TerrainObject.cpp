#include "TerrainObject.h"

TerrainObject::TerrainObject() : GameObject() {

}

TerrainObject::TerrainObject(Identifiers & id, vec3 pos, ResourceList & list) : GameObject(id, pos, list)
{
}


TerrainObject::~TerrainObject()
{
}

void TerrainObject::update(float time) {
	msgrcvr();
}

void TerrainObject::render() {
	if (resources.hasResource("model")) GameObject::model->render(pos);
	else {
		RenderModuleStubb* tmp = Singleton<RenderModuleStubb>::getInstance();

		tmp->DrawQuad(point(pos.x(), pos.y() + 1), point(pos.x() + 1, pos.y()), pos.z());
	}
}

vec3 TerrainObject::getCenterOffset() {
	return vec3(0, 0, 0);
}