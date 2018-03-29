#include "RAWTerrain.h"


RAWTerrain::RAWTerrain() :terrain()
{

}


RAWTerrain::~RAWTerrain()
{

}

void RAWTerrain::update() {

}

RAWTerrain::RAWTerrain(const RAWTerrain & tocpy) {
	dimensions = tocpy.dimensions;
	
	if (tocpy.data != NULL) {
		data = new float[tocpy.dimensions * tocpy.dimensions];

		for (unsigned i = 0; i < dimensions*dimensions; i++) {
			data[i] = tocpy.data[i];
		}
	}
	else {
		data = NULL;
	}

	plane = tocpy.plane;
	planInd = tocpy.planInd;
	texcoords = tocpy.texcoords;
	scale = tocpy.scale;
	texture = tocpy.texture;
}

RAWTerrain * RAWTerrain::create() const {
	return new RAWTerrain(*this);
}

void RAWTerrain::render() {
	if (!texture.empty()) {
		Singleton<TextureManager>::getInstance()->useTexture(texture, Singleton<RenderModuleStubb>::getInstance());
		Singleton<RenderModuleStubb>::getInstance()->renderTexturedArrayTriStrip(planInd, plane, texcoords);
		Singleton<TextureManager>::getInstance()->disableTexture(Singleton<RenderModuleStubb>::getInstance());
	}
	else {
		Singleton<RenderModuleStubb>::getInstance()->renderArrayTriStrip(planInd, plane);
	}
}

bool RAWTerrain::loadData(std::string filename){
	std::ifstream infile(filename.c_str(), std::ios::binary);
	if (!infile) return false;

	infile.seekg(0, std::ios::end);

	unsigned size = (unsigned) infile.tellg();
	infile.seekg(0, std::ios::beg);

	dimensions = (unsigned) sqrt(size);

	unsigned char* data2 = new unsigned char[size];

	if (!data2) return false;

	if (infile.read((char*)data2, size)) {

		data = new float[size];

		for(unsigned i = 0; i < size; i++) {
			data[i] = data2[i];
		}

		delete[] data2;
		data2 = NULL;

		return true;
	}
	else{
		delete[] data2;
		data2 = NULL;
		return false;
	}
}

std::string RAWTerrain::parseOptions(std::string file) {
	std::string hm;
	
	std::ifstream infile(file.c_str());
	if (!infile) return hm;

	std::string tmp;
	char linehead;

	float x, y, z;

	while (infile.peek() != EOF) {
		getline(infile, tmp);

		linehead = tmp.at(0);
		tmp = tmp.substr(tmp.find(" ") + 1);

		switch (linehead) {
		case 's':
			x = atof(tmp.substr(0, tmp.find(" ")).c_str());
			tmp = tmp.substr(tmp.find(" ") + 1);
			y = atof(tmp.substr(0, tmp.find(" ")).c_str());
			tmp = tmp.substr(tmp.find(" ") + 1);
			z = atof(tmp.c_str());
			scale = vec3(x, y, z);
			break;
		case 'f':
			hm = tmp;
			break;
		case 't':
			std::string path = tmp.substr(0, tmp.find(" "));
			tmp = tmp.substr(tmp.find(" ") + 1);
			std::string mettype = tmp;
			std::string name = RandomString(25);
			bool good = Singleton<TextureManager>::getInstance()->loadNewTexture(path, mettype, name, Singleton<RenderModuleStubb>::getInstance());
			if (good) texture = name;
			break;
		}
	}
}

bool RAWTerrain::loadModel(std::string filename){

	std::string file = parseOptions(filename);
	
	if (file.empty()) return false;

	bool good = loadData(file);
	
	if (good) {
		genPlane(dimensions);
		genPlaneIndicies(dimensions);
		genTexCoords();
		applyScaling(scale);
		delete[] data;
		data = NULL;
	}

	return good;
}

std::string RAWTerrain::RandomString(unsigned len) {
	std::string tmp;


	for (unsigned i = 0; i < len; ++i) {
		tmp.push_back((char) 97 + (rand() % static_cast<int>(122 - 97 + 1)));
	}

	return tmp;
}