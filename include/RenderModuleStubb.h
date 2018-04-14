#pragma once

#include "Windows.h"
#define GLFW_INCLUDE_GLU 
#include "gl/glew.h"
#include "glfw/glfw3.h"
#include <vector>
#include "vec3.h"
#include "vec2.h"
#include "MessagingBus.h"
#include "Singleton.h"
#include "Identifiers.h"

struct point{
	float x, y;
	point(float x, float y){ this->x = x; this->y = y; };
};

struct light {
	float ambientLight[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float diffuseLight[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float specularLight[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	float position[4] = { 0.0f, 0.0f, 0.0f, 0.0f };
	bool enabled = false;
};

class RenderModuleStubb
{
public:
	GLFWwindow* getWindow() { return window; }
	RenderModuleStubb();
	void init(int argc, char** argv);
	void DrawQuad(point tl, point br, float y);
	void DrawQuad(vec3 tl, float widthx, float widthz, float height, vec3 trans);
	void storeTexture(const int & texID, unsigned pixelsize, unsigned width, unsigned height, const unsigned char* data);
	void deleteTexture(const int & texID);
	void bindTexture(const int & texID);
	void bindMultiTexture(const int & texIDcolor, const int & texIDdetail);
	void renderArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, const vec3 & trans);
	void renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec2> & texcoords, const vec3 & trans);
	void renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords);
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, const vec3 & trans);
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, std::vector<float> lights, const vec3 & trans);
	void renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec3> normals, std::vector<vec2> & texcoords, const vec3 & trans);
	void callLookAt(vec3 r1, vec3 r2, vec3 r3);
	void disableMultiTexture();

	void RenderFacingCamera();
	void StopRenderFacingCamera();

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
	light lights[8]; 
	void setLightAmbient(int lightNo, float first, float second, float third, float fourth);
	void setLightdiffuse(int lightNo, float first, float second, float third, float fourth);
	void setLightspecular(int lightNo, float first, float second, float third, float fourth);
	void setLightposition(int lightNo, float first, float second, float third, float fourth);
	void configureLights();
	void commitLights();
};

