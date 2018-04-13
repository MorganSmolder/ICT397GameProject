#pragma once

#include "ImageLoaderFactory.h"
#include "RenderModuleStubb.h"

/**
* @class ImageCreationHandler
*
* @brief Controls the image creation.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class ImageCreationHandler
{
public:
	ImageCreationHandler();
	~ImageCreationHandler();

	/**
	* @brief Create a image.
	*
	* @param path(string) - The path of the image being loaded.
	* @param type(string) - The type of image being loaded.
	*
	* @return bool - If the image was created.
	*/
	bool CreateImage(std::string path, std::string type);

	/**
	* @brief Bind images to the render
	*
	* @param id(int &) - The id of the image being bound.
	* @param renderer(RenderModuleStubb *) - A pointer to the renderer object.
	*
	* @return bool - If the image was bound.
	*/
	bool bindImage(const int & id, RenderModuleStubb* renderer);

	/**
	* @brief Unbind the image from the renderer.
	*
	* @param id(int &) - The id of the image being unbound.
	* @param renderer(RenderModuelStubb *) - A pointer to the renderer object.
	*
	* @return bool - If the image was unbound.
	*/
	void unbindImage(const int & id, RenderModuleStubb* renderer);

	/**
	* @brief Creating a texture for the heightmap.
	*
	* @param heightmap(vector<vec3>) - The positions for the heightmap.
	* @param textures(vector<string>) - The textures for the heightmap.
	* @param name(string) - The name for the heightmap.
	* @param id(int &) - The id for the heightmap.
	*
	* @return bool - If the heightmap texture was created.
	*/
	bool CreateMultiTexture(std::vector<vec3> heightmap, std::vector<std::string> textures, std::string name, const int & id);
private:
	ImageLoader* currimage; /// pointer to the current image being loaded.
};

