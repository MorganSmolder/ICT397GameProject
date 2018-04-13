#pragma once

#include "Model.h"
#include "ModelFactory.h"
#include <map>

/**
* @class ModelManger
*
* @brief The model manger.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class ModelManger
{
public:
	ModelManger();
	~ModelManger();

	/**
	* @brief Load the model.
	*
	* @param path(string) - The path of the model.
	* @param type(string) - The type of model.
	* @param name(string) - The name of the model.
	*
	* @return bool - If the model was laoded.
	*/
	bool loadModel(std::string path, std::string type, std::string name);

	/**
	* @brief Use the model.
	*
	* @param name(string) - The name of the model.
	*
	* @return Model* - A pointer to the model.
	*/
	Model* useModel(std::string name);

	/**
	* @brief Get the model refrence.
	*
	* @param name(string) - The name of the model.
	*
	* @return Model* - The model data.
	*/
	Model* getModelRefrence(std::string name);

	/**
	* @brief Load the model.
	*
	* @param path(string) - The path of the model.
	* @param type(string) - The type of model.
	* @param name(string) - The name of the model.
	* @param scale(vec3) - The scale vector.
	*
	* @return bool - If the model was loaded.
	*/
	bool loadModel(std::string path, std::string type, std::string name, vec3 & scale);

private:
	ModelFactory modelfactory; /// Model factory creation object.
	std::map<std::string, Model*> models; /// A map of models.
};

