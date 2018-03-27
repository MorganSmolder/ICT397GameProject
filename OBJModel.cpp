#include "OBJModel.h"



OBJModel::OBJModel(){

}

OBJModel::~OBJModel(){

}

bool OBJModel::loadModel(std::string filename) {
	std::ifstream infile(filename.c_str());
	if (!infile) return false;

	std::string line;

	std::string linehead;

	Mesh tmpmesh;

	vec3 tmpvec;

	while (infile.peek() != EOF) {
		getline(infile, line);

		cleanLine(line);

		if (!line.empty()) {
			linehead = line.substr(0, line.find(" "));
			line = line.substr(line.find(" ") + 1);

			if (linehead == "g" || linehead == "o") {
				meshes.push_back(tmpmesh);
				tmpmesh.clear();
			}
			else
			if (linehead == "v") {
				tmpmesh.verticies.push_back(parseV3(line));
			}
			else
			if (linehead == "vn") {
				tmpmesh.normals.push_back(parseV3(line));
			}
			else
			if (linehead == "vt") {
				tmpmesh.texcoords.push_back(parseV2(line));
			}
			else
			if (linehead == "f") {
				parseFaces(line, tmpmesh);
			}
			else
			if (linehead == "tex") {
				tmpmesh.texture = line;
			}
		}
	}

	meshes.push_back(tmpmesh);

	return true;
}

void OBJModel::cleanLine(std::string & line) {
	while (line.at(0) == ' ') {
		line = line.substr(1);
	}

	while (line.find("  ") != std::string::npos) {
		line = line.substr(0, line.find("  ")) + line.substr(line.find("  ") + 1);
	}

	while (line.find("	") != std::string::npos) {
		line = line.substr(0, line.find("	")) + line.substr(line.find("	") + 1);
	}

	if (line.find('#')) {
		line = line.substr(0, line.find('#'));
	}

	if (line.at(line.size() - 1) == ' ') {
		line.substr(0, line.size() - 1);
	}
}

vec3 OBJModel::parseV3(std::string & line) {
	vec3 tmp;

	tmp.sx(atof(line.substr(0, line.find(" ")).c_str()));
	line = line.substr(line.find(" ") + 1);
	tmp.sy(atof(line.substr(0, line.find(" ")).c_str()));
	line = line.substr(line.find(" ") + 1);
	tmp.sz(atof(line.c_str()));

	return tmp;
}

vec3 OBJModel::parseV2(std::string & line) {
	vec3 tmp;

	tmp.sx(atof(line.substr(0, line.find(" ")).c_str()));
	line = line.substr(line.find(" ") + 1);
	tmp.sz(atof(line.c_str()));

	return tmp;
}

void OBJModel::parseFaces(std::string & toparse, Mesh & m) {
	std::string temp;
	face tempface;

}

void OBJModel::update() {

}

void OBJModel::render() {

}