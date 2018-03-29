#pragma once

#include "TextureManager.h"
#include "Singleton.h"
#include "AudioEngine.h"
#include "ModelManger.h"

class AssetManager
{
public:
	AssetManager();
	~AssetManager();
	bool addResource(std::string path, std::string type, std::string name); 
	bool useResource(std::string name);

private:
	TextureManager* TexMan;
	AudioEngine* AE;
	ModelManger* MM;
};

