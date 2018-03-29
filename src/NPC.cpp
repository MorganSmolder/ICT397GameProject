#include "NPC.h"


NPC::NPC(Identifiers & id, vec3 pos, ResourceList & list) : GameObject( id, pos, list )
{
	
}

NPC::NPC() : GameObject(){

}

NPC::~NPC()
{

}

void NPC::render() {

	if (resources.hasResource("model")) GameObject::model->render();
	else {
		RenderModuleStubb* tmp = Singleton<RenderModuleStubb>::getInstance();

		tmp->DrawQuad(point(pos.x(), pos.z() + 1), point(pos.x() + 1, pos.z()));
	}
}

void NPC::update(float time) {
	LUAScriptManager* tmp = Singleton<LUAScriptManager>::getInstance();

	msgrcvr();

	if(resources.hasResource("msgrcvr")) 
		tmp->callFunction<NPC, MessagingBus>(resources.getResource("msgrcvr"), *this, *(Singleton<MessagingBus>::getInstance()));

	if (resources.hasResource("updatefunc")) 
		tmp->callFunction<NPC, MessagingBus>(resources.getResource("updatefunc"), *this, *(Singleton<MessagingBus>::getInstance()));

}
