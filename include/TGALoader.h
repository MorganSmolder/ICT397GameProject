#pragma once

#include "ImageLoader.h"

class TGALoader : public ImageLoader
{
public:
	TGALoader();
	~TGALoader();

	/**
	* @brief Load a file.
	* 
	* @param filename(string) - The file name.
	*
	* @return bool - If the file was loaded.
	*/
	bool loadFile(std::string filename);

	/**
	* @brief Get the data.
	*
	* @return char* - The data.
	*/
	unsigned char* getData() const;

	/**
	* @brief Get the number of bits in the data.
	*
	* @return unsigned - The number of bits.
	*/
	unsigned getBits() const;

	/**
	* @brief Get the width.
	*
	* @return unsigned - The width.
	*/
	unsigned getWidth() const;
	
	/**
	* @brief Get the height.
	*
	* @return unsigned - The height.
	*/
	unsigned getHeight() const ;

	/**
	* @brief Clear the data.
	* 
	* @return NONE.
	*/
	void clear();

	/**
	* @brief Get the data size.
	*
	* @return unsigned - The data size.
	*/
	unsigned getDataSize();

private:
	unsigned char * data; /// Data
	unsigned width; /// Width of the data.
	unsigned height; /// Height of the data
	unsigned bits; /// The number of bits in the data.
	unsigned size; /// The size of the data.
};

