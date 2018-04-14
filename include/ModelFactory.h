#pragma once

#include "Model.h"
#include "RawTerrain.h"
#include "ImportModel.h"
#include "TexturedSquare.h"

class ModelFactory
{
public:
	ModelFactory();
	Model* create(std::string path, std::string type);
private:
	static unsigned nextid;
};

