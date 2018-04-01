#pragma once

#include "ImageLoaderFactory.h"
#include "RenderModuleStubb.h"

class ImageCreationHandler
{
public:
	ImageCreationHandler();
	~ImageCreationHandler();
	bool CreateImage(std::string path, std::string type);
	bool bindImage(const int & id, RenderModuleStubb* renderer);
	void unbindImage(const int & id, RenderModuleStubb* renderer);
	bool CreateMultiTexture(std::vector<vec3> heightmap, std::vector<std::string> textures, std::string name, const int & id);
private:
	ImageLoader* currimage;
};

