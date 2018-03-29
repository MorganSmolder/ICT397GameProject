#include "ModelManger.h"



ModelManger::ModelManger()
{
}


ModelManger::~ModelManger()
{
	for (std::map<std::string, Model*>::iterator mapit = models.begin(); mapit != models.end(); ++mapit) {
		delete mapit->second;
		mapit->second = NULL;
	}
}

bool ModelManger::loadModel(std::string path, std::string type, std::string name) {
	if (models.count(name) == 1) return false;

	Model* tmp = modelfactory.create(path, type);

	if (tmp == NULL) return false;

	models[name] = tmp;

	return true;
}

Model* ModelManger::useModel(std::string name) {
	if (models.count(name) == 0) {
		return NULL;
	}
	else return models[name]->create();
}