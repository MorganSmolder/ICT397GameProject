#pragma once

#include "ImageLoader.h"

class TGALoader : public ImageLoader
{
public:
	TGALoader();
	~TGALoader();
	bool loadFile(std::string filename);
	const unsigned char* getData() const;
	unsigned getBits() const;
	unsigned getWidth() const;
	unsigned getHeight() const ;
	void clear();

private:
	unsigned char * data;
	unsigned width;
	unsigned height;
	unsigned bits;
};

