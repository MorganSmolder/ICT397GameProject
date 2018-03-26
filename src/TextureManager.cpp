#include "TextureManager.h"

TextureManager::TextureManager(){
	nextid = 0;
}

bool TextureManager::loadNewTexture(std::string path, std::string type, std::string name, RenderModuleStubb* renderer){
	
	if (images.count(name) == 1) return false;
	
	bool success = ImgCH.CreateImage(path, type);

	if (!success) return false;

	int id = nextid++;

	ImgCH.bindImage(id, renderer);

	images[name] = id;

	return true;
}

bool TextureManager::useTexture(std::string name, RenderModuleStubb* renderer){
	if (images.count(name) == 0) return false;
	renderer->bindTexture(images.at(name));
	return true;
}

bool TextureManager::deleteTexture(std::string name, RenderModuleStubb* renderer){
	if (images.count(name) == 0) return false;
	renderer->deleteTexture(images.at(name));
	images.erase(name);
	return true;
}