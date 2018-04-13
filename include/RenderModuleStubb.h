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

/**
* @struct point
* @brief Data type for the point.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
struct point{
	float x, y;
	point(float x, float y){ this->x = x; this->y = y; };
};

/**
* @class RenderModuleStubb
*
* @brief The render modulde stubb.
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
	* @brief The initilisation function.
	*
	* @param argc(int) - The arguement.
	* @param argv(string**) - The string arguement.
	*
	* @return NONE.
	*/
	void init(int argc, char** argv);

	/**
	* @brief Draw the quad.
	*
	* @param tl(point) - Top left data.
	* @param br(point) - Bottom right data.
	* @param y(float) - The y coord.
	*
	* @return NONE.
	*/
	void DrawQuad(point tl, point br, float y);

	/**
	* @brief Store the texture.
	*
	* @param texID(int &) - The texture id.
	* @param pixelsize(unsigned) - The pixel size.
	* @param width(unsigned) - The width.
	* @param height(unsigned) - The height.
	* @param data(unsigned char*) - The data.
	*
	* @return NONE.
	*/
	void storeTexture(const int & texID, unsigned pixelsize, unsigned width, unsigned height, const unsigned char* data);

	/**
	* @brief Delete the texture.
	*
	* @param texID(int) - The texture id.
	*
	* @return NONE.
	*/
	void deleteTexture(const int & texID);

	/**
	* @brief Bind the texture.
	*
	* @param texID(int) - The texture being bound.
	*
	* @return NONE.
	*/
	void bindTexture(const int & texID);

	/**
	* @brief Bind multi-textures.
	*
	* @param texIDcolor(int) - The texture colour id.
	* @param texIDdetail(int) - The detail map texture.
	*
	* @return NONE.
	*/
	void bindMultiTexture(const int & texIDcolor, const int & texIDdetail);

	/**
	* @brief Render tri strip array.
	*
	* @param indicies(vector<unsigned>) - The indicies.
	* @param vertices(vector<vec3>) - The verticies.
	* @param trans(vec3) - The translation.
	*
	* @return NONE.
	*/
	void renderArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, const vec3 & trans);

	/**
	* @brief Render triangle array.
	* 
	* @param indicies(vector<unsigned>) - The indicies.
	* @param vertices(vector<vec3>) - The vertices.
	* @param texcoord(vector<vec2>) - The texture coords.
	* @param trans(vec3) - The translation vector.
	*
	* @return NONE.
	*/
	void renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec2> texcoords, const vec3 & trans);

	/**
	* @brief Render the texured triangle array strip.
	*
	* @param indicies(vector<unsigned>) - The indicies
	* @param vertices(vector<vec3>) - The vertices.
	* @param texcoord(vector<vec2>) - The texture coords.
	*
	* @return NONE.
	*/
	void renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords);

	/**
	* @brief Render the multi-textured triangle array strips.
	*
	* @param indicies(vector<unsigned>) - The indicies
	* @param vertices(vector<vec3>) - The vertices.
	* @param texcoord(vector<vec2>) - The texture coords.
	* @param trans(vec3) - The translation vector.
	*
	* @return NONE.
	*/
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, const vec3 & trans);

	/**
	* @brief Render the multi-textured triangle array strips.
	*
	* @param indicies(vector<unsigned>) - The indicies
	* @param vertices(vector<vec3>) - The vertices.
	* @param texcoord(vector<vec2>) - The texture coords.
	* @param lights(vector<float>) - The lights.
	* @param trans(vec3) - The translation vector.
	*
	* @return NONE.
	*/
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, std::vector<float> lights, const vec3 & trans);

	/**
	* @brief Look at position.
	* 
	* @param r1(vec3)
	* @param r2(vec3)
	* @param r3(vec3)
	*
	* @return NONE.
	*/
	void callLookAt(vec3 r1, vec3 r2, vec3 r3);

	/**
	* @brief Disable the multi-texture.
	*
	* @return NONE.
	*/
	void disableMultiTexture();

	/**
	* @brief Start the rendering cycle.
	*
	* @return NONE.
	*/
	void startRenderCycle();

	/**
	* @brief End the rendering cycle.
	*
	* @return NONE.
	*/
	void endRenderCycle();

	/**
	* @brief A static function to reshape the window.
	* 
	* @param window(GLFWwindow*) - The window.
	* @param width(int) - The new width.
	* @param height(int) - The new height.
	* 
	* @return NONE.
	*/
	static void reshape(GLFWwindow* window, int width, int height);

	/**
	* @brief Get the time elapsed.
	*
	* @return float - The time elapsed.
	*/
	float getTimeElapsed();

	/**
	* @brief Get the time since the last updated.
	*
	* @return float - The time.
	*/
	float getTimeSinceUpdate();

private:
	GLFWwindow* window; /// The window,
	vec3 campos; /// The camera position.
	vec3 camlook; /// Where the camera is looking at,
	float timeLastUpdate; /// The last time uodate.
	float timeElapsed = 0.0f; /// The elapsed time.

};

