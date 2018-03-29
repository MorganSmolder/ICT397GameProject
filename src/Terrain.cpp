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

void terrain::centerOnPoint(vec3 & point) {
	calcMaxMin();

	float centerx = (maxx + minx) / 2;
	float centerz = (maxz + minz) / 2;

	float difx = centerx - point.x();
	float difz = centerz - point.z();

	for (unsigned i = 0; i < plane.size(); i++) {
		plane.at(i).sx(plane.at(i).x() - difx);
		plane.at(i).sz(plane.at(i).z() - difz);
	}

	calcMaxMin();
}

std::vector<vec3>& terrain::getVerticies() {
	return plane;
}

void terrain::calcMaxMin() {

	minx = plane.at(0).x();
	minz = plane.at(0).z();
	maxx = plane.at(0).x();
	maxz = plane.at(0).z();
	maxy = plane.at(0).y();
	miny = plane.at(0).y();

	for (unsigned i = 1; i < plane.size(); i++) {
		if (minx > plane.at(i).x()) {
			minx = plane.at(i).x();
		}
		if (minz > plane.at(i).z()) {
			minz = plane.at(i).z();
		}
		if (maxx < plane.at(i).x()) {
			maxx = plane.at(i).x();
		}
		if (maxz < plane.at(i).z()) {
			maxz = plane.at(i).z();
		}
		if (miny > plane.at(i).y()) {
			miny = plane.at(i).y();
		}
		if (maxy < plane.at(i).y()) {
			maxy = plane.at(i).y();
		}
	}
}