#pragma once
#include "GL\glut.h"

struct point{
	float x, y;
	point(float x, float y){ this->x = x; this->y = y; };
};

class RenderModuleStubb
{
public:
	void DrawQuad(point tl, point br);
	void storeTexture(const int & texID, unsigned pixelsize, unsigned width, unsigned height, const unsigned char* data);
	void deleteTexture(const int & texID);
	void bindTexture(const int & texID);
};

