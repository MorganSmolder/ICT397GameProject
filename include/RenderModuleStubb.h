#pragma once

#define GLFW_INCLUDE_GLU 
#include "gl/glew.h"
#include "glfw/glfw3.h"
#include <vector>
//#include "vec3.h"
//#include "vec2.h"
#include "Maths.h"
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
	GLFWwindow* getWindow() { return window; }
	RenderModuleStubb();
	void init(int argc, char** argv);
	void DrawQuad(point tl, point br, float y);
	void storeTexture(const int & texID, unsigned pixelsize, unsigned width, unsigned height, const unsigned char* data);
	void deleteTexture(const int & texID);
	void bindTexture(const int & texID);
	void bindMultiTexture(const int & texIDcolor, const int & texIDdetail);
	void renderArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, const vec3 & trans);
	void renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec2> texcoords, const vec3 & trans);
	void renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords);
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, const vec3 & trans);
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, std::vector<float> lights, const vec3 & trans);
	void callLookAt(vec3 r1, vec3 r2, vec3 r3);
	void disableMultiTexture();

	void startRenderCycle();
	void endRenderCycle();

	static void reshape(GLFWwindow* window, int width, int height);
	float getTimeElapsed();
	float getTimeSinceUpdate();

private:
	GLFWwindow* window;
	vec3 campos;
	vec3 camlook;
	float timeLastUpdate;
	float timeElapsed = 0.0f;

};

