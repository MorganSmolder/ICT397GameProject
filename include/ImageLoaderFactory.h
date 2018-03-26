#pragma once

#include "TGALoader.h"
#include "BMPLoader.h"

class ImageLoaderFactory
{
	public:
		ImageLoader* getNewLoader(std::string type);
};

