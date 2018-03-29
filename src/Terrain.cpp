#include "terrain.h"

terrain::terrain() {
	data = NULL;
}

terrain::~terrain() {
	if (data != NULL) {
		delete data;
	}
	data = NULL;
}

void terrain::genPlane(unsigned size) {
	int ind = 0;

	for (unsigned i = 0; i < size; i++) {
		for (unsigned j = 0; j < size; j++) {
			plane.push_back(vec3((float) i, data[ind++], (float) j));
		}
	}
}

void terrain::genPlaneIndicies(unsigned size) {

	for (int i = 0; i < size - 1; i++) {
		if (i % 2 == 0) {
			for (int j = 0; j < size; j++) {
				planInd.push_back(j + i * size);
				planInd.push_back(j + (i + 1) * size);
			}
		}
		else {
			for (int j = size - 1; j > 0; j--) {
				planInd.push_back(j + (i + 1) * size);
				planInd.push_back(j - 1 + i * size);
			}
		}
	}
}

void terrain::genTexCoords() {
	float texLeft;
	float texBottom;
	float texTop;

	for (unsigned i = 0; i < plane.size(); i++) {
		texLeft = plane.at(i).x() / dimensions;
		texBottom = plane.at(i).z() / dimensions;
		texTop = plane.at(i).z() / dimensions;

		if (i % 2 == 0) {
			texcoords.push_back(vec2(texLeft, texBottom));
		}
		else {
			texcoords.push_back(vec2(texLeft, texTop));
		}
	}
}

void terrain::applyScaling(vec3 & scale) {
	for (unsigned i = 0; i < plane.size(); i++) {
		plane.at(i).sx(plane.at(i).x() * scale.x());
		plane.at(i).sy(plane.at(i).y() * scale.y());
		plane.at(i).sz(plane.at(i).z() * scale.z());
	}
}