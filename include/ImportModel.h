#pragma once
#include <Assimp/scene.h>
#include <Assimp/Importer.hpp>
#include <Assimp/postprocess.h>

#include "Model.h"
#include "vec2.h"

struct Mesh {
	std::vector<vec3> vertices;
	std::vector<int> indicies;
	std::vector<vec2> texcoords;
	std::vector<vec3> normals;
};


class ImportModel : public Model
{
public:
	ImportModel* create() const;

	ImportModel();
	ImportModel(const ImportModel & tocpy);
	~ImportModel();

	bool loadModel(std::string filename);

	void centerOnPoint(vec3 &point);

	void update();
	void render();

	std::vector<vec3>& getVerticies();

private:
	void setData(aiMesh *mesh);
	void setMinsAndMaxs();
	std::vector<Mesh> meshes;
	std::vector<vec3> Vertices;
	const aiScene *model;
};

