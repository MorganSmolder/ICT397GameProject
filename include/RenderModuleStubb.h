#pragma once

#include "Windows.h"
#define GLFW_INCLUDE_GLU 
#define GLFW_EXPOSE_NATIVE_WGL
#define GLFW_EXPOSE_NATIVE_WIN32
#include "gl/glew.h"
#include "glfw/glfw3.h"
#include "GLFW/glfw3native.h"
#include <vector>
//#include "vec3.h"
//#include "vec2.h"
#include "MessagingBus.h"
#include "Singleton.h"
#include "Identifiers.h"
#include "Maths.h"

/**
* @struct
* @brief Struct for x y coord data
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
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

/**
* @class RenderModuleStubb
* @brief Class rendering the game.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class RenderModuleStubb
{
public:
	GLFWwindow* getWindow() { return window; }
	RenderModuleStubb();

	/**
	* @brief Initalise the render function.
	*
	* @param argc 
	* @param argv
	*/
	void init(int argc, char** argv);

	/**
	* @brief Draw a quad.
	*
	* @param t1 - The top point.
	* @param br - The bottom point
	* @param y - The y coord.
	*/
	void DrawQuad(point tl, point br, float y);

	/**
	* @brief Draw a quad.
	*
	* @param t1 - The top vector.
	* @param widthx - The x width.
	* @param widthz - The z width.
	* @param height - The height.
	* @param trans - The translation matrix.
	*/
	void DrawQuad(vec3 tl, float widthx, float widthz, float height, vec3 trans);

	/**
	* @brief Store the texture.
	*
	* @param texID - The texture id.
	* @param pixelsize - The texture size.
	* @param width - The width of the texture.
	* @param height - The height of the texture.
	* @param data - The texture data.
	*/
	void storeTexture(const int & texID, unsigned pixelsize, unsigned width, unsigned height, const unsigned char* data);

	/**
	* @brief Delete the texture.
	*
	* @param texID - The texture id.
	*/
	void deleteTexture(const int & texID);

	/**
	* @brief Bind the texture to the renderer.
	*
	* @param texID - The texture id.
	*/
	void bindTexture(const int & texID);

	/**
	* @brief Bind the multi-texture.
	*
	* @param texIDcolor - The texture colour.
	* @param texIDdetail - The texture detail id.
	*/
	void bindMultiTexture(const int & texIDcolor, const int & texIDdetail);

	/**
	* @brief Render a array triangle strip.
	*
	* @param indicies - A vector of indicies.
	* @param vecticies - A vector of verticies.
	* @para trans - The transformatiom matrix.
	*/
	void renderArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, const vec3 & trans);

	/**
	* @brief Render array of triangles.
	*
	* @param indicies - A vector of indicies.
	* @param vertices - A vector of vertices.
	* @param texcoords - The texture coords.
	* @param trans - The transformation matrix.
	*/
	void renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec2> & texcoords, const vec3 & trans);

	/**
	* @brief Render the textured array triangle strip.
	*
	* @param indicies - A vector of indicies.
	* @param vertices - A vector of vertices.
	* @param texcoords - A vector of texture coords.
	*/
	void renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords);

	/**
	* @brief Render a multi-Textured array triangle strip.
	*
	* @param indicies - A vector of indicies.
	* @param vertices - A vector of vertices.
	* @param texcoords - A vector of texture coords.
	* @param trans - A transformation matrix.
	*/
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, const vec3 & trans);

	/**
	* @brief Render multi-texture array trianlge strip.
	*
	* @param indicies - A vector of indicies.
	* @param vertices - A vector of vertices.
	* @param texcoords - A vector of texture coords.
	* @param lights - A vector of lights.
	* @param trans - A transformation matrix.
	*/
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, std::vector<float> lights, const vec3 & trans);

	/**
	* @brief Render a array of triangles.
	*
	* @param indicies - A vector of indicies.
	* @param verticies - A vector of verticies.
	* @param normals - A vector of normals.
	* @param texcoords - A vector of texcoords.
	* @param trans - A transformation matrix.
	*/
	void renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec3> normals, std::vector<vec2> & texcoords, const vec3 & trans);

	/**
	* @brief Call the look at function.
	*
	* @param r1 - The first vector.
	* @param r2 - The second vector.
	* @param r3 - The third vector.
	*/
	void callLookAt(vec3 r1, vec3 r2, vec3 r3);

	/**
	* @brief Disbale the multi-texture.
	*/
	void disableMultiTexture();

	/**
	* @brief Render the facing camera.
	*/
	void RenderFacingCamera();

	/**
	* @brief Stop rendering the facing camera.
	*/
	void StopRenderFacingCamera();

	/**
	* @brief Start the rendering cycle.
	*/
	void startRenderCycle();

	/**
	* @brief End the render cycle.
	*/
	void endRenderCycle();

	/**
	* @brief Reshape the window function.
	*
	* @param window - The window.
	* @param widht - The window width.
	* @param height - The window height.
	*/
	static void reshape(GLFWwindow* window, int width, int height);

	/**
	* @brief Get the elapsed time.
	*
	* @return float - The elapsed time.
	*/
	float getTimeElapsed();

	/**
	* @brief Get the time since the last update.
	*
	* @return float - The time since the last update.
	*/
	float getTimeSinceUpdate();

	/**
	* @brief Get the window object.
	*
	* @return HWND - The window object.
	*/
	HWND getWinWindow();

	/**
	* @brief Find out if the rendering should continue or if the program has been exited.
	*
	* @param bool - If the window should continue.
	*/
	bool shouldContinue();

