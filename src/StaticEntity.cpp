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
	if (resources.hasResource("model")) GameObject::model->render();
	else {
		RenderModuleStubb* tmp = Singleton<RenderModuleStubb>::getInstance();

		tmp->DrawQuad(point(pos.x(), pos.y() + 1), point(pos.x() + 1, pos.y()), pos.z());
	}
}