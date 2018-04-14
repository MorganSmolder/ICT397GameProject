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
<<<<<<< HEAD
	void DrawQuad(point tl, point br, float y);
	void DrawQuad(vec3 tl, float widthx, float widthz, float height, vec3 trans);
=======

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
>>>>>>> origin/particles
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
<<<<<<< HEAD
	void renderArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, const vec3 & trans);
	void renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec2> & texcoords, const vec3 & trans);
	void renderTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords);
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, const vec3 & trans);
	void renderMultiTexturedArrayTriStrip(std::vector<unsigned> & indicies, std::vector<vec3> & vertices, std::vector<vec2> & texcoords, std::vector<float> lights, const vec3 & trans);
	void renderArrayTri(std::vector<unsigned>& indicies, std::vector<vec3>& vertices, std::vector<vec3> normals, std::vector<vec2> & texcoords, const vec3 & trans);
=======

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
>>>>>>> origin/particles
	void callLookAt(vec3 r1, vec3 r2, vec3 r3);

	/**
	* @brief Disbale the multi-texture.
	*/
	void disableMultiTexture();

<<<<<<< HEAD
	void RenderFacingCamera();
	void StopRenderFacingCamera();

=======
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
>>>>>>> origin/particles
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
<<<<<<< HEAD
	float getTimeElapsed();
=======

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
>>>>>>> origin/particles
	float getTimeSinceUpdate();

private:
	/// The window.
	GLFWwindow* window;
	/// The camera position.
	vec3 campos;
	/// The camera look at position.
	vec3 camlook;
<<<<<<< HEAD
	Identifiers id;
	float timeLastUpdate;
	float timeElapsed = 0.0f;
	bool wireframe;

	void msgrcvr();
=======
	/// The time since the last update.
	float timeLastUpdate;
	/// The time elapsed.
	float timeElapsed = 0.0f;

>>>>>>> origin/particles
};

