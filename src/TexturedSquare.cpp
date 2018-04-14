#include "TexturedSquare.h"

TexturedSquare::TexturedSquare()
{
}


TexturedSquare * TexturedSquare::create() const {
	TexturedSquare * tmp = new TexturedSquare();
	tmp->br = this->br;
	tmp->tl = this->tl;
	tmp->texture = this->texture;
}

bool TexturedSquare::loadModel(std::string filename) {

}

void TexturedSquare::update() {

}

void TexturedSquare::render(const vec3 & transmat) {

}

void TexturedSquare::centerOnPoint(vec3 & point) {

}

std::vector<vec3>& TexturedSquare::getVerticies() {
	verts.clear();
	verts.push_back(vec3(tl.x(), tl.y(), -1));
	verts.push_back(vec3(br.x(), br.y(), -1));
	return verts;
}

void TexturedSquare::setScale(vec3 & toset) {
	tl *= vec2(toset.x(), toset.y());
	br *= vec2(toset.x(), toset.y());
}