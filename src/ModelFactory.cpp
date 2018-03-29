#include "ModelFactory.h"

Model* ModelFactory::create(std::string path, std::string type) {
	Model* tmp;
	
	if (type == "RAWTRN") {
		tmp = new RAWTerrain;
		if (tmp == NULL) {
			return tmp;
		}
		if (tmp->loadModel(path)) {
			return tmp;
		}
		else {
			delete tmp;
			return NULL;
		}
	}

	return NULL;
}