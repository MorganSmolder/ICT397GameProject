#pragma once

#include "Model.h"
#include "RawTerrain.h"
#include "ImportModel.h"

class ModelFactory
{
public:
	Model* create(std::string path, std::string type);
};

