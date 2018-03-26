#pragma once
#include <string>
#include <string>
#include <fstream>

class ImageLoader
{
public:
	virtual bool loadFile(std::string filename) = 0;
	virtual const unsigned char* getData() const = 0;
	virtual unsigned getBits() const = 0;
	virtual unsigned getWidth() const = 0;
	virtual unsigned getHeight() const = 0;
	virtual void clear() = 0;
};

