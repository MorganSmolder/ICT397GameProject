#include "GameObject.h"


GameObject::GameObject() 
{
	state = 0;
	model = NULL;
}

GameObject::GameObject(Identifiers & id, vec3 pos, ResourceList & list) {
	this->id = id;
	this->pos = pos;
	this->resources = list;
	state = 0;
	model = NULL;
}

GameObject::~GameObject() {
	if (model != NULL) delete model;


	model = NULL;
}

const Identifiers  & GameObject::getIdentifiers() {
	return id;
}

int GameObject::getState() {
	return state;
}

void GameObject::setState(int state) {
	this->state = state;
}

void GameObject::setID(int id){
	this->id.setId(id);
}

int GameObject::getID() const{
	return id.getId();
}

void GameObject::setPos(vec3 pos){
	this->pos = pos;
}

const vec3 & GameObject::getPos() const{
	return pos;
}

std::string GameObject::getType(){
	return id.getType();
}

void GameObject::msgrcvr() {
	MessagingBus* tmpmsgbus = Singleton<MessagingBus>::getInstance();

	Message tmpmsg;

	Message tmprmsg;

	while (tmpmsgbus->hasIMessage(this->id.getId())) {
		tmpmsg = tmpmsgbus->getIMessage(this->id.getId());
		if (tmpmsg.getInstruction() == "POS" || tmpmsg.getInstruction() == "LPOS") {
			tmprmsg.setFrom(this->id);
			tmprmsg.setData(this->pos);
			if (tmpmsg.getInstruction() == "POS") tmprmsg.setInstruction("PR");
			else tmprmsg.setInstruction("LPR");
			tmprmsg.setData(tmpmsg.getData().sdata);
			tmpmsgbus->postIMessage(tmprmsg, tmpmsg.getFrom().getId());
		}
	}
}

void GameObject::setModel(Model* M) {
	model = M;
}