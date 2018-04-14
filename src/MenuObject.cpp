#include "MenuObject.h"


MenuObject::MenuObject(Identifiers & id, vec3 pos, ResourceList & list) : GameObject(id, pos, list){
	visible = false;
}

void MenuObject::render() {
	if (!visible) return;
<<<<<<< HEAD

	if (resources.hasResource("model") && model != NULL){
		RenderModuleStubb* tmp = Singleton<RenderModuleStubb>::getInstance();
		tmp->RenderFacingCamera();
		GameObject::model->render(this->pos);
=======
	
	if (resources.hasResource("model") && model != NULL) GameObject::model->render(this->pos);
	else {
		RenderModuleStubb* tmp = Singleton<RenderModuleStubb>::getInstance();

		tmp->RenderFacingCamera();
		tmp->DrawQuad(point(pos.x(), pos.y() + 1), point(pos.x() + 1, pos.y()), pos.z());
>>>>>>> origin/particles
		tmp->StopRenderFacingCamera();
	}
}

void MenuObject::update(float time) {
<<<<<<< HEAD
	msgrcvr();

	MessagingBus* tmp = Singleton<MessagingBus>::getInstance();
	Message tmpm;

	while (tmp->hasMessage(id)) {

		tmpm = tmp->getMessage(id);

		if (tmpm.getInstruction() == DISPLAY) {
			this->visible = true;
		}
		else
		if (tmpm.getInstruction() == HIDE) {
			this->visible = false;
		}
		else
		if (tmpm.getInstruction() == TOGGLE) {
			this->visible = !this->visible;
		}
	}
=======
	LUAScriptManager* tmp = Singleton<LUAScriptManager>::getInstance();

	msgrcvr();
>>>>>>> origin/particles
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