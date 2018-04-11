#pragma once

#include "TextureManager.h"
#include "Singleton.h"
#include "AudioEngine.h"
#include "ModelManger.h"

/**
* @class AssetManager
* @brief Provides an  interface to the various resource managing modules.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/

class AssetManager
{
public:
	AssetManager();
	~AssetManager();
	/**
	* @brief Requests for a new resource to be loaded.
	*
	* @param path(string) - Location of the resource on disk.
	* @param type(string) - The type of resource to load.
	* @param name(string) - The handle to be used in calls to utilise resource.
	*
	* @return bool - Wether or not the resource was loaded correctly.
	*/
	bool addResource(std::string path, std::string type, std::string name); 
	
	/**
	* @brief Uses resource with given handle.
	*
	* @param path(string) - Location of the resource on disk.
	* @param type(string) - The type of resource to load.
	* @param name(string) - The handle to be used in calls to utilise resource.
	*
	* @return bool - Wether or not the resource could be successfully used.
	*/
	bool useResource(std::string name);

	/**
	* @brief Adds model with given path, type, name and scale
	*
	* @param path(string) - Location of the resource on disk.
	* @param type(string) - The type of resource to load.
	* @param name(string) - The handle to be used in calls to utilise resource.
	* @param scale(vec3) - The scale of the model
	*
	* @return bool - Wether or not the model could be successfully added.
	*/
	bool addModel(std::string path, std::string type, std::string name, vec3 & scale);

private:
	///Pointer to texture manager module
	TextureManager* TexMan;
	///Pointer to audio manager module
	AudioEngine* AE;
	///Pointer to model manager module
	ModelManger* MM;
};

