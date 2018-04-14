#include "MenuObject.h"


MenuObject::MenuObject(Identifiers & id, vec3 pos, ResourceList & list) : GameObject(id, pos, list){
	visible = false;
}

void MenuObject::render() {
	if (!visible) return;
	
	if (resources.hasResource("model") && model != NULL) GameObject::model->render(this->pos);
	else {
		RenderModuleStubb* tmp = Singleton<RenderModuleStubb>::getInstance();

		tmp->RenderFacingCamera();
		tmp->DrawQuad(point(pos.x(), pos.y() + 1), point(pos.x() + 1, pos.y()), pos.z());
		tmp->StopRenderFacingCamera();
	}
}

void MenuObject::update(float time) {
	LUAScriptManager* tmp = Singleton<LUAScriptManager>::getInstance();

	msgrcvr();
}

vec3 MenuObject::getCenterOffset() {
	if (resources.hasResource("model") && model != NULL) {
		return vec3(0, abs(model->getMaxY()), 0);
	}

	return vec3(0, 0, 0);
}

bool MenuObject::isCollidable(){
	return false;
}

void MenuObject::setModel(Model* M) {
	model = M;
}