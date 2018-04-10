#pragma once

#include "Model.h"
#include "ModelFactory.h"
#include <map>

class ModelManger
{
public:
	ModelManger();
	~ModelManger();
	bool loadModel(std::string path, std::string type, std::string name);
	Model* useModel(std::string name);
	Model* getModelRefrence(std::string name);
	bool loadModel(std::string path, std::string type, std::string name, vec3 & scale);

private:
	ModelFactory modelfactory;
	std::map<std::string, Model*> models;
};

