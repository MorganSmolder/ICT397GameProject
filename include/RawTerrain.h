#pragma once

#include "terrain.h"
#include <fstream>
#include <iostream>
#include <cmath>

/**
* @class RAWTerrain
*
* @brief Get the raw terrain data.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class RAWTerrain : public terrain
{
	public:
		RAWTerrain();
		RAWTerrain(const RAWTerrain & tocpy);
		~RAWTerrain();

		/**
		* @brief Virtual method for loading a model.
		* 
		* @param filename(string) - The file name.
		*
		* @return NONE.
		*/
		virtual bool loadModel(std::string filename);

		/**
		* @brief Virtual mothod for updating.
		*
		* @return NONE.
		*/
		virtual void update();

		/**
		* @brief Virtual method for rendering.
		*
		* @param transmat(vec3) - The transmat vector.
		*
		* @return NONE.
		*/
		virtual void render(const vec3 & transmat);

		/**
		* @brief Create the raw terrain data.
		*
		* @return RAWTerrain * - The terrain data.
		*/
		RAWTerrain * create() const;

	private:
		std::string multitexture; /// The multi-texture data.
		std::string detailmap; /// The detail map data.

		/**
		* @brief Load the data.
		*
		* @param filename(string) - The file name.
		*
		* @return bool - If the data loaded.
		*/
		bool loadData(std::string filename); 

		/**
		* @brief Parse options.
		*
		* @param file(string) - The file name.
		*
		* @return string - The data.
		*/
		std::string parseOptions(std::string file); 
	
		/**
		* @brief Create a random string.
		*
		* @param len(unsigned) - The length of the string.
		*
		* @return string - The random string.
		*/
		std::string RandomString(unsigned len); 
		std::vector<std::string> images; /// The images.
};

