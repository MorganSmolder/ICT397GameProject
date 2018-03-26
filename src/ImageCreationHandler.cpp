#include "ImageCreationHandler.h"


ImageCreationHandler::ImageCreationHandler()
{
	currimage = NULL;
}


ImageCreationHandler::~ImageCreationHandler()
{
	if (currimage != NULL){
		currimage->clear();
		delete currimage;
		currimage = NULL;
	}
}


bool ImageCreationHandler::CreateImage(std::string path, std::string type){
	ImageLoaderFactory temp;

	currimage = temp.getNewLoader(type);

	if (currimage == NULL) return false;

	bool success = currimage->loadFile(path);

	if (!success){
		currimage->clear();
		delete currimage;
		currimage = NULL;
		return false;
	}

	return true;
}

bool ImageCreationHandler::bindImage(const int & id, RenderModuleStubb* renderer){
	if (currimage == NULL) return false;
	
	renderer->storeTexture(id, currimage->getBits(), currimage->getWidth(), currimage->getHeight(), currimage->getData());
	currimage->clear();
	delete currimage;
	currimage = NULL;
	return true;
}

void ImageCreationHandler::unbindImage(const int & id, RenderModuleStubb* renderer){
	renderer->deleteTexture(id);
}