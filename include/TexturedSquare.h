#pragma once

#include "Model.h"
#include "vec2.h"
#include "Singleton.h"
#include "TextureManager.h"

class TexturedSquare : public Model
{
public:
	TexturedSquare();
	TexturedSquare * create() const;
	bool loadModel(std::string filename);
	void update();
	void render(const vec3 & transmat);
	void centerOnPoint(vec3 & point);
	std::vector<vec3>& getVerticies();
	void setScale(vec3 & toset);
private:
	vec2 tl;
	vec2 br;
	std::vector<vec3> verts;
	std::string texture;
	std::string RandomString(unsigned len);
};

