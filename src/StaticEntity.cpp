#include "StaticEntity.h"

StaticEntity::StaticEntity() : GameObject() {

}

StaticEntity::StaticEntity(Identifiers & id, vec3 pos, ResourceList & list) : GameObject(id, pos, list)
{
}


StaticEntity::~StaticEntity()
{
}

void StaticEntity::update(float time) {
	msgrcvr();
}

void StaticEntity::render() {
	if (resources.hasResource("model")) GameObject::model->render(pos);
	else {
		RenderModuleStubb* tmp = Singleton<RenderModuleStubb>::getInstance();

		tmp->DrawQuad(point(pos.x(), pos.y() + 1), point(pos.x() + 1, pos.y()), pos.z());
	}
}

vec3 StaticEntity::getCenterOffset() {
	//if (resources.hasResource("model")) {
		//return vec3(model->getMaxX() - model->getMinX(), model->getMaxY() - model->getMinY(), model->getMaxZ() - model->getMinZ());
	//}

	return vec3(0, 0, 0);
}