#pragma once
#include "ImageCreationHandler.h"
#include <map>

class TextureManager
{
public:
	TextureManager();
	bool loadNewTexture(std::string path, std::string type, std::string name, RenderModuleStubb* renderer);
	bool useTexture(std::string name, RenderModuleStubb* renderer);
	bool deleteTexture(std::string name, RenderModuleStubb* renderer);

private:
	std::map<std::string, int> images;
	ImageCreationHandler ImgCH;
	unsigned nextid;
};

