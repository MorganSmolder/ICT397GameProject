#pragma once

#include "Model.h"


struct vec3i {
	int x, y, z;
};

struct face {
	vec3i data[3];
};

struct Mesh {
	std::vector<vec3> verticies;
	std::vector<vec3> normals;
	std::vector<unsigned> indicies;
	std::vector<vec3> texcoords;
	std::vector<face> faces;
	std::string texture;
	void clear() { verticies.clear(); normals.clear(); indicies.clear(); texcoords.clear(); faces.clear(); texture.empty(); };
};

class OBJModel : public Model
{
public:
	OBJModel();
	~OBJModel();
	bool loadModel(std::string filename);
	void update();
	void render();
private:
	vec3 parseV3(std::string & line);
	vec3 parseV2(std::string & line);
	void parseFaces(std::string & toparse, Mesh & m);
	void cleanLine(std::string & line);
	std::vector<Mesh> meshes;

};

