#pragma once
#include "ImageCreationHandler.h"
#include <map>

class TextureManager
{
public:
	TextureManager();
	bool loadNewTexture(std::string path, std::string type, std::string name, RenderModuleStubb* renderer);
	bool useTexture(std::string name, RenderModuleStubb* renderer);
	bool useTexture(std::string name, std::string name2, RenderModuleStubb* renderer);
	bool deleteTexture(std::string name, RenderModuleStubb* renderer);
	void disableTexture(RenderModuleStubb* renderer);
	bool genMultiTexture(std::vector<vec3> heightmap, std::vector<std::string> textures, std::string name);
	void DisableMultiTex(RenderModuleStubb* renderer);

private:
	std::map<std::string, int> images;
	ImageCreationHandler ImgCH;
	unsigned nextid;
};

