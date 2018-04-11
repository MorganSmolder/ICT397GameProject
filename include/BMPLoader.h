#pragma once

#include "ImageLoader.h"

/**
* @class BMPLoader
* @brief Class for loading in .BMP files.
*
* @author Morgan Smolder
* @version 01
* @date 02/04/2018
*/
class BMPLoader : public ImageLoader
{
public:
	BMPLoader();
	~BMPLoader();
	/**
	* @brief Load file.
	*
	* @param filename(string) - Name of the file.
	*
	* @return bool - If the file was loaded.
	*/
	bool loadFile(std::string filename);

	/**
	* @brief Get data from file.
	*
	* @return unsigned char* - Data from the file.
	*/
	unsigned char* getData() const;

	/**
	* @brief Get bits in file.
	*
	* @return unsigned - The number of bits in the file.
	*/
	unsigned getBits() const;

	/** 
	* @brief Get width.
	*
	* @return unsigned - The width of the file.
	*/
	unsigned getWidth() const;

	/**
	* @brief Get height.
	*
	* @return unsigned - The height of the file.
	*/
	unsigned getHeight() const;

	/**
	* @brief Clear the loaded file.
	*
	* @return NONE.
	*/
	void clear(); 

	/**
	* @brief Get the size of the data.
	*
	* @return unsigned - The size of the data.
	*/
	unsigned getDataSize();
private:
	unsigned char * data; /// The data of the file.
	unsigned width; /// Width of the file.
	unsigned height; /// Height of the file.
	unsigned bits; /// Bits in the file.
	unsigned size; /// Size of the file.
};
