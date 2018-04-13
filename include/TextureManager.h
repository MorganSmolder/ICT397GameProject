#pragma once
#include "ImageCreationHandler.h"
#include <map>

/**
* @class TextureManager
* @brief The texture manager.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class TextureManager
{
public:
	TextureManager();

	/**
	* @brief Load the new texture.
	*
	* @param path(string) - The path of the texture.
	* @param type(string) - The type of texture.
	* @param name(string) - The name of the texure.
	* @param renderer(RenderModuleStubb*) - The renderer object.
	*
	* @return bool - If the new texture was created.
	*/
	bool loadNewTexture(std::string path, std::string type, std::string name, RenderModuleStubb* renderer); 

	/**
	* @brief Store the texture data.
	*
	* @param name(string) - The name of the texture data.
	* @param data(unsigned char*) - The data.
	* @param bits(unsigned) - The number of bits in the data.
	* @param width(unsigned) - The width of the data.
	* @param height(unsigned) - The height of the data.
	*
	* @return bool - If the texture was stored.
	*/
	bool storeTextureFromData(std::string name, unsigned char* data, unsigned bits, unsigned width, unsigned height);

	/**
	* @brief Use the texture.
	*
	* @param name(string) - The name of the texture.
	* @param renderer(RenderModuleStubb*) - The renderer object.
	* 
	* @return bool - If the texture was used.
	*/
	bool useTexture(std::string name, RenderModuleStubb* renderer);

	/**
	* @brief Use the texture.
	*
	* @param name(string) - The name of the texture.
	* @param name2(string) - The name of the second texture.
	* @param renderer(RenderModuleStubb*) - The renderer object.
	*
	* @return bool - If the texture was used.
	*/
	bool useTexture(std::string name, std::string name2, RenderModuleStubb* renderer);

	/**
	* @brief Delete the texture.
	*
	* @param name(string) - The texture to be deleted.
	* @param renderer(RenderModuleStubb*) - The renderer object.
	* 
	* @return bool - If the texture was deleted.
	*/
	bool deleteTexture(std::string name, RenderModuleStubb* renderer);

	/**
	* @brief Disable the texture.
	* 
	* @param renderer(RenderModuleStubb*) - The renderer object.
	*
	* @return NONE.
	*/
	void disableTexture(RenderModuleStubb* renderer);

	/**
	* @brief Generate the multi-texture.
	*
	* @param heightmap(vector<vec3>) - The heightmap data.
	* @param texture(vector<string>) - The texture data.
	* @param name(string) - The name of the height map.
	*
	* @return bool - If the texture was generated.
	*/
	bool genMultiTexture(std::vector<vec3> heightmap, std::vector<std::string> textures, std::string name);

	/**
	* @brief disable the multi-texture.
	*
	* @param renderer(RenderModuleStubb*) - The renderer object.
	*
	* @return NONE.
	*/
	void DisableMultiTex(RenderModuleStubb* renderer);

private:
	std::map<std::string, int> images; /// The images
	ImageCreationHandler ImgCH; /// The creation handeler object.
	unsigned nextid; /// The next texture id.
};

