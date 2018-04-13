#pragma once
#include <string>
#include <string>
#include <fstream>

/**
* @class ImageLoader
*
* @brief Loads the images.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class ImageLoader
{
public:
	/** 
	* @brief Virtual function to load the file.
	*
	* @param filename(string) - The name of the file being loaded.
	* 
	* @return bool - If the file was loaded.
	*/
	virtual bool loadFile(std::string filename) = 0;

	/**
	* @brief Virtual function to get the data from the file.
	*
	* @return char* - The data from the file.
	*/
	virtual unsigned char* getData() const = 0;

	/**
	* @brief Virtual function to get the number of bits in the file.
	*
	* @return unsigned - The number of bits in the file.
	*/
	virtual unsigned getBits() const = 0;

	/**
	* @brief Virtual function to get the width of the file.
	*
	* @return unsigned - The width of the file.
	*/
	virtual unsigned getWidth() const = 0;

	/**
	* @brief Virtual function to get the height of the file.
	*
	* @return unsigned - The height of the file.
	*/
	virtual unsigned getHeight() const = 0;

	/**
	* @brief Virtual function to clear the saved data.
	*
	* @return unsigned - NONE.
	*/
	virtual void clear() = 0;

	/**
	* @brief Virtual function to get the size of the data.
	*
	* @return unsigned - The size of the data.
	*/
	virtual unsigned getDataSize() = 0;
};

