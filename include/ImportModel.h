#pragma once
#include <Assimp/scene.h>
#include <Assimp/Importer.hpp>
#include <Assimp/postprocess.h>

#include "Model.h"


class ImportModel : public Model
{
public:
	ImportModel *create() const
	{
		return new ImportModel(*this);
	}

	ImportModel();
	ImportModel(const ImportModel & tocpy);
	~ImportModel();

	bool loadModel(std::string filename);

	void setVertices(aiMesh *mesh);

	std::vector<vec3> &getVerticies()
	{
		return(Vertices);
	}

	void centerOnPoint(vec3 &point);

	void update();
	void render();

	void setMinsAndMaxs();

private:
	std::vector<vec3> Vertices;
	const aiScene *model;
};

