#pragma once

#include "Model.h"
#include "RawTerrain.h"
#include "ImportModel.h"

/**
* @class ModelFactory
*
* @brief Creates models.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class ModelFactory
{
public:
	/**
	* @brief Create the model.
	*
	* @param path(string) - The path of the model.
	* @param type(string) - The type of model.
	* 
	* @return Model* - The model.
	*/
	Model* create(std::string path, std::string type);
};