private:
	/// The window.
	GLFWwindow* window;
	/// The camera position.
	vec3 campos;
	/// The camera look at position.
	vec3 camlook;
	/// The identifer for the render.
	Identifiers id;
	/// If the renderer should be rendering in wireframe mode.
	bool wireframe;

	/**
	* @brief Message receiver method.
	*/
	void msgrcvr();
	/// The time since the last update.
	float timeLastUpdate;
	/// The time elapsed.
	float timeElapsed = 0.0f;
	/// If the renderer is running.
	bool running;

	/// Array of lights.
	light lights[8];

	/**
	* @brief Set the ambient light.
	*
	* @param lightno - The light number in the array.
	* @param first - The first variable for the lighting object.
	* @param second - The second variable for the lighting object.
	* @param third - The third variable for the lighting object.
	* @param fourth - The fourth variable for the lighting object.
	*/
	void setLightAmbient(int lightNo, float first, float second, float third, float fourth);

	/**
	* @brief Set the diffuse light.
	*
	* @param lightno - The light number in the array.
	* @param first - The first variable for the lighting object.
	* @param second - The second variable for the lighting object.
	* @param third - The third variable for the lighting object.
	* @param fourth - The fourth variable for the lighting object.
	*/
	void setLightdiffuse(int lightNo, float first, float second, float third, float fourth);

	/**
	* @brief Set the specular light.
	*
	* @param lightno - The light number in the array.
	* @param first - The first variable for the lighting object.
	* @param second - The second variable for the lighting object.
	* @param third - The third variable for the lighting object.
	* @param fourth - The fourth variable for the lighting object.
	*/
	void setLightspecular(int lightNo, float first, float second, float third, float fourth);

	/**
	* @brief Set the lights position.
	*
	* @param lightno - The light number in the array.
	* @param first - The first variable for the lighting object.
	* @param second - The second variable for the lighting object.
	* @param third - The third variable for the lighting object.
	* @param fourth - The fourth variable for the lighting object.
	*/
	void setLightposition(int lightNo, float first, float second, float third, float fourth);

	/**
	* @brief Configure the lighting.
	*/
	void configureLights();

	/**
	* @brief Confirm lighting changes.
	*/
	void commitLights();
};

