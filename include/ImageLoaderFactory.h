#pragma once

#include "TGALoader.h"
#include "BMPLoader.h"

/**
* @class ImageLoaderFactor
*
* @brief Creates image loader objects.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class ImageLoaderFactory
{
	public:
		/**
		* @brief Create a new image loader
		* 
		* @param type(String) - The type of image loader being created.
		*
		* @return ImageLoader* - The pointer for the image loader created.
		*/
		ImageLoader* getNewLoader(std::string type);
};

