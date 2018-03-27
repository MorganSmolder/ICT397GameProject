#pragma once
#include "GL\glut.h"
#include <vector>
#include "vec3.h"
#include "MessagingBus.h"
#include "Singleton.h"
#include "Identifiers.h"

struct point{
	float x, y;
	point(float x, float y){ this->x = x; this->y = y; };
};

class RenderModuleStubb
{
public:
	void init(int argc, char** argv);
	void setUpdateCallBack(void(*callback)());
	void setReshapeCallBack();
	void setKeyCallback();
	void start();
	void DrawQuad(point tl, point br);
	void storeTexture(const int & texID, unsigned pixelsize, unsigned width, unsigned height, const unsigned char* data);
	void deleteTexture(const int & texID);
	void bindTexture(const int & texID);
	void renderArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices);
	void renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec3> & texcoords);

	static void (*displayfunc)();

	static void display();
	static void reshape(GLsizei width, GLsizei height);
	static void keys(unsigned char key, int x, int y);
};

