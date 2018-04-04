#pragma once
#include <Assimp/scene.h>
#include <Assimp/Importer.hpp>
#include <Assimp/postprocess.h>

#include "Model.h"
#include "vec2.h"


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
	void setTexCoords(aiMesh *mesh);
	void setNormals(aiMesh *mesh);
	void setIndexes(aiMesh *mesh);

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
	std::vector<vec2> texCoords;
	std::vector<vec3> Normals;
	std::vector<vec3> Index;
	const aiScene *model;
};

